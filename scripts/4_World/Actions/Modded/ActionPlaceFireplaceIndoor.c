modded class ActionPlaceFireplaceIndoor: ActionSingleUseBase
{
	override void OnExecuteServer( ActionData action_data )
	{	
		FBF_FireplaceBase fbf_fireplace = FBF_FireplaceBase.Cast( action_data.m_MainItem );
		if(fbf_fireplace)
		{
			FireplaceToIndoorsLambda lambda = new FireplaceToIndoorsLambda( fbf_fireplace, "FBF_FireplaceIndoor", action_data.m_Player, action_data.m_Player.GetLastFirePoint(), action_data.m_Target.GetObject() );
			lambda.SetTransferParams( true, true, true );
			action_data.m_Player.ServerReplaceItemInHandsWithNewElsewhere( lambda );
		}
		else
		{
			super.OnExecuteServer(action_data);
		}		
	}
};