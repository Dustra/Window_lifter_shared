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
#include "LEDS.h"

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

extern T_UBYTE rub_level;
extern T_UBYTE rub_state;
extern T_UBYTE rub_flag_1ms;


/* WORDS */


/* LONGS and STRUCTURES */

extern T_ULONG rul_count_gen;



/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */


/* Functions prototypes */

extern void WL_Func_1ms(void);


/* Functions macros */

/* Exported defines */



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

#define 	ON_LED_UP		LED_ON(RA14)
#define 	OFF_LED_UP		LED_OFF(RA14)

#define 	ON_LED_DOWN		LED_ON(RA15)
#define 	OFF_LED_DOWN	LED_OFF(RA15)





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



#define		t_10ms			10
#define		t_500ms			500
#define		t_400ms			400
#define		t_5000ms		5000
#define 	t_10ms_antipinch	10




#endif 

