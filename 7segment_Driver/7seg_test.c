/*
 *       7seg_test.c
 *      Created on: Oct 9, 2021
 *      Author: Abdelaziz Mohammad
 *
 */

#include "seven_seg.h"
#include "gpio.h"
#include "util/delay.h"

int main (void)
{
	_7seg_Setup(PORTB_ID,PIN3_ID);

	while(1)
	{
		for( uint8 counter = 0 ; counter <=9 ; counter ++  )
		{
			_7seg_Write(counter);
			_delay_ms(1000);
		}

	}
	return 0 ;
}
