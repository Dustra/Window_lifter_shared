/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        Schm.c
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:   	Wed July  1 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the funcions of Scheduler 		  */
/* 					                                                 		  */
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

#include "SchM.h"
#include "PIT.h"
#include "MemAlloc.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

const SchConfigType *  rps_Sch_Config_Ptr;


/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */



/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */

SchTaskControlType* SchTaskControlVector;
SchControltype SchControl;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */


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
 *  Name                 : delay_ms
 *  Description          : Delay design to stop the system while waiting for desgined time
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :	void
 *  Critical/explanation :    [No]
 **************************************************************/




/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Init
 *  Description          :	Config of Scheduler
 *  Parameters           :  [const SchConfigType *Sch_Config_ptr]
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/

	
void SchM_Init(const SchConfigType *Sch_Config_ptr)
 {
 	SchTaskDescriptorType *  Sch_Desc_Ptr;
 	T_UBYTE lub_iterator;
 	
 	/*Set interruption timer*/
 	PIT_device_init();					
 	/*Channel Config and Callback*/					
	PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);	
 	/*Definition of Global Config Pointer*/
 	rps_Sch_Config_Ptr=Sch_Config_ptr;
 	/*Definition of Local Descriptor Pointer*/
	Sch_Desc_Ptr = (SchTaskDescriptorType *) Sch_Config_ptr->SchTaskDescriptorPtr;
 	/*Initialize Scheduler counter*/
 	SchControl.SchCounter=0;	
 	/*Initialize Scheduler Status*/
 	SchControl.SchStatus=SCH_INIT;
 	/*Memory reserve dynamicaly for the ControlVector*/ 	
 	SchTaskControlVector=(SchTaskControlType*)MemAlloc(sizeof(SchTaskControlVector)*Sch_Config_ptr->SchNumberofTasks); 
 	
 	/*For through the Number of Tasks*/
	for(lub_iterator=0; lub_iterator < Sch_Config_ptr->SchNumberofTasks ; lub_iterator++)
 	{
 		/*Initialize state suspended*/
 		SchTaskControlVector[lub_iterator].SchTaskState = TASK_STATE_SUSPENDED;		
 		/*Initialize the taks functions pointers*/
 		SchTaskControlVector[lub_iterator].TaskFunctionControlPtr = Sch_Desc_Ptr[lub_iterator].TaskFunctionPtr;  
	}
 	 
 	
 }
 

/**************************************************************
 *  Name                 :	SchM_Stop
 *  Description          :	Stop of the Scheduler
 *  Parameters           :  [void]
 *  Return               :	[void]
 *  Critical/explanation :    [No]
 **************************************************************/
 
 void SchM_Stop(void)
 {
	 /*Stop Interrupt Timer*/
	 PIT_channel_stop(PIT_CHANNEL_0);
	 /*State of Scheduler to Halted*/
	 SchControl.SchStatus= SCH_HALTED;	
 }
 

/**************************************************************
 *  Name                 :	SchM_Start
 *  Description          :	Start the Scheduler
 *  Parameters           :  [void]
 *  Return               :	[void]
 *  Critical/explanation :    [No]
 **************************************************************/
 
 
 void SchM_Start(void)
 {

	/*Start Timer of interruption*/
	PIT_channel_start(PIT_CHANNEL_0);	
	/*Enable Interruptions*/
	enableIrq();
	/*Set the state of the Scheduler as running*/
 	SchControl.SchStatus= SCH_RUNNING;	
 	/*Call of the background function*/
	SchM_Background();					
 }


/**************************************************************
 *  Name                 :	SchM_OsTick
 *  Description          :	Callback function of the interruption
 *  Parameters           :  [void]
 *  Return               :	[void]
 *  Critical/explanation :    [No]
 **************************************************************/
 
 
 void SchM_OsTick(void)
 {
 	SchTaskDescriptorType *  Sch_Desc_Ptr = (SchTaskDescriptorType *) rps_Sch_Config_Ptr->SchTaskDescriptorPtr;
 	T_UBYTE lub_iterator;
 	
 	/*Main Counter of Scheduler*/
  	SchControl.SchCounter++;    

 	/*For trough the Control Vector*/
 	for(lub_iterator=0 ; lub_iterator < rps_Sch_Config_Ptr -> SchNumberofTasks ; lub_iterator++)		 /*For through number of tasks*/
 	{
   		/*And with mask and compare to Offset*/
 		if(((SchControl.SchCounter) & (Sch_Desc_Ptr[lub_iterator].SchTaskMask)) ==  (Sch_Desc_Ptr[lub_iterator].SchTaskOffset))
 		{
 			/*Change state of tasks in ControlVector*/
 			SchTaskControlVector[lub_iterator].SchTaskState= TASK_STATE_READY;	
  		}
  		else
  		{
  			/*Do nothing*/
  		}
	}
 }
 

/**************************************************************
 *  Name                 :	SchM_Background
 *  Description          :	Function running in the Background of the Scheduler
 *  Parameters           :  [void]
 *  Return               :	[void]
 *  Critical/explanation :    [No]
 **************************************************************/
 
 void SchM_Background(void)
 {
 	T_UBYTE lub_iterator;
 	
 	for(;;)
 	{
 		/*For trough the Control Tasks Vector*/
	 	for(lub_iterator=0 ; lub_iterator < rps_Sch_Config_Ptr-> SchNumberofTasks; lub_iterator++)
	 	{
	 		/*Check the state Tasks*/
		 	if(SchTaskControlVector[lub_iterator].SchTaskState==TASK_STATE_READY)
		 	{
		 		/*State of Task Running*/
		 		SchTaskControlVector[lub_iterator].SchTaskState = TASK_STATE_RUNNING;
		 		/*Call Function of Tasks*/
		 		SchTaskControlVector[lub_iterator].TaskFunctionControlPtr();
		 		/*State of Task Suspended*/
		 		SchTaskControlVector[lub_iterator].SchTaskState = TASK_STATE_SUSPENDED;
		 		
		 	}
		 	else
		 	{
		 		/*Do nothing*/
		 	}
	 	
	 	 	
	 	}
 	 		
 	}
 
 	
 }

	










