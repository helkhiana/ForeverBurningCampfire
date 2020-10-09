modded class ActionDismantleOven: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
		
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.IsBaseFireplace() && fireplace_target.CanDismantleOven() )
		{
			return true;
		}

		return super.ActionCondition(player, target, item);
	}
		
	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object target_object = action_data.m_Target.GetObject();
		FBF_FireplaceBase fireplace_target = FBF_FireplaceBase.Cast( target_object );
		
		if (fireplace_target && fireplace_target.CanDismantleOven() )
		{
			ItemBase attached_item = ItemBase.Cast( fireplace_target.GetAttachmentByType( fireplace_target.ATTACHMENT_STONES ) );
			
			// for backward compatibility - for the cases built before slot locking was commented out for the stone att slot
			InventoryLocation inventory_location = new InventoryLocation;
			attached_item.GetInventory().GetCurrentInventoryLocation( inventory_location );			
			fireplace_target.GetInventory().SetSlotLock( inventory_location.GetSlot(), false );

			//set oven state
			fireplace_target.SetOvenState( false );
			
			fireplace_target.SetLifetimeMax( 7888000 );
			
			//add specialty to soft skills
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
}