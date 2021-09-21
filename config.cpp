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
	class FireplaceBase;
	class Pot;
	class FryingPan;
	
	class FBF_FireplaceBase: Inventory_Base
	{
		stackedUnit="NA";
		canBeSplit=0;
		quantityBar=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varTemperatureMax=1000;
		absorbency=0;
		forceFarBubble="true";
		itemBehaviour=2;
		class AnimationSources
		{
			class Ashes
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Kindling
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Sticks
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Wood
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class BurntWood
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Stones
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Tripod
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Oven
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class LidOn
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class LidOff
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpFireplaceLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpFireplace_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="fireplace_drop_SoundSet";
					id=898;
				};
			};
		};		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLabels[]={1,0.69999999,0.5,0.30000001,0};
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cooking\data\FireplaceKit.rvmat",
								"DZ\gear\cooking\data\FireplaceKit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cooking\data\FireplaceKit.rvmat",
								"DZ\gear\cooking\data\FireplaceKit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cooking\data\FireplaceKit.rvmat",
								"DZ\gear\cooking\data\FireplaceKit.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cooking\data\FireplaceKit.rvmat",
								"DZ\gear\cooking\data\FireplaceKit.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cooking\data\FireplaceKit.rvmat",
								"DZ\gear\cooking\data\FireplaceKit.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class FBF_Fireplace: FBF_FireplaceBase
	{
		scope=2;
		displayName="Campfire";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";
		model="\dz\gear\cooking\Fireplace.p3d";
		overrideDrawArea="8.0";
		slopeTolerance=0.30000001;
		physLayer="item_large";
		openable=0;
		lootCategory="Crafted";
		itemSize[]={4,4};
		itemsCargoSize[]={10,30};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		useEntityHierarchy="true";
		attachments[]=
		{
			"Firewood",
			"WoodenStick",
			"CookingEquipment",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"CookingTripod",
			"Stones",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		class GUIInventoryAttachmentsProps
		{
			class CookingEquipment
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"CookingTripod",
					"CookingEquipment"
				};
				icon="cat_fp_cooking";
				view_index=1;
			};
			class Smoking
			{
				name="$STR_attachment_Smoking";
				description="";
				attachmentSlots[]=
				{
					"SmokingA",
					"SmokingB",
					"SmokingC",
					"SmokingD"
				};
				icon="cookingequipment";
				view_index=2;
			};
			class DirectCooking
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"DirectCookingA",
					"DirectCookingB",
					"DirectCookingC"
				};
				icon="cookingequipment";
				view_index=3;
			};
			class Upgrade
			{
				name="$STR_attachment_Upgrade0";
				description="";
				attachmentSlots[]=
				{
					"Stones"
				};
				icon="cat_fp_upgrade";
				view_index=4;
			};
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
				view_index=5;
			};
			class Kindling
			{
				name="$STR_attachment_Kindling0";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Paper",
					"Bark"
				};
				icon="cat_fp_kindling";
				view_index=6;
			};
		};
		hiddenSelections[]=
		{
			"ashes",
			"inventory"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\cooking\data\stoneground_co.paa",
			"\dz\gear\cooking\data\fireplacekit_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\dz\gear\cooking\data\stonegroundnoemit.rvmat",
			"\dz\gear\cooking\data\fireplacekit.rvmat"
		};
		hologramMaterial="FireplaceKit";
		hologramMaterialPath="dz\gear\cooking\data";
	};

	class FBF_FireplaceIgnited : FBF_Fireplace
	{

	};
	
	class FBF_FireplaceIndoor: FBF_FireplaceBase
	{
		scope=2;
		displayName="Campfire";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";
		model="\dz\gear\cooking\FireplaceIndoor.p3d";
		overrideDrawArea="8.0";
		rotationFlags=64;
		openable=0;
		lootCategory="Crafted";
		itemSize[]={4,4};
		itemsCargoSize[]={10,30};
		attachments[]=
		{
			"Firewood",
			"WoodenStick",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"DirectCookingA",
			"DirectCookingB",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		class GUIInventoryAttachmentsProps
		{
			class Smoking
			{
				name="$STR_attachment_Smoking";
				description="";
				attachmentSlots[]=
				{
					"SmokingA",
					"SmokingB",
					"SmokingC",
					"SmokingD"
				};
				icon="cookingequipment";
			};
			class CookingEquipment
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"DirectCookingA",
					"DirectCookingB"
				};
				icon="cookingequipment";
			};
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
			};
			class Kindling
			{
				name="$STR_attachment_Kindling0";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Paper",
					"Bark"
				};
				icon="cat_fp_kindling";
			};
		};
		hiddenSelections[]=
		{
			"ashes"
		};
	};
	
	class FBF_OvenIndoor: FBF_FireplaceBase
	{
		scope=2;
		displayName="$STR_cfgvehicles_fireplace0";
		descriptionShort="$STR_cfgvehicles_fireplace1";
		model="\dz\gear\cooking\OvenIndoor.p3d";
		overrideDrawArea="8.0";
		rotationFlags=64;
		openable=0;
		lootCategory="Crafted";
		itemSize[]={4,4};
		itemsCargoSize[]={10,30};
		attachments[]=
		{
			"Firewood",
			"WoodenStick",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"DirectCookingA",
			"SmokingA",
			"SmokingB"
		};
		class GUIInventoryAttachmentsProps
		{
			class Smoking
			{
				name="$STR_attachment_Smoking";
				description="";
				attachmentSlots[]=
				{
					"SmokingA",
					"SmokingB"
				};
				icon="cookingequipment";
			};
			class CookingEquipment
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"DirectCookingA"
				};
				icon="cookingequipment";
			};
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
			};
			class Kindling
			{
				name="$STR_attachment_Kindling0";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Paper",
					"Bark"
				};
				icon="cat_fp_kindling";
			};
		};
		hiddenSelections[]=
		{
			"ashes"
		};
	};
		
	class FBF_Pot: Pot
	{
		itemsCargoSize[]={10,6};
	};
	class FBF_FryingPan: FryingPan
	{
		itemsCargoSize[]={10,6};
	};
	class HouseNoDestruct;
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

	class FBF_Static_Campfire: HouseNoDestruct
	{
		scope=1;
		displayName="Campfire";
		descriptionShort="This campfire was made by Jamison Fawkes himself. It will burn forever once ignited.";
		model="\dz\gear\cooking\Fireplace.p3d";
		useEntityHierarchy="true";
		attachments[]=
		{
			"CookingEquipment"
		};
		class GUIInventoryAttachmentsProps
		{
			class CookingEquipment
			{
				name="$STR_attachment_CookingEquipment0";
				description="";
				attachmentSlots[]=
				{
					"CookingEquipment"
				};
				icon="cat_fp_cooking";
				view_index=1;
			};
		};
		class AnimationSources
		{
			class Ashes
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Kindling
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Sticks
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Wood
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class BurntWood
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Stones
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Tripod
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Oven
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class LidOn
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class LidOff
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};

	class FBF_Spotlight: HouseNoDestruct
	{
		scope=1;
		displayName="$STR_CfgVehicles_Spotlight0";
		descriptionShort="$STR_CfgVehicles_Spotlight1";
		model="\dz\gear\camping\spotlight.p3d";
		physLayer="item_small";
		class AnimationSources
		{
			class cord_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class cord_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class inventory
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class placing
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class reflector
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class reflector_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class reflector_unfolded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class glass_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class glass_unfolded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class spotlight_folded_cord_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class spotlight_folded_cord_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
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