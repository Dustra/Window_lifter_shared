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


#ifndef _APP_H        /*prevent duplicated includes*/
#define _APP_H

/* Includes */
/* -------- */

#include "typedefs.h"


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

extern void WL_Func_2ms(void);


/* Functions macros */

/* Exported defines */

#define 	ON_LED_UP		LED_ON(RA14)
#define 	OFF_LED_UP		LED_OFF(RA14)

#define 	ON_LED_DOWN		LED_ON(RA15)
#define 	OFF_LED_DOWN	LED_OFF(RA15)

#define		t_10ms				5
#define		t_500ms				245
#define		t_400ms				200
#define		t_5000ms			2500
#define 	t_10ms_antipinch	5



enum N_STATES
{
	
		state_initial=0,		
		state_up_aut,	
	 	state_down_aut,		
		state_up_manual,		
		state_down_manual,		
 		state_up_inter,		
 		state_down_inter,	
		state_antipinch			
		
};


enum N_LEVELS
{
	LEVEL_MIN=0,
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	LEVEL5,
	LEVEL6,
	LEVEL7,
	LEVEL8,
	LEVEL9,
	LEVEL_MAX 
	
};







#endif 

