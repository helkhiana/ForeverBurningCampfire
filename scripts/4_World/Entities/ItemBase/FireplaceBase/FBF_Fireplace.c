class FBF_FireplaceBase extends FireplaceBase
{
    override void CalcAndSetQuantity()
	{
		if (GetGame() && GetGame().IsServer())
		{			
			SetQuantity(10000);
		}
	}

    override void SpendFireConsumable(float amount)
	{
		CalcAndSetQuantity();
	}

    override void BurnItemsInFireplace()
	{
		//! cargo
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			
			//set damage
			AddDamageToItemByFireEx(item, false, false);

			if (item.GetHealth("", "Health") <= 0 && !item.IsKindOf("Grenade_Base"))
			{
				item.Delete();
			}
			
			//add temperature
			AddTemperatureToItemByFire(item);
			
			//remove wetness
			AddWetnessToItem(item, -PARAM_WET_HEATING_DECREASE_COEF);
		}
	}
};


class FBF_Fireplace extends Fireplace
{		
	override void DeferredInit()
	{
		super.DeferredInit();
		if(GetGame().IsServer())
		{
			ItemBase firewood = ItemBase.Cast(GetInventory().CreateAttachment("FireWood"));
			if(firewood)
			{
				firewood.SetQuantity(firewood.GetQuantityMax())
			}
			GetInventory().CreateAttachment("Paper");
			SetLifetime(7888000);
			Synchronize();
		}
	}

    override bool CanReleaseAttachment( EntityAI attachment )
	{
		ItemBase item = ItemBase.Cast( attachment );
		if (item.IsKindOf("FBF_Pot") || item.IsKindOf("FBF_FryingPan"))
		{
			return false;
		}
        return super.CanReleaseAttachment(attachment);
    }	
    
    override void CalcAndSetQuantity()
	{
		if (GetGame() && GetGame().IsServer())
		{			
			SetQuantity(10000);
		}
	}

    override void SpendFireConsumable(float amount)
	{
		CalcAndSetQuantity();
	}

    override void BurnItemsInFireplace()
	{
		//! cargo
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			
			//set damage
			AddDamageToItemByFireEx(item, false, false);

			if (item.GetHealth("", "Health") <= 0 && !item.IsKindOf("Grenade_Base"))
			{
				item.Delete();
			}
			
			//add temperature
			AddTemperatureToItemByFire(item);
			
			//remove wetness
			AddWetnessToItem(item, -PARAM_WET_HEATING_DECREASE_COEF);
		}
	}
};

class FBF_FireplaceIndoor extends FireplaceIndoor
{
    override bool CanReleaseAttachment( EntityAI attachment )
	{
		ItemBase item = ItemBase.Cast( attachment );
		if (item.IsKindOf("FBF_Pot") || item.IsKindOf("FBF_FryingPan"))
		{
			return false;
		}
        return super.CanReleaseAttachment(attachment);
    }		
    
    override void CalcAndSetQuantity()
	{
		if (GetGame() && GetGame().IsServer())
		{			
			SetQuantity(10000);
		}
	}

    override void SpendFireConsumable(float amount)
	{
		CalcAndSetQuantity();
	}

    override void BurnItemsInFireplace()
	{
		//! cargo
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			
			//set damage
			AddDamageToItemByFireEx(item, false, false);

			if (item.GetHealth("", "Health") <= 0 && !item.IsKindOf("Grenade_Base"))
			{
				item.Delete();
			}
			
			//add temperature
			AddTemperatureToItemByFire(item);
			
			//remove wetness
			AddWetnessToItem(item, -PARAM_WET_HEATING_DECREASE_COEF);
		}
	}
};

class FBF_OvenIndoor extends OvenIndoor
{
    override bool CanReleaseAttachment( EntityAI attachment )
	{
		ItemBase item = ItemBase.Cast( attachment );
		if (item.IsKindOf("FBF_Pot") || item.IsKindOf("FBF_FryingPan"))
		{
			return false;
		}
        return super.CanReleaseAttachment(attachment);
    }		
    
    override void CalcAndSetQuantity()
	{
		if (GetGame() && GetGame().IsServer())
		{			
			SetQuantity(10000);
		}
	}

    override void SpendFireConsumable(float amount)
	{
		CalcAndSetQuantity();
	}

    override void BurnItemsInFireplace()
	{
		//! cargo
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			
			//set damage
			AddDamageToItemByFireEx(item, false, false);

			if (item.GetHealth("", "Health") <= 0 && !item.IsKindOf("Grenade_Base"))
			{
				item.Delete();
			}
			
			//add temperature
			AddTemperatureToItemByFire(item);
			
			//remove wetness
			AddWetnessToItem(item, -PARAM_WET_HEATING_DECREASE_COEF);
		}
	}
};