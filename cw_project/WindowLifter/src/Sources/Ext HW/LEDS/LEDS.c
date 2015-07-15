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

 void Out_Leds(void);


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
 *  Name                 : LED_Init
 *  Description          :	Translate the value in variable rub_level to digital outputs
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
 void LED_Init(void)
 {
 	
 	vfnGPIO_Init_channel(RA0,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA0-> as output*/
	vfnGPIO_Output (RA0, 0);
	vfnGPIO_Init_channel(RA1,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA1-> as output*/
	vfnGPIO_Output (RA1, 0);
	vfnGPIO_Init_channel(RA2,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA2-> as output*/
	vfnGPIO_Output (RA2, 0);
	vfnGPIO_Init_channel(RA3,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA3-> as output*/
	vfnGPIO_Output (RA3, 0);
	vfnGPIO_Init_channel(RA4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA4-> as output*/
	vfnGPIO_Output (RA4, 0);
	vfnGPIO_Init_channel(RA5,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA5-> as output*/
	vfnGPIO_Output (RA5, 0);
	vfnGPIO_Init_channel(RA6,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA6-> as output*/
	vfnGPIO_Output (RA6, 0);
	vfnGPIO_Init_channel(RA7,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA7-> as output*/
	vfnGPIO_Output (RA7, 0);
	vfnGPIO_Init_channel(RA8,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA8-> as output*/
	vfnGPIO_Output (RA8, 0);
	vfnGPIO_Init_channel(RA9,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA9-> as output*/
	vfnGPIO_Output (RA9, 0);
	vfnGPIO_Init_channel(RA10,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA10-> as output*/
	vfnGPIO_Output (RA10, 0);
	vfnGPIO_Init_channel(RA11,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA11-> as output*/
	vfnGPIO_Output (RA11, 0);
	vfnGPIO_Init_channel(RA12,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA12-> as output*/
	vfnGPIO_Output (RA12, 0);
	vfnGPIO_Init_channel(RA13,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA13-> as output*/
	vfnGPIO_Output (RA13, 0);
	vfnGPIO_Init_channel(RA14,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA14-> as output*/
	vfnGPIO_Output (RA14, 0);
	vfnGPIO_Init_channel(RA15,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /*RA15-> as output*/
	vfnGPIO_Output (RA15, 0);
 

}
 
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


	










