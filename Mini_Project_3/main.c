/*************************************************************
* File name: main.c
* Created on: Oct 9, 2021
* Author: Abdelaziz Mohammad
*************************************************************/


#include "lcd.h"
#include "ADC.h"
#include "util/delay.h"
#include "LM35.h"
#include "gpio.h"
#include "DC_Motor.h"
#include "PWM.h"


int main(void)
{
	/*Variable to hold Temp sensor read to display it on LCD*/
	uint16 read= 0 ;

	/*ADC Configuration Structure*/
	ADC_ConfigType Config_struct = { Internal, Prescaler_8 };

	/*Initializations*/
	LCD_init();
	ADC_Init(& Config_struct);
	DC_MOTOR_Init();


    /*Initial Display for LCD*/
	LCD_moveCursor(0,4);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,4);
	LCD_displayString("TEMP = ");



	while(1)
	{
	   /*read temp sensor value*/
       read= LM35_getTemp(2);

       /*To Update Temp Value Display at the same place every time it's updated*/
       LCD_moveCursor(1,11);

       /*Display Value on LCD*/
       LCD_intgerToString(read);

       /*Space for numbers greater than 99*/
       LCD_displayCharacter(' ');


       if(read < 30 )
       {
    	   /*Trun of the fan*/
           DC_MOTOR_Rotate(Stop,0);
    	   LCD_moveCursor(0,11);
    	   LCD_displayString("OFF");
       }
       else if ( read >= 30 && read < 60)
       {
    	   /*Turn on the fan with 25% of its speed*/
    	   DC_MOTOR_Rotate(CW,25);
    	   LCD_moveCursor(0,11);
    	   LCD_displayString("ON");
    	   LCD_displayCharacter(' ');
       }
       else if ( read >= 60 && read < 90)
       {
    	   /*Turn on the fan with 50% of its speed*/
    	   DC_MOTOR_Rotate(CW,50);
    	   LCD_moveCursor(0,11);
    	   LCD_displayString("ON");
    	   LCD_displayCharacter(' ');
       }
       else if ( read >= 90 && read < 120 )
       {
    	   /*Turn on the fan with 75% of its speed*/
    	   DC_MOTOR_Rotate(CW,75);
    	   LCD_moveCursor(0,11);
    	   LCD_displayString("ON");
    	   LCD_displayCharacter(' ');
       }
       else if ( read >= 120)
       {
    	   /*Turn on the fan with 100% of its speed*/
    	   DC_MOTOR_Rotate(CW,100);
    	   LCD_moveCursor(0,11);
    	   LCD_displayString("ON");
    	   LCD_displayCharacter(' ');
       }
	}
	return 0 ;
}

