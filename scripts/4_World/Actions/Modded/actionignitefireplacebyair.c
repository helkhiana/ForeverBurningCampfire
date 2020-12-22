modded class ActionIgniteFireplaceByAir: ActionContinuousBase
{			
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		FBF_FireplaceBase fbf_fireplace = FBF_FireplaceBase.Cast( target_object );
		
		if (fbf_fireplace)
		{
			return false;
		}
		
		return super.ActionCondition (player, target, item);
	}
};