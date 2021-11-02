/******************************************************************************
*  Module:    UART
*  File name: UART.h
*  Created on: Oct 14, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "ICU.h"
#include "gpio.h"
#include "avr/io.h"
#include "common_macros.h"
#include "LCD.h"
#include "avr/interrupt.h"
/*******************************************************************************
*                                                                              *
*                                  GLOBAL VARIABLES                            *
*                                                                              *
********************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void)=NULL_PTR;

/*******************************************************************************
*                                                                              *
*                              Interrupt Service Routines                      *
*                                                                              *
********************************************************************************/
ISR(TIMER1_CAPT_vect)
{

	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       ICU_Init
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the ICU mode.
********************************************************************************/
void ICU_Init(const ICU_ConfigType * Config_Ptr)
{


	/*ICP as input pin*/
	GPIO_setupPinDirection(PORTD_ID, PIN6_ID, PIN_INPUT);

    /*Non-PWM-Mode*/
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);

	/*Normal Mode*/
	/*BITS ARE ALREADY CLEARED*/

	/*Input Noise Canceler*/
	switch(Config_Ptr ->noise_caneler)
	{
	case Noise_Canceler_Disabled: CLEAR_BIT(TCCR1B,ICNC1);

	                              break;
	case Noise_Canceler_Enabled:  SET_BIT(TCCR1B,ICNC1);
	                              break;
	}
	/*Input Edge Select*/
	switch(Config_Ptr ->edge_select)
	{
	  case Falling_Edge:  CLEAR_BIT(TCCR1B,ICES1);
	                      break;
	  case Rising_Edge:   SET_BIT(TCCR1B,ICES1);
	                      break;
	}
	/*Clock Select*/
	switch(Config_Ptr->clock_select)
	{
	case No_Clock:       CLEAR_BIT(TCCR1B,CS10);
	                     CLEAR_BIT(TCCR1B,CS11);
	                     CLEAR_BIT(TCCR1B,CS12);
	                     break;
	case Divide_By_1:    SET_BIT(TCCR1B,CS10);
	                     CLEAR_BIT(TCCR1B,CS11);
	                     CLEAR_BIT(TCCR1B,CS12);
	                     break;
	case Divide_By_8:    CLEAR_BIT(TCCR1B,CS10);
	                     SET_BIT(TCCR1B,CS11);
	                     CLEAR_BIT(TCCR1B,CS12);
	                     break;
	case Divide_By_64:   SET_BIT(TCCR1B,CS10);
	                     SET_BIT(TCCR1B,CS11);
	                     CLEAR_BIT(TCCR1B,CS12);
	                     break;
	case Divide_By_256:  CLEAR_BIT(TCCR1B,CS10);
	                     CLEAR_BIT(TCCR1B,CS11);
	                     SET_BIT(TCCR1B,CS12);
	                     break;
	case Divide_By_1024: SET_BIT(TCCR1B,CS10);
	                     CLEAR_BIT(TCCR1B,CS11);
	                     SET_BIT(TCCR1B,CS12);
                         break;
	case External_Falling_Edge: CLEAR_BIT(TCCR1B,CS10);
	                            SET_BIT(TCCR1B,CS11);
	                            SET_BIT(TCCR1B,CS12);
                                break;
	case External_Rising_Edge:  SET_BIT(TCCR1B,CS10);
	                            SET_BIT(TCCR1B,CS11);
	                            SET_BIT(TCCR1B,CS12);
                                break;
	}
	/*Initial Values*/
	TCNT1 = 0;
	ICR1  = 0;

	/*Input Capture Interrupt Enable*/
    SET_BIT(TIMSK,TICIE1);


}
/*******************************************************************************
* Service Name:       ICU_setCallBack
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Call Back TIMER1 Function.
********************************************************************************/
void ICU_setCallBack( void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
/*******************************************************************************
* Service Name:       ICU_EdgeDetectionType
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Change the Edge Detection Type.
********************************************************************************/
void ICU_EdgeDetectionType(const Edge_Select edge_select)
{
	switch(edge_select)
	{
	  case Falling_Edge:  CLEAR_BIT(TCCR1B,ICES1);
	                      break;
	  case Rising_Edge:   SET_BIT(TCCR1B,ICES1);
	                      break;
	}
}
/*******************************************************************************
* Service Name:       ICU_getInputCaptureValue
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       uint16
* Description:        Save TIMER1 value when Input is captured in ICR Register.
********************************************************************************/
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}
/*******************************************************************************
* Service Name:       ICU_clearTimerValue
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Clear Timer1 Value to start from 0.
********************************************************************************/
void ICU_clearTimerValue(void)
{
	TCNT1=0;
}
/*******************************************************************************
* Service Name:       ICU_deInit
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        DeInit ICU Driver by Disabling TIMER1.
********************************************************************************/
void ICU_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1=0;
    ICR1=0;

	/*Disable Input Capture Interrupt*/
	CLEAR_BIT(TIMSK,TICIE1);
}
