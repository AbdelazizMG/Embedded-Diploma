/******************************************************************************
*  Module:    ADC
*  File name: ADC.c
*  Created on: Oct 9, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "ADC.h"
#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"
#include "gpio.h"


/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       ADC_Init
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    configurations - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the ADC module.
********************************************************************************/
void ADC_Init(const ADC_ConfigType * Config_Ptr)
{

	/*Checking Voltage Reference Value*/
	switch ( Config_Ptr ->ref_volt)
	{
	  case AREF:      CLEAR_BIT(ADMUX,REFS0);
	                  CLEAR_BIT(ADMUX,REFS1);
	                  break;
	  case AVCC:      SET_BIT(ADMUX,REFS0);
                      CLEAR_BIT(ADMUX,REFS1);
                      break;
	  case Internal:  SET_BIT(ADMUX,REFS0);
                      SET_BIT(ADMUX,REFS1);
                      break;
	  default:        break;
	}

	/*Check the Prescaler Value*/
    switch ( Config_Ptr ->prescaler )
    {
           case Prescaler_2:   CLEAR_BIT(ADCSRA,ADPS0);
                               CLEAR_BIT(ADCSRA,ADPS1);
                               CLEAR_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_4:   CLEAR_BIT(ADCSRA,ADPS0);
                               SET_BIT(ADCSRA,ADPS1);
                               CLEAR_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_8:   SET_BIT(ADCSRA,ADPS0);
                               SET_BIT(ADCSRA,ADPS1);
                               CLEAR_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_16:  CLEAR_BIT(ADCSRA,ADPS0);
                               CLEAR_BIT(ADCSRA,ADPS1);
                               SET_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_32:  SET_BIT(ADCSRA,ADPS0);
                               CLEAR_BIT(ADCSRA,ADPS1);
                               SET_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_64:  CLEAR_BIT(ADCSRA,ADPS0);
                               SET_BIT(ADCSRA,ADPS1);
                               SET_BIT(ADCSRA,ADPS2);
                               break;
           case Prescaler_128: SET_BIT(ADCSRA,ADPS0);
                               SET_BIT(ADCSRA,ADPS1);
                               SET_BIT(ADCSRA,ADPS2);
                               break;
    }

   /*Enable ADC*/
   SET_BIT(ADCSRA,ADEN);


}
/*******************************************************************************
* Service Name:       ADC_readChannel
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Channel number
* Parameters (inout): None
* Parameters (out):   None
* Return value:       uint16
* Description:        Obtain the converted data from the ADC register
********************************************************************************/
uint16 ADC_readChannel(uint8 Channel)
{
	/*Choosing Channel*/
     ADMUX = (ADMUX & 0xE0 ) | Channel ;

     /*Start Conversion*/
     SET_BIT(ADCSRA,ADSC);

     /*Using Polling Method until conversion is done*/
     while ( ! CHECK_BIT(ADCSRA,ADIF) );

     /*Clearing the FLAG*/
     SET_BIT(ADCSRA,ADIF);

     /*Return the result*/
     return ADC;
}


