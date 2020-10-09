class FBF_CampfireLight extends PointLightBase
{	
	void FBF_CampfireLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(25);
		SetBrightnessTo(4.75);
		SetCastShadow(false);
		SetFadeOutTime(5);
		SetDiffuseColor(1.0, 0.5, 0.3);
		SetAmbientColor(1.0, 0.5, 0.3);
		SetFlareVisible(false);
		SetFlickerAmplitude(0);
		SetFlickerSpeed(0);
		SetDancingShadowsMovementSpeed(0);
		SetDancingShadowsAmplitude(0);
	}
};

class FBF_Campfire_Base : House
{
    FBF_CampfireLight m_Light;
	Particle m_FireParticle;
	Particle m_SmokeParticle;
    protected ref Timer m_HeatingTimer;
	protected EffectSound m_SoundFireLoop;
	FBF_LightBasic_Config config;
	const int 	TIMER_HEATING_UPDATE_INTERVAL 		= 5;
	const float PARAM_HEAT_RADIUS 					= 3.0;
	const float PARAM_HEAT_THROUGH_AIR_COEF			= 0.08;
	const float PARAM_TEMPERATURE			        = 500;
	
	void FBF_Campfire_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_Light = FBF_CampfireLight.Cast( ScriptedLightBase.CreateLight( FBF_CampfireLight, "0 0 0" ) );
			m_Light.AttachOnMemoryPoint(this, "light");
            m_FireParticle = Particle.PlayOnObject(ParticleList.CAMP_NORMAL_FIRE, this, Vector( 0, 0.05, 0 ), Vector(0,0,0), true);            
            m_SmokeParticle = Particle.PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, Vector( 0, 0.05, 0 ), Vector(0,0,0), true);
			SetLightCustomSettings();
			if (!config)
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightCustomSettings, 500, false );
		}
        if(GetGame().IsMultiplayer() || GetGame().IsServer())
        {
            StartHeating();
        }
	}
	
	void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CampfireLight_Config();
	}

    void SetLightCustomSettings()
    {	
		GetConfig();
        if(config)
		{
			m_Light.SetRadiusTo(config.Radius);
			m_Light.SetCastShadow(config.WithShadows);
			m_Light.SetBrightnessTo(config.Brightness);
			m_Light.SetVisibleDuringDaylight(config.VisibleDuringDaylight);			
		}		
    }

	override void EEInit(){
		super.EEInit();
        
		if ( GetGame().IsServer() || GetGame().IsMultiplayer() )
        {
            PlaySoundSetLoop( m_SoundFireLoop, "HeavyFire_SoundSet", 1.0, 2.0 );
            ItemBase item_base = ItemBase.Cast(this.GetInventory().CreateAttachment("FBF_Pot"));            
            item_base.SetAnimationPhase( "handleRotate", 0 );
        }
	}

	override bool DisableVicinityIcon()
	{
		return true;
	}

    override bool CanReleaseAttachment( EntityAI attachment )
	{
        return false;
    }

    override bool IsInventoryVisible(){
        return false;
    }

	override void EEDelete(EntityAI parent)
	{
        if (m_Light)
            m_Light.Destroy();            
        if (m_FireParticle)
            m_FireParticle.Stop();
        if (m_SmokeParticle)
            m_SmokeParticle.Stop();
        if ( m_SoundFireLoop )
            m_SoundFireLoop.SoundStop();            
        if ( m_HeatingTimer )
            m_HeatingTimer.Stop();
	}

	protected void StartHeating()
	{	
        if(m_HeatingTimer && m_HeatingTimer.IsRunning())
        { 
            m_HeatingTimer.Stop();
            m_HeatingTimer = NULL;
        }
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( TIMER_HEATING_UPDATE_INTERVAL, this, "TransferHeatToNearPlayers", NULL, true );	
	}

	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), PARAM_HEAT_RADIUS, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );				
				
				float temperature = PARAM_TEMPERATURE * ( PARAM_HEAT_THROUGH_AIR_COEF / distance );
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (no in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );
					
					wetness = wetness * ( PARAM_HEAT_THROUGH_AIR_COEF / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	}
};

class FBF_Static_Campfire : FBF_Campfire_Base{};