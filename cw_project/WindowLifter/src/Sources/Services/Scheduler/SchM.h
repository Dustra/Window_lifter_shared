/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        SchM.h
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

#ifndef _SchM_H_
#define _SchM_H_



/* Includes */
/* -------- */

#include "SchM_Types.h"
#include "SchM_Cfg.h"


/*Exported types and constants*/
/*----------------------------*/

/*Types definition*/
/*typedefs*/





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


extern void SchM_Init(const SchConfigType *Sch_Config_ptr);
extern void SchM_Stop(void);
extern void SchM_Start(void);
extern void SchM_OsTick(void);
extern void SchM_Background(void);



/* Functions macros */

/* Exported defines */



















#endif