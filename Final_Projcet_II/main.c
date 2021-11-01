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
#include "UART.h"
#include "DC_Motor.h"
#include "Buzzer.h"
#include "gpio.h"
#include "Timers.h"
#include "common_macros.h"
#include "avr/io.h"
#include "Operations_II.h"


extern uint16 g_Interrupts_number;


int main (void)
{

	  /*Configuration Structure*/
	 UART_ConfigType UART_Config_Struct =
	 {
			 Transmitter_Receiver,
			 Double_Speed,
			 Asynchronous, Parity_Disabled,
			 StopBit_1,
			 DataFrame_8Bits,
			 BaudRate_9600
	 };
	 /*Config Struct*/
	 TIMER_ConfigType TIMER_Config_Struct =
	 {
			 Timer_2 ,
			 CTC,
			 Timer2_FCPU_1024,
			 OF_Interrupt_Disable,
			 OTC_Interrupt_Enable,
			 OCPin_Disconnected,
			 0,   /*TCNT*/
			 254, /*OCR*/
	 };




	    /*Init Buzzer*/
	    BUZZER_init(PORTC_ID, PIN0_ID);

	    /*DC - Motor Init*/
	    DC_MOTOR_Init();



	    /*UART Init*/
	    UART_Init(&UART_Config_Struct);


	    /*Enable I-Bit*/
	    SET_BIT(SREG,7);


	while (1)
	{

		OPERATIONS_II_UART_HANDLE(&TIMER_Config_Struct);


	}

}


