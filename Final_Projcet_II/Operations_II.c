/******************************************************************************
*  Module:    Operations_II
*  File name: Operations_II.h
*  Created on: Oct 26, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "Operations_II.h"
#include "PWM.h"
#include "DC_Motor.h"
#include "Buzzer.h"
#include "Timers.h"
#include "UART.h"
#include "avr/io.h"
#include "I2C.h"
#include "external_eeprom.h"
/*******************************************************************************
*                                                                              *
*                                  Global Variables                            *
*                                                                              *
********************************************************************************/
uint16 g_Interrupts_number = 0;
/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       OPERATIONS_II_Motor
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in the ISR
********************************************************************************/
void OPERATIONS_II_Motor (void)
{
	/*Variable To Hold interrupt number*/
	static uint16 counter = 0 ;

	/*Variable to detect which direction the motor is rotating at*
	 * 0 CW - 1 CCW */
	static uint8 flag = 0;

	counter ++ ;

	/*for 5 seconds*/
	if(counter == g_Interrupts_number && g_Interrupts_number == 461 && flag ==0)
	{
		DC_MOTOR_Rotate(Stop, 0);
		counter = 0;
		/*Get ready for holding motor 3 seconds*/
		g_Interrupts_number = 92;
		flag = 1;
	}
	else if (counter == g_Interrupts_number && g_Interrupts_number == 92 )
	{
		/*after holding motor for 3 seconds , rotate CCW for 5 seconds*/
		DC_MOTOR_Rotate(CCW, 75);
		g_Interrupts_number = 215;
		counter = 0;
	}
	else if (counter == g_Interrupts_number && g_Interrupts_number == 215 )
	{
		/*after 5 seconds stop the motor and display finished*/
		DC_MOTOR_Rotate(Stop, 0);
		flag = 0 ;
		counter = 0;
		Timer_Deinit(2);
	}
}
/*******************************************************************************
* Service Name:       OPERATIONS_II_Buzzer
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in the ISR
********************************************************************************/
void OPERATIONS_II_Buzzer (void)
{
   static uint16 counter = 0 ;

   counter ++ ;

   if(counter == g_Interrupts_number && g_Interrupts_number == 215 )
   {
       BUZZER_OFF();
       counter = 0 ;
   }
}
/*******************************************************************************
* Service Name:       OPERATIONS_II_UART_HANDLE
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in main function to handle UART
*                     input from first MCU.
********************************************************************************/
void OPERATIONS_II_UART_HANDLE(const TIMER_ConfigType * TIMER_Config_STRUCT)
{
    /*Variable to hold UART Received PINS*/
    uint8 key;

    /*Take Flag from other MCU*/
	key = UART_receiveByte();

	/*Check Flag VAlue*/
	if(key == 'b')
	{

	    DC_MOTOR_Rotate(CW, 75);
	    Timer_init(TIMER_Config_STRUCT);
	    Timer2_setCallBack(OPERATIONS_II_Motor);
	    g_Interrupts_number= 461;
	    key='a';
	}
	else if ( key == 'a')
	{
		BUZZER_ON();
		Timer_init(TIMER_Config_STRUCT);
		Timer2_setCallBack(OPERATIONS_II_Buzzer);
		g_Interrupts_number= 215;
		key = 'a';
	}
	/*indicates that the following password is to be saved in EEPROM*/
	else if ( key == 'e' )
	{
		/*counter to be used in loop*/
        uint8 counter = 0;
        /*Variable to hold received passowrd digit*/
        uint8 value= 0;
        while (counter < 5 )
        {
        	/*Receive digit from first MCU*/
        	value = UART_receiveByte();

        	/*Save the digit in EEPROM*/
        	EEPROM_writeByte(0x0000 + counter, value);

        	/*counter increament*/
        	counter ++ ;
        }

	}
}

