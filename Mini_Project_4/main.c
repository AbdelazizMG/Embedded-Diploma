/******************************************************************************
*  Module:    ICU
*  File name: ICU.h
*  Created on: Oct 14, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "ICU.h"
#include "Ultrasonic.h"
#include "lcd.h"
#include "avr/io.h"
#include "common_macros.h"

int main (void)
{
	/*variable to hold distance*/
	uint16 distance = 0;

	ICU_ConfigType Config_Struct = {Noise_Canceler_Disabled,Rising_Edge,Divide_By_8};

	/*Enable I-Bit*/
	SET_BIT(SREG,7);

    Ultrasonic_Init(&Config_Struct);

    LCD_init();

    LCD_displayString("Distance: ");


	while (1)
	{
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		if(distance<10) /* 0 : 9*/
		{
			LCD_displayString("  ");
		}
		else if(distance < 100 && distance > 9) /*10:99*/
		{
			LCD_displayString(" ");
		}

		LCD_moveCursor(0, 13);
		LCD_displayString(" cm");
	}
}
