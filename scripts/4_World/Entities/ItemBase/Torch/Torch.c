class FBF_TorchLight extends PointLightBase
{	
	void FBF_TorchLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(30);
		SetBrightnessTo(5.0);
		SetCastShadow(false);
		SetFadeOutTime(1);
		SetDiffuseColor(1.0, 0.45, 0.25);
		SetAmbientColor(1.0, 0.45, 0.25);
		SetFlareVisible(false);
		SetFlickerAmplitude(0.55);
		SetFlickerSpeed(0.75);
		SetDancingShadowsMovementSpeed(0.1);
		SetDancingShadowsAmplitude(0.03);
	}
};

class FBF_Torch_Base : House
{
    FBF_TorchLight m_Light;
	Particle m_FireParticle;
	vector m_ParticleLocalPos;
	
	void FBF_Torch_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
            m_ParticleLocalPos = GetParticleLocalPos();
			m_Light = FBF_TorchLight.Cast( ScriptedLightBase.CreateLight( FBF_TorchLight, "0 0 0" ) );
			m_Light.AttachOnObject(this, m_ParticleLocalPos + Vector (0,0.2,0));
            m_FireParticle = Particle.PlayOnObject(ParticleList.TORCH_T1, this, m_ParticleLocalPos, Vector(0,0,0), true);            			
		}
	}
    
    vector GetParticleLocalPos()
    {
        return Vector(0, 0.50, 0);
    }

	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if (m_Light)
				m_Light.Destroy();            
            if (m_FireParticle)
			    m_FireParticle.Stop();
		}
	}
};

class FBF_Torch : FBF_Torch_Base{};
class FBF_LongTorch : FBF_Torch_Base
{
    override vector GetParticleLocalPos()
    {
        return Vector(0, 0.83, 0);
    }
};