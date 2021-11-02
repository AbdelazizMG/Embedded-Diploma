/******************************************************************************
*  Module:    LM35 Temp Sensor
*  File name: LM35.c
*  Created on: Oct 9, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "LM35.h"
#include "ADC.h"
/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
uint16 LM35_getTemp(uint8 Channel)
{
   /*Variable to Hold Temperature value*/
   uint16 temp = 0;

   /*Variable to Hold ADC read value*/
   uint16 adc = 0;

   /*Reading ADC using ADC_readChannel Function*/
   adc = ADC_readChannel(Channel);

   /*Mathematical Equation to convert ADC read into temperature value*/
   temp = (uint8) (( (uint32) adc * LM35_MAX_TEMP * ADC_REF_VOLT) / ( LM35_MAX_VOLT * ADC_MAX_VALUE ));

   /*return temp value obtained*/
   return temp;
}
