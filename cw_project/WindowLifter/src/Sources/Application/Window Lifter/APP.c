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
#include "typedefs.h"
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
T_UBYTE rub_flag_1ms=0;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */

T_ULONG rul_count_gen=0;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */


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

void delay_ms(vuint32_t time_ms)
{
	TIMER_REGISTER=0;
	while(TIMER_REGISTER<time_ms*1000)
	{
		
	}
	
}

/**************************************************************
 *  Name                 : Func_500us
 *  Description          : Function call by PIT, executing every 500us, calling State_Machine_1ms()
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :   [No]
 **************************************************************/
 
 
void Func_500us(void)
{
	static T_UBYTE lub_count_cycle1ms=0;
	static T_UBYTE lub_count_antipinch=0;

	lub_count_cycle1ms++;
	
	if(lub_count_cycle1ms>1)
	{
		lub_count_cycle1ms=0;
		State_Machine_1ms();
		
	}
	
	
	if(ANTIPINCH==ACTIVATED && (rub_state==state_up_aut || rub_state==state_up_manual))
	{
		lub_count_antipinch++;
		if(lub_count_antipinch>t_10ms_antipinch)
		{
			lub_count_antipinch=0;
			rub_state=state_antipinch;
				
		}
		
	}
	
}

 



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


	
	
	










