class FBF_CustomAreaLight_Base : House
{
    FBF_AreaPointLight m_Light;
	vector m_LocalPos;
	FBF_LightColoured_Config config;
	
	void FBF_CustomAreaLight_Base()
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
		config = g_Game.GetFBFConfig().Get_CustomLight1_Config();
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
		if(config)
		{
			m_Light.SetAmbientColor(config.DiffuseColorRed, config.DiffuseColorGreen, config.DiffuseColorBlue);
			m_Light.SetDiffuseColor(config.DiffuseColorRed, config.DiffuseColorGreen, config.DiffuseColorBlue);
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

class FBF_CustomAreaLight_1 : FBF_CustomAreaLight_Base 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CustomLight1_Config();
	}
};
class FBF_CustomAreaLight_2 : FBF_CustomAreaLight_1 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CustomLight2_Config();
	}
};

class FBF_CustomAreaLight_3 : FBF_CustomAreaLight_1 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CustomLight3_Config();
	}
};

class FBF_CustomAreaLight_4 : FBF_CustomAreaLight_1 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CustomLight4_Config();
	}
};

class FBF_CustomAreaLight_5 : FBF_CustomAreaLight_1 
{
	override void GetConfig()
	{
		config = g_Game.GetFBFConfig().Get_CustomLight5_Config();
	}
};