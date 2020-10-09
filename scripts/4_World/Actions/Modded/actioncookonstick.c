modded class ActionCookOnStick: ActionContinuousBase
{
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		FireplaceBase fireplace_target = FireplaceBase.Cast( target.GetObject() );
		Object targetObject = target.GetObject();
		Edible_Base item_on_stick = Edible_Base.Cast( item.GetAttachmentByType( Edible_Base ) );
		if ( fireplace_target && item_on_stick && item_on_stick.CanBeCookedOnStick() )
		{
			BarrelHoles_ColorBase barrel = BarrelHoles_ColorBase.Cast( fireplace_target );
			//barrel with holes
			if ( barrel )
			{
				if ( barrel.IsOpen() && fireplace_target.CanCookOnStick() )
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			//fireplace
			if ( fireplace_target.IsBaseFireplace() )
			{
				Fireplace fireplace = Fireplace.Cast( fireplace_target );
				if ( !fireplace.IsOven() && fireplace_target.CanCookOnStick() ) 
				{
					return true;
				}
			}
			
			//fireplace indoor
			if ( fireplace_target.IsFireplaceIndoor() )
			{
				if ( fireplace_target.CanCookOnStick() ) 
				{
					return true;
				}	
			}			
		}
		FBF_FireplaceBase fwfireplace_target = FBF_FireplaceBase.Cast( target.GetObject() );
		if ( fwfireplace_target && item_on_stick && item_on_stick.CanBeCookedOnStick() )
		{	
			//fireplace
			if ( fwfireplace_target.IsBaseFireplace() )
			{
				if (fwfireplace_target.CanCookOnStick()) 
				{
					return true;
				}
			}
			
			//fireplace indoor
			if ( fwfireplace_target.IsFireplaceIndoor() )
			{
				if ( fwfireplace_target.CanCookOnStick() ) 
				{
					return true;
				}	
			}			
		}
		
		return false;
	}	
};