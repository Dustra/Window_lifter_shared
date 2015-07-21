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

#include "SchM_Cfg.h"
#include "SchM_Tasks.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

const SchTaskDescriptorType SchTaskTableConfig []=
{
	/*{Offset, MASK, TASK ID , Func PTR}*/
	{0	,	MASK_1MS, 	TASK_1MS, 	&SchM_1MS_Task	}
//	{1	,	MASK_6P25MS, 	TASK_6P25MS, 	&SchM_6P25MS_Task	},
//	{2	,	MASK_12P5MS, 	TASK_12P5MS,	&SchM_12P5MS_Task	},
//	{3	,	MASK_25MS, 		TASK_25MS, 		&SchM_25MS_Task		},
//	{5	,	MASK_50MS, 		TASK_50MS, 		&SchM_50MS_Task		},
//	{6	,	MASK_100MS, 	TASK_100MS,		&SchM_100MS_Task	}
	
};

const SchConfigType SchConfig =
{
	
	(sizeof(SchTaskTableConfig)/sizeof(SchTaskTableConfig[0])),
	SchTaskTableConfig
};

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


