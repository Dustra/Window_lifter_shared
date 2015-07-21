
/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        APP.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Wed July 6 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : Contains header for APP.C function              		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef _SCHM_TYPEDEFS_H_
#define _SCHM_TYPEDEFS_H_


/* Includes */
/* -------- */

#include "typedefs.h"


/*Exported types and constants*/
/*----------------------------*/

/*Types definition*/
/*typedefs*/

typedef void (*TaskFunctionPtrType)(void);
typedef T_UBYTE SchTaskOffsetType;


typedef enum
{
	MASK_1MS=1,
	MASK_2MS=2

		
}SchTaskMaskType;

typedef enum
{
	TASK_BKG,
	TASK_1MS,
	TASK_2MS
	
}SchTaskIDType;

typedef enum
{
	
	TASK_STATE_SUSPENDED,
	TASK_STATE_READY,
	TASK_STATE_RUNNING
		
}SchTaskStateType;


typedef struct
{
	SchTaskStateType SchTaskState;
	TaskFunctionPtrType TaskFunctionControlPtr;

}SchTaskControlType;


typedef struct 
{
	SchTaskOffsetType	 SchTaskOffset;
	SchTaskMaskType 	 SchTaskMask;
	SchTaskIDType		 SchTaskID;
	TaskFunctionPtrType	 TaskFunctionPtr;
	
}SchTaskDescriptorType;


typedef struct 
{
	
	T_UBYTE 						SchNumberofTasks;
	const SchTaskDescriptorType 	*SchTaskDescriptorPtr;

}SchConfigType;

typedef enum
{
	SCH_UNINIT,
	SCH_INIT,
	SCH_RUNNING,
	SCH_OVERLOAD,
	SCH_HALTED
	
}SchStateType;

typedef struct
{
	T_UBYTE SchCounter;
	SchTaskIDType SchedulerTaskRunning;
	SchStateType SchStatus;
		
}SchControltype;








/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */




/* WORDS */


/* LONGS and STRUCTURES */





/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */


/* Functions prototypes */



/* Functions macros */

/* Exported defines */








#endif