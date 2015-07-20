/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        Schm_Taks.c
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

#include "SchM_Tasks.h"
#include "GPIO.h"



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
 *  Name                 : delay_ms
 *  Description          : Delay design to stop the system while waiting for desgined time
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
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

void SchM_3P125MS_Task(void)
{

	//LED_ON(LED2);
	WL_Func_1ms();
	//LED_OFF(LED2);
	
	
}
void SchM_6P25MS_Task(void)
{

}
void SchM_12P5MS_Task(void)
{

	
}
void SchM_25MS_Task(void)
{


		
}
void SchM_50MS_Task(void)
{



}
void SchM_100MS_Task(void)
{

}












