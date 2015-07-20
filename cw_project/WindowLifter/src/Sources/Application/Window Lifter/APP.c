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
#include "Switches.h"

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

void State_Machine_1ms(void);
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


void State_Machine_1ms(void)
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
	OFF_LED_DOWN;
    OFF_LED_UP;                           
	Out_Leds(&rub_level);
	
	if(UP_PUSH==ACTIVATED)
	{
		rul_count_gen++;
		if(rul_count_gen>t_10ms)
		{
			rub_state=state_up_inter;
		}
	}
	
	if(DOWN_PUSH==ACTIVATED)
	{
		rul_count_gen++;
		if(rul_count_gen>t_10ms)
		{
			rub_state=state_down_inter;
		}
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
		rul_count_gen=0;
	}
	
	if(UP_PUSH==ACTIVATED && rul_count_gen>t_500ms)
	{
		rub_state=state_up_manual;
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
			rul_count_gen=0;
		}
		
	if(DOWN_PUSH==ACTIVATED && rul_count_gen>t_500ms)
		{
			rub_state=state_down_manual;
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
ON_LED_UP;
rul_count_gen++;

if(rub_level<LEVEL_MAX)
{
	
	if(rul_count_gen>t_400ms)
		{
			rub_level++;
			Out_Leds(&rub_level);
			rul_count_gen=0;
		}
	else
		{
			/*Do nothing*/
		}
	
}
	
else
	{
		rul_count_gen=0;
		rub_state=state_initial;
	}
	
	
if(DOWN_PUSH==ACTIVATED)
	{
		rul_count_gen=0;
		rub_state= state_initial;
		delay_ms(500);
	}
else
	{
		/*Do nothing*/
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

	if(rub_level<LEVEL_MIN+1)
		{
		
		rul_count_gen=0;
		rub_state=state_initial;
		
		}
		else
		{
			
		ON_LED_DOWN;
		rul_count_gen++;				
	
		
		if(rul_count_gen>t_400ms)
		{
		
		rub_level--;
		Out_Leds(&rub_level);
		rul_count_gen=0;
		
		}
		
		if(UP_PUSH==ACTIVATED)
		{
			rul_count_gen=0;
			rub_state= state_initial;
			delay_ms(500);
		}
					
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
	ON_LED_UP;
	rul_count_gen++;

	
	if(rub_level<LEVEL_MAX && rul_count_gen>t_400ms)
	{
		
		rub_level++;
		Out_Leds(&rub_level);
		OFF_LED_UP;
		rul_count_gen=0;
	}
		
	
	
	if(UP_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_UP;
	}
	
	if(rub_level>LEVEL_MAX-1)
	{
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
	ON_LED_DOWN;
	rul_count_gen++;

	
	if(rub_level>LEVEL_MIN && rul_count_gen>t_400ms)
	{
		
		rub_level--;
		Out_Leds(&rub_level);
		OFF_LED_DOWN;
		rul_count_gen=0;
	}
		
	
	
	if(DOWN_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_DOWN;
	}
	
	if(rub_level<LEVEL_MIN+1)
	{
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
	if(rub_level<LEVEL_MIN+1)
	{
	rul_count_gen=0;
	delay_ms(t_5000ms);
	rub_state=state_initial;

	}
	else
	{
		
					
	ON_LED_DOWN;
	rub_level--;
	Out_Leds(&rub_level);
	if(rub_level>0)
	{
		delay_ms(t_400ms);	
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
 
 
void WL_Func_1ms(void)
{
	static T_UBYTE lub_count_antipinch=0;

	if(ANTIPINCH==ACTIVATED && (rub_state==state_up_aut || rub_state==state_up_manual))
	{
		lub_count_antipinch++;
		if(lub_count_antipinch>t_10ms_antipinch)
		{
			lub_count_antipinch=0;
			rub_state=state_antipinch;
				
		}
		
	}
		
	State_Machine_1ms();
	
}

