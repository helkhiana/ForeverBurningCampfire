modded class ActionPlaceOvenIndoor: ActionSingleUseBase
{	
	override void OnExecuteServer( ActionData action_data )
	{
		FBF_FireplaceBase fbf_fireplace = FBF_FireplaceBase.Cast( action_data.m_MainItem );
		if(fbf_fireplace)
		{
			FireplaceToIndoorOvenLambda lambdaFBF = new FireplaceToIndoorOvenLambda( fbf_fireplace, "FBF_OvenIndoor", action_data.m_Player, action_data.m_Player.GetLastFirePoint(), action_data.m_Target.GetObject() );
			lambdaFBF.SetTransferParams( true, true, true );
			action_data.m_Player.ServerReplaceItemInHandsWithNewElsewhere( lambdaFBF );
		}
		else
		{
			super.OnExecuteServer(action_data);
		}		
	}
};