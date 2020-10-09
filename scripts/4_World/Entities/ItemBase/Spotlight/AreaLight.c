class FBF_AreaPointLight extends PointLightBase
{
	void FBF_AreaPointLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(100);
		SetCastShadow(false);
		SetBrightnessTo(10.0);
	}
};


class FBF_AreaLight_Base : House
{
    FBF_AreaPointLight m_Light;
	vector m_LocalPos;
	FBF_LightBasic_Config config;
	
	void FBF_AreaLight_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
            m_LocalPos = Vector(0, 1.5, 0);
			m_Light = FBF_AreaPointLight.Cast( ScriptedLightBase.CreateLight( FBF_AreaPointLight, "0 0 0") );
			m_Light.AttachOnObject(this, m_LocalPos, "180 0 0");
			SetLightCustomSettings();
			SetLightColours();
			if (!config)
			{
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightCustomSettings, 500, false );
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightColours, 500, false );
			}
		}        
	}

	void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_AreaLight_White_Config();
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

	void SetLightColours()
	{
		m_Light.SetAmbientColor(0.8, 0.9, 1.0);
        m_Light.SetDiffuseColor(0.8, 0.9, 1.0);
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
class FBF_AreaLight_White : FBF_AreaLight_Base {};
class FBF_AreaLight_Warm : FBF_AreaLight_Base 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_AreaLight_Warm_Config();
	}

    override void SetLightColours()
    {
        m_Light.SetAmbientColor(1.0, 0.45, 0.25);
        m_Light.SetDiffuseColor(1.0, 0.45, 0.25);
    }
};


class FBF_DynamicAreaLight_Base : House
{
    FBF_AreaPointLight m_Light;
	vector m_LocalPos;
	FBF_LightBasic_Config config;
	float r_light = 0;
	float g_light = 0;
	float b_light = 0;
	
	void FBF_DynamicAreaLight_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
            m_LocalPos = Vector(0, 1.5, 0);
			m_Light = FBF_AreaPointLight.Cast( ScriptedLightBase.CreateLight( FBF_AreaPointLight, "0 0 0") );
			m_Light.AttachOnObject(this, m_LocalPos, "180 0 0");
			SetLightCustomSettings();
			SetLightColours();
			if (!config)
			{
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightCustomSettings, 500, false );
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetLightColours, 2000, true );
			}
		}        
	}

    void SetLightCustomSettings()
    {	
        if(config)
		{
			m_Light.SetRadiusTo(100);
			m_Light.SetCastShadow(false);
			m_Light.SetBrightnessTo(10.0);
			m_Light.SetVisibleDuringDaylight(false);			
		}		
    }

	void SetLightColours()
	{
		if(r_light > 0.9)
			r_light = 0.1;
		else
			r_light = r_light + 0.1;
		if(g_light > 0.9)
			g_light = 0.1;
		else
			g_light = g_light + 0.1;
		if(b_light > 0.9)
			b_light = 0.1;
		else
			b_light = r_light + 0.1;
		
		m_Light.SetAmbientColor(r_light, g_light, b_light);
        m_Light.SetDiffuseColor(r_light, g_light, b_light);
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