/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        main.c
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Wed	July  1 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes main routine of the window lifter   */
/*                                                							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 01/07/2015  |                               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/
/*  1.1      | 09/07/2015  |                               | Erick Salinas    */
/* Integration of SCHEDULER MODULE                                            */
/*============================================================================*/



/* Includes */
/* -------- */

#include 	"MCU_derivative.h"
#include    "GPIO.h"			/*Services*/
#include    "PIT.h"
#include    "APP.h"
#include	"STM.h"
#include 	"LEDS_HANDLER.h"
#include 	"SWITCHES_HANDLER.h"
#include 	"SchM.h"
#include 	"MemAlloc_Cfg.h"


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

void disableWatchdog(void);


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
 *  Name                 : disableWatchdog
 *  Description          : Disable function of watchdog
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void disableWatchdog(void)
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}

/**************************************************************
 *  Name                 : main
 *  Description          : main routine of the aplication, contains configuration routines en infinite loop
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

int main(void) 

{
	/*Initiate Run Mode at 64K*/
	initModesAndClock();
	/*Disable Watchdog in private function*/
	disableWatchdog();
	/*Config of Malloc Module*/
	MemAllocInit(&MemAllocConfig);
	/*Init of internal HW LEDS*/
	vfnGPIO_LED_Init();	
	/*Init of external HW LEDS*/
	LED_Init();
	/*Init of Push*/
	PUSH_Init();
	/*INT interruptions*/
	INTC_InitINTCInterrupts();
	/*STM TIMER Module Configuration*/
	Timer_Config();
	/*Init Except Handler*/
	EXCEP_InitExceptionHandlers();
	/*Config of Scheduler*/
	SchM_Init(&SchConfig);
	/*Start Scheduler and loop in Background Function*/
	SchM_Start();
    
    while(1)
    {

	
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



