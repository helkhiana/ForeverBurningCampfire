modded class MissionGameplay
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("FBF_Config", "ClientStoreFBFConfig", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("FBF_Config", "GetServerFBFConfig", null, true, null);
	}

	void ClientStoreFBFConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref FBFConfig> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.SetFBFConfig( data.param1 );
			Print("[FBF_Config] MissionGameplay --> Got instance of cfg: " + data.param1);
		}
    }
};