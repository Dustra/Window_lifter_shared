/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        Switches.c
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

#include "GPIO.h"
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



/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


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
 *  Name                 : Out_Leds
 *  Description          :	Translate the value in variable rub_level to digital outputs
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/

 
 



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
T_UBYTE rub_Debounse_UP_Push=0;
T_UBYTE rub_Debounse_DOWN_Push=0;
T_UBYTE rub_Debounse_ANTIPINCH=0;



void PUSH_Init(void)
{
	
	vfnGPIO_Init_channel(PUSH1,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE4 --> PUSH1*/
	vfnGPIO_Init_channel(PUSH2,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE5 --> PUSH2*/
	vfnGPIO_Init_channel(PUSH3,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE6 --> PUSH3*/
	vfnGPIO_Init_channel(PUSH4,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE7 --> PUSH4*/
	
}


void Debounse_PUSH_1ms(void)
{
	
static T_UBYTE lub_counter_up=0;
static T_UBYTE lub_counter_down=0;
static T_UBYTE lub_counter_antipinch=0;


	/*Debounse Up push*/
	
	if(UP_PUSH==ACTIVATED)
	{
		lub_counter_up++;
		if(lub_counter_up>t_10ms_debounse)
		{
			rub_Debounse_UP_Push=ENABLE;
			lub_counter_up=0;	
		}
	}
	else
	{
		lub_counter_up=0;
		rub_Debounse_UP_Push=DISABLE;
	}


	/*Debounse Down Push*/
	
	if(DOWN_PUSH==ACTIVATED)
	{
		lub_counter_down++;
		if(lub_counter_down>t_10ms_debounse)
		{
			rub_Debounse_DOWN_Push=ENABLE;
			lub_counter_down=0;	
		}
				
	}
	else
	{
		lub_counter_down=0;
		rub_Debounse_DOWN_Push=DISABLE;
	}
	
	/*Debounse Antipinch*/
	
	if(ANTIPINCH==ACTIVATED)
	{
		lub_counter_antipinch++;
		if(lub_counter_antipinch>t_10ms_debounse)
		{
			rub_Debounse_ANTIPINCH=ENABLE;
			lub_counter_antipinch=0;	
		}
		
	}
	else
	{
		lub_counter_antipinch=0;
		rub_Debounse_ANTIPINCH=DISABLE;
	}
	


}









