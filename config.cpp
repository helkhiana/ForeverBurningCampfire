class CfgPatches
{
	class Forever_Burning_Campfire
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables",
			"DZ_Gear_Cooking",
			"DZ_Gear_Tools"
		};
	};
};

class CfgMods
{
    class Forever_Burning_Campfire
    {
        dir = "Forever_Burning_Campfire";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Forever_Burning_Campfire";
        credits = "";
        author = "Helkhiana";
        authorID = "0"; 
        version = "1.0"; 
        extra = 0;
        type = "mod";
        
        dependencies[] = {"Game", "World", "Mission"};
        
        class defs
        {
			class gameScriptModule
            {
                value = "";
                files[] = {"Forever_Burning_Campfire/Scripts/3_Game"};
			};

            class worldScriptModule
            {
                value = "";
                files[] = {"Forever_Burning_Campfire/Scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"Forever_Burning_Campfire/Scripts/5_Mission"};
			};
		};
    };
};

class CfgVehicles
{
	class Inventory_Base;
	class Fireplace;
	class FireplaceIndoor;
	class OvenIndoor;
	class Pot;
	class FryingPan;
	class HouseNoDestruct;
	
	class FBF_FireBarrel : HouseNoDestruct
	{
		scope=1;
		model = "\Forever_Burning_Campfire\firebarrel\firebarrel.p3d";
	};
	class FBF_Fireplace: Fireplace
	{
		scope=2;
		displayName="Fawkes Campfire";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";		
	};
	
	class FBF_FireplaceIndoor: FireplaceIndoor
	{
		scope=2;
		displayName="Fawkes Indoor Fireplace";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";
	};
	
	class FBF_OvenIndoor: OvenIndoor
	{
		scope=2;
		displayName="Fawkes Indoor Oven Fireplace";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";
	};
		
	class FBF_Pot: Pot
	{
		varQuantityInit=2000;
		varQuantityMin=2000;
		varQuantityMax=2000;
		itemsCargoSize[]={10,6};
	};
	class FBF_FryingPan: FryingPan
	{
		itemsCargoSize[]={10,6};
	};
	class FBF_Torch: HouseNoDestruct
	{
		scope=1;
		displayName="$STR_CfgVehicles_Torch0";
		descriptionShort="$STR_CfgVehicles_Torch1";
		model="\dz\gear\crafting\Torch.p3d";
		physLayer="item_small";
	};

	class FBF_LongTorch: HouseNoDestruct
	{
		displayName="$STR_cfgvehicles_long_torch";
		descriptionShort="$STR_cfgvehicles_long_torch_desc";
		model="\dz\gear\crafting\LongTorch.p3d";
		physLayer="item_small";
	};

	class FBF_AreaLight_White: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_AreaLight_Warm: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_CustomAreaLight_1: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_CustomAreaLight_2: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_CustomAreaLight_3: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_CustomAreaLight_4: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
	class FBF_CustomAreaLight_5: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
};