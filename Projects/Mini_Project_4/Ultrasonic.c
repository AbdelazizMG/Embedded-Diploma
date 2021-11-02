/******************************************************************************
*  Module:    Ultrasonic
*  File name: Ultrasonic.h
*  Created on: Oct 15, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "Ultrasonic.h"
#include "ICU.h"
#include "GPIO.h"
#include "util/delay.h"
#include "lcd.h"
/*******************************************************************************
*                                                                              *
*                              Global Variables                                *
*                                                                              *
********************************************************************************/
/*Variable to hold number of edges*/
static volatile uint8 g_edges_count = 0;

/*Variable to hold Pulse Width*/
 uint16 g_TON = 0;
/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       Ultrasonic_Init
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the ICU Driver
*                     Setup the ICU Call back function
*                     Setup direction for the trigger pin as output pin
********************************************************************************/
void Ultrasonic_Init(const ICU_ConfigType * Config_Ptr)
{
	/*Initialize the ICU Driver*/
	ICU_Init(Config_Ptr);

	/*Setup the ICU Call back function*/
    ICU_setCallBack(Ultrasonic_edgeProcessing);

    /*Setup direction for the trigger pin as output pin*/
    GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}
/*******************************************************************************
* Service Name:       Ultrasonic_Trigger
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Send the trigger pulse to the ultrasonic
********************************************************************************/
void Ultrasonic_Trigger(void)
{
   GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
   _delay_us(50);
   GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}
/*******************************************************************************
* Service Name:       Ultrasonic_Trigger
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   the measured distance in cm
* Return value:       uint16
* Description:        Send the trigger pulse by using Ultrasonic_Trigger Func
*                     Start the measurements by the ICU from this moment.
********************************************************************************/
uint16 Ultrasonic_readDistance(void)
{
	/*Variable to hold distance*/
	uint16 distance = 0;

	/*Send the trigger pulse by using Ultrasonic_Trigger Function*/
	Ultrasonic_Trigger();

	/*Start the measurements by the ICU from this moment*/
	while ( g_edges_count != 2);

	distance = (g_TON * 0.017);

	/*Reset edges count*/
	 g_edges_count = 0;


    return distance;
}
/*******************************************************************************
* Service Name:       Ultrasonic_Trigger
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        This is the Call Back Function Called by ICU driver
*                     It's used to calculate the high time (Pulse time) generated
*                     by the ultrasonic sensor.
********************************************************************************/
void Ultrasonic_edgeProcessing(void)
{
	/*Increament number of counts*/
	g_edges_count ++;

    /*First rising edge*/
	if(g_edges_count == 1)
	{
		/*start measurement from first rising edge*/
		ICU_clearTimerValue();

		/*Detect Falling Edge*/
		ICU_EdgeDetectionType(Falling_Edge);
	}
	/*First falling edge*/
	else if ( g_edges_count == 2)
	{
		/*Saving High Time*/
        g_TON = ICU_getInputCaptureValue();

        /* Clear the timer counter register to start measurements again */
        ICU_clearTimerValue();

        /* Detect rising edge */
        ICU_EdgeDetectionType(Rising_Edge);


	}
}

