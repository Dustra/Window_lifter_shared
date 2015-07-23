/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        APP.c
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:   	Wed July  1 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the statemachine working by PIT 	  */
/* Interruptions	                                                 		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 01/07/2015  |                               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MCU_derivative.h"
#include "APP.h"		/*Services*/
#include "GPIO.h"
#include "STM.h"
#include "LEDS.h"
#include "SWITCHES.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */

T_UBYTE rub_level=LEVEL_MAX;
T_UBYTE rub_state=state_initial;


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */

T_ULONG rul_count_gen=0;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */

void Func_state_initial(void);
void Func_state_up_inter(void);
void Func_state_down_inter(void);
void Func_state_up_manual(void);
void Func_state_down_manual(void);
void Func_state_up_auto(void);
void Func_state_down_auto(void);
void Func_state_antinpinch(void);


/* Exported functions prototypes */
/* ----------------------------- */



/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : delay_ms
 *  Description          : Delay design to stop the system while waiting for desgined time
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/


 
/**************************************************************
 *  Name                 :	State_Machine_1ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


void State_Machine_2ms(void)
{
	
		switch(rub_state)
		{

			case state_initial:   
				
				Func_state_initial();
				break;
			
			case state_up_inter: 
			
				Func_state_up_inter();
				break;
				
			case state_down_inter:
			
				Func_state_down_inter();			
				break;
			
			case state_up_aut:
			
				Func_state_up_auto();
				break;
			
			case state_down_aut:

				Func_state_down_auto();
				break;
			
			case state_up_manual:
				
				Func_state_up_manual();
				break;
			
			case state_down_manual:
			
				Func_state_down_manual();				
				break;
			
			case state_antipinch:
				
				Func_state_antinpinch();
				break;
			
			default:
				break;

		}
}




/**************************************************************
 *  Name                 : Func_State_initial  
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_initial()
{
 
 Out_Leds(&rub_level);
	
	if(rub_Debounse_UP_Push==ENABLE)
	{
		rub_state=state_up_inter;
		
	}
	
	if(rub_Debounse_DOWN_Push==ENABLE)
	{
		rub_state=state_down_inter;
	
	}
			
}

/**************************************************************
 *  Name                 : Func_state_up_inter  
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_inter()
{
	if(UP_PUSH==ACTIVATED)
	{
		rul_count_gen++;
	}
	
	if(UP_PUSH==DEACTIVATED && rul_count_gen<t_500ms)
	{
		rub_state=state_up_aut;
		rub_level++;
		Out_Leds(&rub_level);
		rul_count_gen=0;
	}
	
	if(UP_PUSH==ACTIVATED && rul_count_gen>t_500ms)
	{
		rub_state=state_up_manual;
		rub_level++;
		Out_Leds(&rub_level);
		rul_count_gen=0;
	}

}


/**************************************************************
 *  Name                 : State_down_inter  
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_inter()
{
	if(DOWN_PUSH==ACTIVATED)
		{
			rul_count_gen++;
		}
		
	if(DOWN_PUSH==DEACTIVATED && rul_count_gen<t_500ms)
		{
			rub_state=state_down_aut;
			if(rub_level>LEVEL_MIN)
			{
				rub_level--;
			}
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}
		
	if(DOWN_PUSH==ACTIVATED && rul_count_gen>t_500ms)
		{
			rub_state=state_down_manual;
			if(rub_level>LEVEL_MIN)
			{
				rub_level--;
			}
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}
			
			
}

/**************************************************************
 *  Name                 : State_up_auto 
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_auto()
{

	if(rub_level<LEVEL_MAX)
	{
		ON_LED_UP;
		rul_count_gen++;

		if(rul_count_gen>t_400ms)
		{
		
			rub_level++;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}

		
	}
		
	else
		{
			rul_count_gen=0;
			rub_state=state_initial;
			OFF_LED_UP;
		}
		
		
	if(rub_Debounse_DOWN_Push==ENABLE)
	{
		rul_count_gen=0;
		rub_state= state_initial;
		OFF_LED_UP;
		delay_ms(500);
	}
			
}

/**************************************************************
 *  Name                 : State_down_auto  
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_auto()
{

	if(rub_level>LEVEL_MIN)
	{
		ON_LED_DOWN;
		rul_count_gen++;
		
		if(rul_count_gen>t_400ms)
		{
			rub_level--;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}
	}
		
	else
	{
		rul_count_gen=0;
		rub_state=state_initial;
		OFF_LED_DOWN;
	}
		
		
	if(rub_Debounse_UP_Push==ENABLE)
	{
		rul_count_gen=0;
		rub_state= state_initial;
		OFF_LED_DOWN;
		delay_ms(500);
	}
	
}

/**************************************************************
 *  Name                 : State_up_manual
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_manual()
{

	if(rub_level<LEVEL_MAX)
	{
		ON_LED_UP;
		rul_count_gen++;
		
		if(rul_count_gen>t_400ms)
		{
			rub_level++;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}

	}
	else
	{
		OFF_LED_UP;
	}
		
	
	if(UP_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_UP;
	}
	
	
	
}

/**************************************************************
 *  Name                 : State_state_down_manual
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_manual()
{

	if(rub_level>LEVEL_MIN)
	{
		ON_LED_DOWN;
		rul_count_gen++;
		
		if(rul_count_gen>t_400ms)
		{
			rub_level--;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}

	}
	else
	{
		OFF_LED_DOWN;
	}
		
	
	if(DOWN_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_DOWN;
	}
	

}

/**************************************************************
 *  Name                 : State_antipinch
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_antinpinch()
{
	OFF_LED_UP;

	if(rub_level>LEVEL_MIN)
	{
		
		ON_LED_DOWN;
		rul_count_gen++;

		if(rul_count_gen>t_400ms)
		{
			rub_level--;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}
	}
		
	else
		{
			rul_count_gen++;
			if(rul_count_gen>t_5000ms)
			{
				rul_count_gen=0;
				rub_state=state_initial;
				OFF_LED_DOWN;
			}
		
		
		}
}
	
	
	
/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 : Func_500us
 *  Description          : Function call by PIT, executing every 500us, calling State_Machine_1ms()
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :   [No]
 **************************************************************/
 
 
void WL_Func_2ms(void)
{

	if(	rub_Debounse_ANTIPINCH==ENABLE && (rub_state==state_up_aut || rub_state==state_up_manual))
	{
		rub_state=state_antipinch;
	}
		
	State_Machine_2ms();
	
}

