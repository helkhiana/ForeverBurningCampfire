class FBF_FireplaceBase extends FireplaceBase
{
    override void CalcAndSetQuantity()
	{
		if (GetGame() && GetGame().IsServer())
		{			
			SetQuantity(10000);
		}
	}
};