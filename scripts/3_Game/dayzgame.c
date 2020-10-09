modded class DayZGame
{
    private ref FBFConfig m_FBFConfig;

    ref FBFConfig GetFBFConfig()
    {
        if (!m_FBFConfig)
        {
            SetFBFConfig(new FBFConfig);
        }
        
	    return m_FBFConfig;
    }

    void SetFBFConfig(FBFConfig config)
	{
		m_FBFConfig = config;
	}
};