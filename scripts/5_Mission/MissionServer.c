modded class MissionServer
{
    private ref FBFConfig m_FBFConfig;

    void MissionServer()
    {
        GetRPCManager().AddRPC("FBF_Config", "GetServerFBFConfig", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();
        
        Print("[FBF_Config] Server Cfg loading...");
       
        m_FBFConfig = new FBFConfig;
        g_Game.SetFBFConfig(m_FBFConfig);
    }

    void GetServerFBFConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null)
        {
            Print("[FBF_Config] MissionServer --> Sending instance of cfg to client: " + sender.GetName());
            GetRPCManager().SendRPC("FBF_Config", "ClientStoreFBFConfig", new Param1<ref FBFConfig>( m_FBFConfig ), true, sender);
        }
    }
};