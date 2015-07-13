/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        LEDS.c
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
#include "LEDS.h"

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
 
 void Out_Leds(void)
{
	
	if(rub_level<LEVEL_MIN)
	{
		rub_level=LEVEL_MIN;
	}
	
	if(rub_level>LEVEL_MAX)
	{
		rub_level=LEVEL_MAX;
	}
	
	LED_OFF(RA0);
	LED_OFF(RA1);
	LED_OFF(RA2);
	LED_OFF(RA3);
	LED_OFF(RA4);
	LED_OFF(RA5);
	LED_OFF(RA6);
	LED_OFF(RA7);
	LED_OFF(RA8);
	LED_OFF(RA9);
	
	
	if(rub_level>LEVEL_MIN)
	{
		LED_ON(RA0);
	}

	if(rub_level>LEVEL1)
	{
		LED_ON(RA1);
	}
	if(rub_level>LEVEL2)
	{
		LED_ON(RA2);
	}
	if(rub_level>LEVEL3)
	{
		LED_ON(RA3);
	}
	if(rub_level>LEVEL4)
	{
		LED_ON(RA4);
	}
	if(rub_level>LEVEL5)
	{
		LED_ON(RA5);
	}
	if(rub_level>LEVEL6)
	{
		LED_ON(RA6);
	}
	if(rub_level>LEVEL7)
	{
		LED_ON(RA7);
	}
	if(rub_level>LEVEL8)
	{
		LED_ON(RA8);
	}
	if(rub_level>LEVEL9)
	{
		LED_ON(RA9);
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


	










