/*******************************************************************************/
/**
\file       GPIO.c
\brief      General purpose IO functions
\author     Abraham Tezmol
\version    1.0
\date       31/10/2008
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"
#include "LEDS_HANDLER.h"

/** Used modules */


/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain)
{
    if (input_output == GPIO_OUTPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.OBE = 1;					/* Output buffer enable */
    	if (Open_drain == GPIO_OPEN_DRAIN_ENABLE)
    	{
    		SIU.PCR[channel].B.ODE = 1;				/* Open drain option enable */	
    	}
    	else
    	{	
    		SIU.PCR[channel].B.ODE = 0;				/* Push-pull option enable */	
    	}
    }
    else if (input_output == GPIO_INPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.IBE = 1;					/* Input buffer enable */	
    }

}

/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value)
{
    SIU.GPDO[channel].B.PDO  = logical_value;  		/* Drive the logical output value to the pin */

}




/****************************************************************************************************/
/**
* \brief    Initialize GPIO port connected to LEDs on eval board
* \author   Abraham Tezmol
* \param    void 
* \return   void
*/
void vfnGPIO_LED_Init(void)
{
    /* Data Port A initialization */
	vfnGPIO_Init_channel(LED1,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE4 --> LED1*/
	vfnGPIO_Output (LED1, 1);
	vfnGPIO_Init_channel(LED2,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE5 --> LED2*/
	vfnGPIO_Output (LED2, 1);
	vfnGPIO_Init_channel(LED3,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE6 --> LED3*/
	vfnGPIO_Output (LED3, 1);
	vfnGPIO_Init_channel(LED4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PE7 --> LED4*/
	vfnGPIO_Output (LED4, 1);
	
	
	
	
	
}

/****************************************************************************************************/
