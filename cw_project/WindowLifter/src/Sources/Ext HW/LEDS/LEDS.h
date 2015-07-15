/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        LEDS.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Wed July 6 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : Header for LEDS MODULE			            		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _LEDS_H        /*prevent duplicated includes*/
#define _LEDS_H

/* Includes */
/* -------- */

#include "typedefs.h"
#include "APP.h"


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

extern void Out_Leds(void);

/*defines*/


enum PORTA
{
	 RA0=0,													
	 RA1,												
	 RA2,											
	 RA3,							
	 RA4,											
	 RA5,											
	 RA6,									
	 RA7,												
	 RA8,											
	 RA9,												
	 RA10,											
	 RA11,											
	 RA12,												
	 RA13,						
	 RA14,						
	 RA15							
};

/*
#define RA0							0						
#define RA1							1					
#define RA2							2				
#define RA3							3
#define RA4							4				
#define RA5							5				
#define RA6							6		
#define RA7							7					
#define RA8							8				
#define RA9							9					
#define RA10						10					
#define RA11						11					
#define RA12						12						
#define RA13						13
#define RA14						14
#define RA15						15
*/

/* Functions macros */

/* Exported defines */







#endif 

