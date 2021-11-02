/*
 ============================================================================
 Name        : GPIO_Exercise.c
 Author      : Abdelaziz Mohammad
 Description : Test the GPIO Driver
 Date        : 23/9/2021
 ============================================================================
 */

#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h> /* To use the delay functions */

int main(void)
{
	GPIO_setupPinDirection(PORTD_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID,PIN3_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTA_ID,PIN4_ID,PIN_INPUT);

	while(1)
	{

      if ( GPIO_readPin(PORTA_ID,PIN3_ID) )
      {
    	  GPIO_writePin(PORTD_ID,PIN0_ID,LOGIC_HIGH);
      }
      else if ( GPIO_readPin(PORTA_ID,PIN4_ID) )
      {
    	  GPIO_writePin(PORTD_ID,PIN0_ID,LOGIC_LOW);
      }

	}
}


