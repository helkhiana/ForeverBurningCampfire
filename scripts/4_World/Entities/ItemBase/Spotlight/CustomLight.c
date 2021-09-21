class FBF_CustomAreaLight_Base : House
{
    FBF_AreaPointLight m_Light;
	vector m_LocalPos;
	
	void FBF_CustomAreaLight_Base()
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

class FBF_CustomAreaLight_1 : FBF_CustomAreaLight_Base 
{
	override void SetLightColours()
	{
		m_Light.SetAmbientColor(1.0, 0, 0);
        m_Light.SetDiffuseColor(1.0, 0, 0);
	}
};
class FBF_CustomAreaLight_2 : FBF_CustomAreaLight_1 
{
	override void SetLightColours()
	{
		m_Light.SetAmbientColor(0, 1.0, 0);
        m_Light.SetDiffuseColor(0, 1.0, 0);
	}
};

class FBF_CustomAreaLight_3 : FBF_CustomAreaLight_1 
{
	override void SetLightColours()
	{
		m_Light.SetAmbientColor(0, 0, 1.0);
        m_Light.SetDiffuseColor(0, 0, 1.0);
	}
};

class FBF_CustomAreaLight_4 : FBF_CustomAreaLight_1 
{
	override void SetLightColours()
	{
		m_Light.SetAmbientColor(0.8, 0, 0.2);
        m_Light.SetDiffuseColor(0.8, 0, 0.2);
	}
};

class FBF_CustomAreaLight_5 : FBF_CustomAreaLight_1 
{
	override void SetLightColours()
	{
		m_Light.SetAmbientColor(1.0, 1.0, 1.0);
        m_Light.SetDiffuseColor(1.0, 1.0, 1.0);
	}
};