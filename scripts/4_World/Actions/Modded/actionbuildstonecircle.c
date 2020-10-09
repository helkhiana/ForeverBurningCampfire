modded class ActionBuildStoneCircle: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
			
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.IsBaseFireplace() && fireplace_target.CanBuildStoneCircle() )
		{
			return true;
		}
		
		return super.ActionCondition(player, target, item);
	}
		
	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object target_object = action_data.m_Target.GetObject();
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.CanBuildStoneCircle() )
		{
			fireplace_target.SetStoneCircleState( true );
			
			// extend lifetime
			fireplace_target.SetLifetimeMax(7888000);

			//add specialty to soft skills
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
};