/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        SWITCHES.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Wed July 6 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : Header for SITCHES MODULE			            		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _SWITCHES_H        /*prevent duplicated includes*/
#define _SWITCHES_H

/* Includes */
/* -------- */

#include "typedefs.h"



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

extern T_UBYTE rub_Debounse_UP_Push;
extern T_UBYTE rub_Debounse_DOWN_Push;
extern T_UBYTE rub_Debounse_ANTIPINCH;


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

extern void PUSH_Init(void);
extern void Debounse_PUSH_1ms(void);

/* Functions prototypes */

/*defines*/
#define 	ANTIPINCH		INPUT(PUSH3)
#define		UP_PUSH			INPUT(PUSH1)
#define		DOWN_PUSH		INPUT(PUSH2)

#define PUSH1						64
#define PUSH2						65
#define PUSH3						66
#define PUSH4						67

#define DEACTIVATED					1
#define	ACTIVATED					0

#define	ENABLE						1
#define DISABLE						0

/* Functions macros */

/* Exported defines */

#define t_10ms_debounse 	10





#endif 

