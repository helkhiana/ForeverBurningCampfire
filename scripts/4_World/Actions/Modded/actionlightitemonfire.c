modded class ActionLightItemOnFire: ActionContinuousBase
{	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		ItemBase target_item = ItemBase.Cast( target.GetObject() );
		
		if ( target_item && item )
		{
			// when igniting item on the ground with igniter in hands
			if ( !target_item.IsIgnited()  &&  !IsItemInCargoOfSomething(target_item)  &&  item.CanIgniteItem( target_item )  &&  target_item.CanBeIgnitedBy( item ) && target_item.IsKindOf( "FBF_FireplaceIndoor" ) )
				return true;
		}
		
		return super.ActionCondition(player, target, item);
	}
}