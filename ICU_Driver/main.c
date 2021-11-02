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
#include "lcd.h"
#include "gpio.h"
#include "common_macros.h"
#include "ICU.h"
#include "avr/io.h"
#include "avr/interrupt.h"
/*******************************************************************************
*                                                                              *
*                                  Global Variables                            *
*                                                                              *
********************************************************************************/
 uint8 g_edges_count = 0;
 uint16 g_TON = 0;
 uint16 g_Period = 0;
 uint16 g_Period_Plus_TON = 0;

void APP_edgeProcessing(void)
{
	g_edges_count ++;

	/*First rising edge*/
	if (g_edges_count == 1)
	{
		/*Clear Timer Value to start counting from it*/
		ICU_clearTimerValue();

		/*Set Falling Edge*/
		ICU_EdgeDetectionType(Falling_Edge);
	}
	/*First Falling edge*/
	else if ( g_edges_count ==  2)
	{
		 /*Saving Pulse TON*/
         g_TON = ICU_getInputCaptureValue();

 		/*Set Rising Edge*/
 		ICU_EdgeDetectionType(Rising_Edge);
	}
	/*Second Rising Edge*/
	else if ( g_edges_count == 3)
	{
		/*Getting Period*/
		g_Period = ICU_getInputCaptureValue();

		/*Set Falling Edge*/
		ICU_EdgeDetectionType(Falling_Edge);
	}
	/*Second Falling Edge*/
	else if (g_edges_count == 4 )
	{
        /*Getting Period plus High Time*/
		g_Period_Plus_TON = ICU_getInputCaptureValue();

		/*Reset Timer Value*/
		ICU_clearTimerValue();

 		/*Set Rising Edge*/
 		ICU_EdgeDetectionType(Rising_Edge);
	}
}


int main (void)
{
	/*Variable to hold duty cycle*/
	uint8 duty_cycle = 0;

	/*Variable to hold period*/
	uint8 period = 0;

	/*Config struct*/
	ICU_ConfigType Config_Struct = { Noise_Canceler_Disabled , Rising_Edge, Divide_By_1};


	/*I-Bit*/
	SET_BIT(SREG,7);

	/*setCallBack Function*/
	ICU_setCallBack(APP_edgeProcessing);

	/*Init LCD*/
	LCD_init();

	/*Init ICU Module*/
	ICU_Init( & Config_Struct);


	while (1)
	{
		if (g_edges_count == 4 )
		{
			ICU_deInit();
			g_edges_count=0;
			LCD_displayString("Duty = ");
            duty_cycle = ( (float) (g_Period_Plus_TON - g_Period ) / (g_Period_Plus_TON - g_TON) ) * 100 ;
            LCD_intgerToString(duty_cycle);
            LCD_displayCharacter('%');
            period = (g_Period_Plus_TON - g_TON)/1000;
            LCD_moveCursor(1, 0);
            LCD_displayString("Period = ");
            LCD_intgerToString(period);
            LCD_displayString(" ms");

		}
	}
}


