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
/*  1.0      | 01/07/2015  |                               | Erick Salinas     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include 	"MCU_derivative.h"
#include    "GPIO.h"			/*Services*/
#include    "PIT.h"
#include    "APP.h"
#include	"STM.h"
#include 	"LEDS.h"

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
void State_Machine_1ms(void);
void Func_state_initial(void);
void Func_state_up_inter(void);
void Func_state_down_inter(void);
void Func_state_up_manual(void);
void Func_state_down_manual(void);
void Func_state_up_auto(void);
void Func_state_down_auto(void);
void Func_state_antinpinch(void);

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

	initModesAndClock();
	disableWatchdog();
	vfnGPIO_LED_Init();	
	INTC_InitINTCInterrupts();
	Timer_Config();
	EXCEP_InitExceptionHandlers();
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , Func_500us);	
    PIT_channel_start(PIT_CHANNEL_0);
    enableIrq();

    
    while(1)
    {

	
    }
}

void State_Machine_1ms(void)
{
	
		switch(rub_state)
		{

			case state_initial:   
				
				Func_state_initial();
		
				break;
			
			case state_up_inter: 
			
				Func_state_up_inter();
				break;
				
			case state_down_inter:
			
				Func_state_down_inter();			
				break;
			
			
			
			case state_up_aut:
			
				Func_state_up_auto();
				break;
			
			
			
			case state_down_aut:

				Func_state_down_auto();
				break;
			
			case state_up_manual:
				
				Func_state_up_manual();
				break;
			
			
			case state_down_manual:
			
				Func_state_down_manual();				
				break;
			
			case state_antipinch:
				
				Func_state_antinpinch();
				break;
				
			
			default:
				break;

		}
}




/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_initial()
{
	OFF_LED_DOWN;
    OFF_LED_UP;                           
	Out_Leds();
	
	if(UP_PUSH==ACTIVATED)
	{
		rul_count_gen++;
		if(rul_count_gen>t_10ms)
		{
			rub_state=state_up_inter;
		}
	}
	
	if(DOWN_PUSH==ACTIVATED)
	{
		rul_count_gen++;
		if(rul_count_gen>t_10ms)
		{
			rub_state=state_down_inter;
		}
	}
			
}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_inter()
{
	if(UP_PUSH==ACTIVATED)
	{
		rul_count_gen++;
	}
	
	if(UP_PUSH==DEACTIVATED && rul_count_gen<t_500ms)
	{
		rub_state=state_up_aut;
		rub_level++;
		rul_count_gen=0;
	}
	
	if(UP_PUSH==ACTIVATED && rul_count_gen>t_500ms)
	{
		rub_state=state_up_manual;
		rub_level++;
		rul_count_gen=0;
	}

}


/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_inter()
{
	if(DOWN_PUSH==ACTIVATED)
		{
			rul_count_gen++;
		}
		
		if(DOWN_PUSH==DEACTIVATED && rul_count_gen<t_500ms)
		{
			rub_state=state_down_aut;
			if(rub_level>0)
			{
				rub_level--;	
			}
		
			rul_count_gen=0;
		}
		
		if(DOWN_PUSH==ACTIVATED && rul_count_gen>t_500ms)
		{
			rub_state=state_down_manual;
			if(rub_level>0)
			{
				rub_level--;	
			}
			rul_count_gen=0;
		}
			
			
}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_auto()
{
if(rub_level>LEVEL_MAX-1)
		{
		
		rul_count_gen=0;
		rub_state=state_initial;
		
		}
		else
		{
			
		ON_LED_UP;
		rul_count_gen++;				
		Out_Leds();
		
		if(rul_count_gen>t_400ms)
		{
		
		rub_level++;
		rul_count_gen=0;
		
		}
		
		if(DOWN_PUSH==ACTIVATED)
		{
			rul_count_gen=0;
			rub_state= state_initial;
			delay_ms(500);
		}
		
								
					}
			
}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_auto()
{

	if(rub_level<LEVEL_MIN+1)
		{
		
		rul_count_gen=0;
		rub_state=state_initial;
		
		}
		else
		{
			
		ON_LED_DOWN;
		rul_count_gen++;				
		Out_Leds();
		
		if(rul_count_gen>t_400ms)
		{
		
		rub_level--;
		rul_count_gen=0;
		
		}
		
		if(UP_PUSH==ACTIVATED)
		{
			rul_count_gen=0;
			rub_state= state_initial;
			delay_ms(500);
		}
					
		}

}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_up_manual()
{
	ON_LED_UP;
	rul_count_gen++;
	Out_Leds();
	
	if(rub_level<LEVEL_MAX && rul_count_gen>t_400ms)
	{
		
		rub_level++;
		OFF_LED_UP;
		rul_count_gen=0;
	}
		
	
	
	if(UP_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_UP;
	}
	
	if(rub_level>LEVEL_MAX-1)
	{
		OFF_LED_UP;
	}
	
	
}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_down_manual()
{
	ON_LED_DOWN;
	rul_count_gen++;
	Out_Leds();
	
	if(rub_level>LEVEL_MIN && rul_count_gen>t_400ms)
	{
		
		rub_level--;
		OFF_LED_DOWN;
		rul_count_gen=0;
	}
		
	
	
	if(DOWN_PUSH==DEACTIVATED)
	{
		rub_state=state_initial;
		OFF_LED_DOWN;
	}
	
	if(rub_level<LEVEL_MIN+1)
	{
		OFF_LED_DOWN;
	}
	
}

/**************************************************************
 *  Name                 : State_initial  (iddle)
 *  Description          : 
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/

void Func_state_antinpinch()
{
	OFF_LED_UP;
	if(rub_level<LEVEL_MIN+1)
	{
	rul_count_gen=0;
	delay_ms(t_5000ms);
	rub_state=state_initial;

	}
	else
	{
		
					
	ON_LED_DOWN;
	rub_level--;
	Out_Leds();
	if(rub_level>0)
	{
		delay_ms(t_400ms);	
	}
	
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



