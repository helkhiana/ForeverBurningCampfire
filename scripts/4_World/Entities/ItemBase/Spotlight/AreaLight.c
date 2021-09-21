class FBF_AreaPointLight extends PointLightBase
{
	void FBF_AreaPointLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(100);
		SetBrightnessTo(10);
		SetCastShadow(false);
		SetBrightnessTo(10.0);
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


class FBF_AreaLight_Base : House
{
    FBF_AreaPointLight m_Light;
	vector m_LocalPos;
	
	void FBF_AreaLight_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
            m_LocalPos = Vector(0, 1.5, 0);
			m_Light = FBF_AreaPointLight.Cast( ScriptedLightBase.CreateLight( FBF_AreaPointLight, "0 0 0") );
			m_Light.AttachOnObject(this, m_LocalPos, "180 0 0");
			SetLightColours();
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
    override void SetLightColours()
    {
        m_Light.SetAmbientColor(1.0, 0.45, 0.25);
        m_Light.SetDiffuseColor(1.0, 0.45, 0.25);
    }
};