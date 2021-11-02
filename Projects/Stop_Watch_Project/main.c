/*
 * main.c
 *
 *  Created on: Sep 17, 2021
 *      Author: sigmaa
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "macros.h"

volatile unsigned short int seconds=0;
volatile unsigned short int minutes=0;
volatile unsigned short int hours=0;

void INT0_INIT(void)
{
	/*FALLING EDGE*/
	SetBit(MCUCR,ISC01);

	/*Interrupt enable request*/
	SetBit(GICR,INT0);

	/*Input PIN*/
	ClearBit(DDRD,PD2);

	/*Internal Pull UP*/
	SetBit(PORTD,PD2);

}

void INT1_INIT(void)
{
    /*RISING EDGE*/
	SetBit(MCUCR,ISC10);
	SetBit(MCUCR,ISC11);

	/*Interrupt enable request*/
	SetBit(GICR,INT1);

	/*Input PIN*/
	ClearBit(DDRD,PD3);

}

void INT2_INIT(void)
{
	/*Falling Edge*/
	SetBit(MCUCSR,ISC2);

	/*Interrupt enable request*/
	SetBit(GICR,INT2);

	/*Internal Pull UP*/
	SetBit(PORTB,PB2);

}

void TIMER1_INIT(void)
{
   /*NON PWM Mode*/
   SetBit(TCCR1A,FOC1A);

   /*CTC Mode - OCR1A is the TOP*/
   SetBit(TCCR1B,WGM12);

   /*Prescaler 1024*/
   SetBit(TCCR1B,CS10);
   SetBit(TCCR1B,CS12);

   /*Init Value*/
   TCNT1 = 0;

   /*TOP VALUE =  977*/
   OCR1A= 977;

   /*Interrupt Enable*/
   SetBit(TIMSK,OCIE1A);

   /*PORTC is output */
       DDRC = 0x0F;

   /*PORTC is initially off */
       PORTC= 0x00;
}


int main(void)
{
	/*Disable I-BIT*/
	ClearBit(SREG,7);

	/*Initiate Timer1*/
	TIMER1_INIT();

	/*Interrupt 0 Init*/
	INT0_INIT();

	/*Interrupt 1 Init*/
	INT1_INIT();

	/*Interrupt 2 Init*/
	INT2_INIT();

	/*Enable I-Bit*/
	SetBit(SREG,7);

	/*OUTPUT */
	DDRA = 0xFF;

    /*All inputs are Enabled*/
    PORTA = 0x7E;

    /*All are showing 0*/
    PORTC= 0x00;


	while(1)
	{

       PORTA= 0x40;
       PORTC= seconds % 10 ;
      _delay_ms(3);

       PORTA= 0x20;
       PORTC=(int short) (seconds / 10);
       _delay_ms(3);

       PORTA= 0x10;
       PORTC=minutes % 10;
       _delay_ms(3);

      PORTA= 0x08;
       PORTC=(int short) (minutes / 10);
       _delay_ms(3);

       PORTA= 0x04;
       PORTC= hours % 10;
       _delay_ms(3);

       PORTA= 0x02;
       PORTC= (int short)(hours /10);
       _delay_ms(3);

	}


}

ISR(TIMER1_COMPA_vect)
{
    _delay_ms(3);

    seconds++;

    if(seconds == 60)
    {
        minutes++;
    	seconds = 0;
    }
    if(minutes == 60)
    {
    	hours++;
    	minutes =0;
    }
}
ISR(INT0_vect)
{
	/*RESET*/
     seconds = minutes = hours = 0;
}
ISR(INT1_vect)
{
   /*STOP WATCH TIME PAUSE*/
	/*Interrupt Disable*/
	ClearBit(TIMSK,OCIE1A);
}
ISR(INT2_vect)
{
     /*STOP WATCH TIME RESUME*/
	/*Interrupt Enable*/
	SetBit(TIMSK,OCIE1A);
}
