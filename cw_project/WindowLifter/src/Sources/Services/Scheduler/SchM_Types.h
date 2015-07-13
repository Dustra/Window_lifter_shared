
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
	MASK_3P125MS=	3,
	MASK_6P25MS	=	7,
	MASK_12P5MS	=	15,
	MASK_25MS	=	31,
	MASK_50MS	=	63,
	MASK_100MS	=	127
		
}SchTaskMaskType;

typedef enum
{
	TASK_BKG,
	TASK_3P125MS,
	TASK_6P25MS,
	TASK_12P5MS,
	TASK_25MS,
	TASK_50MS,
	TASK_100MS
	
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
	
	T_UBYTE SchNumberofTasks;
	const SchTaskDescriptorType *SchTaskDescriptor;
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