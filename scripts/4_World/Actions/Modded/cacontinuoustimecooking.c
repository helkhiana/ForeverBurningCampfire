modded class CAContinuousTimeCooking : CAContinuousBase
{
	override void Setup( ActionData action_data )
	{
		m_TimeElapsedRepeat = 0;
		
		if ( !m_SpentUnits )
		{ 
			m_SpentUnits = new Param1<float>(0);
		}
		else
		{	
			m_SpentUnits.param1 = 0;
		}
		
		//fireplace & cooking process
		FireplaceBase fireplace = FireplaceBase.Cast( action_data.m_Target.GetObject() );
		if(fireplace){
			m_CookingProcess = fireplace.GetCookingProcess();
		}else{
			
			FBF_FireplaceBase fwfireplace_target = FBF_FireplaceBase.Cast( action_data.m_Target.GetObject() );			
			m_CookingProcess = fwfireplace_target.GetCookingProcess();
		}
		m_ItemToCook = m_CookingProcess.GetFoodOnStick( action_data.m_MainItem );
		m_TimeToCook = m_CookingProcess.GetTimeToCook( m_ItemToCook, CookingMethodType.BAKING );
		
		//update elapsed time
		m_TimeElapsed = m_ItemToCook.GetFoodStage().GetCookingTime();
		
		//SoftSkill implementation to hasten Cooking
		m_AdjustedCookingUpdateTime = action_data.m_Player.GetSoftSkillsManager().SubtractSpecialtyBonus( m_CookingUpdateTime, m_Action.GetSpecialtyWeight(), true);
		m_AdjustedTimeToCook = action_data.m_Player.GetSoftSkillsManager().SubtractSpecialtyBonus( m_TimeToCook, m_Action.GetSpecialtyWeight(), true);
	}	
};