/******************************************************************************
*  Module:    ADC
*  File name: ADC.c
*  Created on: Oct 9, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "std_types.h"

/*******************************************************************************
*                                                                              *
*                                  DEFINTIONS                                  *
*                                                                              *
********************************************************************************/

#define ADC_REF_VOLT   2.56
#define ADC_MAX_VALUE 1023


/*******************************************************************************
*                                                                              *
*                             User-Defined Data Types                          *
*                                                                              *
********************************************************************************/

/*******************************************************************************
* Name: ADC_ReferenceVoltage
* Type: Enumeration
* Range: AREF
*        AVCC
*        Internal
* Description: Data Type for symbolic name for ADC Voltage Reference
********************************************************************************/
typedef enum
{
	AREF,
	AVCC,
	Internal=3
}ADC_ReferenceVoltage;
/*******************************************************************************
* Name: ADC_Prescaler
* Type: Enumeration
* Range: Prescaler_2 - Prescaler_128
* Description: Data Type for symbolic name for ADC Prescaler
********************************************************************************/
typedef enum
{
	Prescaler_2=1,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128
}ADC_Prescaler;
/*******************************************************************************
* Name: ADC_ConfigType
* Type: Structure
* Range: Hardware dependent structure
* Description : Type of the external data structure containing the initialization
*               data for this module. This is the one that is sent to the init
*               function.
********************************************************************************/
typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
*                                                                              *
*                                  FUNCTIONS PROTOTYPE                         *
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
void ADC_Init( const ADC_ConfigType * Config_Ptr);
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
uint16 ADC_readChannel(uint8 Channel);


#endif /* ADC_H_ */
