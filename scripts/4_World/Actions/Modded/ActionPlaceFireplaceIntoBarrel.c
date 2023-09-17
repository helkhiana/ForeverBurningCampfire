modded class ActionPlaceFireplaceIntoBarrel: ActionSingleUseBase
{	
	override void OnExecuteServer( ActionData action_data )
	{	
		FBF_Fireplace fbf_fireplace = FBF_Fireplace.Cast( action_data.m_MainItem );
		if(fbf_fireplace)
		{
			BarrelHoles_ColorBase fireplace_barrel = BarrelHoles_ColorBase.Cast( action_data.m_Target.GetObject() );
			
			auto lambda = new MoveEquipToExistingItemAndDestroyOldRootLambda(fbf_fireplace, "", action_data.m_Player, fireplace_barrel);
			action_data.m_Player.ServerReplaceItemInHandsWithNewElsewhere(lambda);
		}
		else
		{
			super.OnExecuteServer(action_data);
		}	
	}
}
