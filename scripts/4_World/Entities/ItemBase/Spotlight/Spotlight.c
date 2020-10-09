class FBF_SpotlightLight extends SpotLightBase
{
	void FBF_SpotlightLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(60);
		SetBrightnessTo(20.0);
		SetCastShadow(false);
		SetSpotLightAngle(140);
		SetFadeOutTime(0.3);
		FadeIn(0.2);
		SetAmbientColor(0.8, 0.9, 1.0);
		SetDiffuseColor(0.8, 0.9, 1.0);
	}
};

class FBF_Spotlight_Base : House
{
    FBF_SpotlightLight m_Light;
	vector m_LocalPos;
	FBF_LightBasic_Config config;
	
	void FBF_Spotlight_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
            m_LocalPos = Vector(0, 1.50668, 0);
			m_Light = FBF_SpotlightLight.Cast( ScriptedLightBase.CreateLight( FBF_SpotlightLight, "0 0 0") );
			m_Light.AttachOnObject(this, m_LocalPos, "180 0 0");
			SetLightCustomSettings();
			if (!config)
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightCustomSettings, 500, false );
		}        
	}    
	
	void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_SpotlightLight_Config();
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

	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if (m_Light)
				m_Light.Destroy();
		}
	}
};

class FBF_Spotlight : FBF_Spotlight_Base {};