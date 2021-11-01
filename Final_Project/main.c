/******************************************************************************
*  Module:    main
*  File name: main.c
*  Created on: Oct 25, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#define F_CPU 8000000
#include "Buzzer.h"
#include "gpio.h"
#include "Timers.h"
#include "lcd.h"
#include "keypad.h"
#include "UART.h"
#include "Operations.h"
#include "util/delay.h"
#include "avr/interrupt.h"



int main (void)
{

	const UART_ConfigType UART_ConfigStruct =
	{
			Transmitter_Receiver,
			Double_Speed,
			Asynchronous,
			Parity_Disabled,
			StopBit_1,
			DataFrame_8Bits,
			BaudRate_9600
	};

	/*LCD init*/
	LCD_init();

	/*UART_Init*/
    UART_Init(&UART_ConfigStruct);

    OPERATION_EnterPassword();
    OPERATION_reEnterPassword();
    OPERATION_checkPasswordMatch();

	while(1)
	{



	}


	return 0 ;
}
