/******************************************************************************
*  Module:    UART
*  File name: UART.h
*  Created on: Oct 10, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "UART.h"
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"
#include "lcd.h"
#include "avr/io.h"
/*******************************************************************************
*                                                                              *
*                                  MAIN FUNCTION                               *
*                                                                              *
********************************************************************************/



int main (void)
{


   uint8 key = 'a';

	/*Configuration Structure*/
	UART_ConfigType UART_Config_Struct =
	{       Transmitter_Receiver,
			Double_Speed,
			Asynchronous,
			Parity_Disabled,
			StopBit_1,
			DataFrame_8Bits,
			BaudRate_9600,
			RX_InterruptDisable,
			TX_InterruptDisable
	};

	/*LED Init*/
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);

	LCD_init();
	UART_Init(&UART_Config_Struct);

	/*Enable I-Bit*/
	SET_BIT(SREG,7);


	while(1)
	{



		key = UART_receiveByte();

	    LCD_displayCharacter(key);


	     if ( key == 'b')
	     {
	     	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
	     }
	     else
	     {
	     	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	     }





/*
		UART_sendByte(8);
*/




	}

	return 0;
}

