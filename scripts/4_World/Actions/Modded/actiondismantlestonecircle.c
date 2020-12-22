modded class ActionDismantleStoneCircle: ActionContinuousBase
{	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
		
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.IsBaseFireplace() && fireplace_target.CanDismantleStoneCircle() )
		{
			return true;
		}
		else if(fireplace_target)
		{
			return false;
		}

		return super.ActionCondition(player, target, item);
	}
		
	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object target_object = action_data.m_Target.GetObject();
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.CanDismantleStoneCircle() )
		{
			ItemBase attached_item = ItemBase.Cast( fireplace_target.GetAttachmentByType( fireplace_target.ATTACHMENT_STONES ) );

			//set oven state
			fireplace_target.SetStoneCircleState( false );
			
			// extend lifetime (but back to default of CE)
			fireplace_target.SetLifetimeMax( 10800 );
			
			//add specialty to soft skills
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
}