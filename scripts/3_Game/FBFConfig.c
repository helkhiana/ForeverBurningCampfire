class FBFConfig
{	
	static const string MODCONFIG_ROOT_FOLDER = "$profile:FBF_Config/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "FBFConfig.json";

	private ref FBF_LightBasic_Config m_CampfireLight;
	private ref FBF_LightBasic_Config m_FireplaceLight;
	private ref FBF_LightBasic_Config m_TorchLight;
	private ref FBF_LightBasic_Config m_SpotlightLight;
	private ref FBF_LightBasic_Config m_AreaLight_White;
	private ref FBF_LightBasic_Config m_AreaLight_Warm;

    
	private ref FBF_LightColoured_Config m_CustomLight1;
	private ref FBF_LightColoured_Config m_CustomLight2;
	private ref FBF_LightColoured_Config m_CustomLight3;
	private ref FBF_LightColoured_Config m_CustomLight4;
	private ref FBF_LightColoured_Config m_CustomLight5;

	void FBFConfig()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            Print("[FBF_Config] '" + MODCONFIG_ROOT_FOLDER + "' does NOT exist, creating directory!");
            MakeDirectory(MODCONFIG_ROOT_FOLDER);
        }

        if (!FileExist(CONFIG_PATH))
        {
            Print("[FBF_Config] '" + CONFIG_PATH + "' does NOT exist, creating default config!");
            Default();
            return; 
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {
            Print("[FBF_Config] '" + CONFIG_PATH + "' found, loading existing config!");
            JsonFileLoader<FBFConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<FBFConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
        m_CampfireLight = new FBF_LightBasic_Config;
        m_CampfireLight.Radius = 25;
        m_CampfireLight.WithShadows = false;
        m_CampfireLight.Brightness = 4.75;
        m_CampfireLight.VisibleDuringDaylight = false;

        m_FireplaceLight = new FBF_LightBasic_Config;
        m_FireplaceLight.Radius = 25;
        m_FireplaceLight.WithShadows = false;
        m_FireplaceLight.Brightness = 4.75;
        m_FireplaceLight.VisibleDuringDaylight = false;

        m_TorchLight = new FBF_LightBasic_Config;
        m_TorchLight.Radius = 30;
        m_TorchLight.WithShadows = false;
        m_TorchLight.Brightness = 5.0;
        m_TorchLight.VisibleDuringDaylight = false;

        m_SpotlightLight = new FBF_LightBasic_Config;
        m_SpotlightLight.Radius = 60;
        m_SpotlightLight.WithShadows = false;
        m_SpotlightLight.Brightness = 20.0;
        m_SpotlightLight.VisibleDuringDaylight = false;

        m_AreaLight_White = new FBF_LightBasic_Config;
        m_AreaLight_White.Radius = 100;
        m_AreaLight_White.WithShadows = false;
        m_AreaLight_White.Brightness = 10.0;
        m_AreaLight_White.VisibleDuringDaylight = false;

        m_AreaLight_Warm = new FBF_LightBasic_Config;
        m_AreaLight_Warm.Radius = 100;
        m_AreaLight_Warm.WithShadows = false;
        m_AreaLight_Warm.Brightness = 10.0;
        m_AreaLight_Warm.VisibleDuringDaylight = false;

        DefaultCustomLightColours();		
		Save();
	}

    protected void DefaultCustomLightColours()
    {
        m_CustomLight1 = new FBF_LightColoured_Config;
        m_CustomLight1.Radius = 100;
        m_CustomLight1.WithShadows = false;
        m_CustomLight1.Brightness = 10.0;
        m_CustomLight1.VisibleDuringDaylight = false;
        m_CustomLight1.DiffuseColorRed = 1.0;
        m_CustomLight1.DiffuseColorGreen = 0;
        m_CustomLight1.DiffuseColorBlue = 0;

        m_CustomLight2 = new FBF_LightColoured_Config;
        m_CustomLight2.Radius = 100;
        m_CustomLight2.WithShadows = false;
        m_CustomLight2.Brightness = 10.0;
        m_CustomLight2.VisibleDuringDaylight = false;
        m_CustomLight2.DiffuseColorRed = 0;
        m_CustomLight2.DiffuseColorGreen = 1.0;
        m_CustomLight2.DiffuseColorBlue = 0;

        
        m_CustomLight3 = new FBF_LightColoured_Config;
        m_CustomLight3.Radius = 100;
        m_CustomLight3.WithShadows = false;
        m_CustomLight3.Brightness = 10.0;
        m_CustomLight3.VisibleDuringDaylight = false;
        m_CustomLight3.DiffuseColorRed = 0;
        m_CustomLight3.DiffuseColorGreen = 0;
        m_CustomLight3.DiffuseColorBlue = 1.0;

        m_CustomLight4 = new FBF_LightColoured_Config;
        m_CustomLight4.Radius = 100;
        m_CustomLight4.WithShadows = false;
        m_CustomLight4.Brightness = 10.0;
        m_CustomLight4.VisibleDuringDaylight = false;
        m_CustomLight4.DiffuseColorRed = 0.8;
        m_CustomLight4.DiffuseColorGreen = 0;
        m_CustomLight4.DiffuseColorBlue = 0.2;

        m_CustomLight5 = new FBF_LightColoured_Config;
        m_CustomLight5.Radius = 100;
        m_CustomLight5.WithShadows = false;
        m_CustomLight5.Brightness = 10.0;
        m_CustomLight5.VisibleDuringDaylight = false;
        m_CustomLight5.DiffuseColorRed = 1.0;
        m_CustomLight5.DiffuseColorGreen = 1.0;
        m_CustomLight5.DiffuseColorBlue = 1.0;
    }

	FBF_LightBasic_Config Get_CampfireLight_Config()
	{
		return m_CampfireLight;
	}

	FBF_LightBasic_Config Get_FireplaceLight_Config()
	{
		return m_FireplaceLight;
	}

	FBF_LightBasic_Config Get_TorchLight_Config()
	{
		return m_TorchLight;
	}

	FBF_LightBasic_Config Get_SpotlightLight_Config()
	{
		return m_SpotlightLight;
	}

	FBF_LightBasic_Config Get_AreaLight_White_Config()
	{
		return m_AreaLight_White;
	}

	FBF_LightBasic_Config Get_AreaLight_Warm_Config()
	{
		return m_AreaLight_Warm;
	}

    
	FBF_LightColoured_Config Get_CustomLight1_Config()
	{
		return m_CustomLight1;
	}
	FBF_LightColoured_Config Get_CustomLight2_Config()
	{
		return m_CustomLight2;
	}
	FBF_LightColoured_Config Get_CustomLight3_Config()
	{
		return m_CustomLight3;
	}
	FBF_LightColoured_Config Get_CustomLight4_Config()
	{
		return m_CustomLight4;
	}
	FBF_LightColoured_Config Get_CustomLight5_Config()
	{
		return m_CustomLight5;
	}
};