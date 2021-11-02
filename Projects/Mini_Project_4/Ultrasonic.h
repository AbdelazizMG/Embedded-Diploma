/******************************************************************************
*  Module:    Ultrasonic
*  File name: Ultrasonic.h
*  Created on: Oct 15, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "std_types.h"
#include "ICU.h"
/*******************************************************************************
*                                                                              *
*                                  FUNCTIONS PROTOTYPE                         *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       Ultrasonic_Init
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the ICU Driver
*                     Setup the ICU Call back function
*                     Setup direction for the trigger pin as output pin
********************************************************************************/
void Ultrasonic_Init(const ICU_ConfigType * Config_Ptr);
/*******************************************************************************
* Service Name:       Ultrasonic_Trigger
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Send the trigger pulse to the ultrasonic
********************************************************************************/
void Ultrasonic_Trigger(void);
/*******************************************************************************
* Service Name:       Ultrasonic_readDistance
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   the measured distance in cm
* Return value:       uint16
* Description:        Send the trigger pulse by using Ultrasonic_Trigger Func
*                     Start the measurements by the ICU from this moment.
********************************************************************************/
uint16 Ultrasonic_readDistance(void);
/*******************************************************************************
* Service Name:       Ultrasonic_Trigger
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        This is the Call Back Function Called by ICU driver
*                     It's used to calculate the high time (Pulse time) generated
*                     by the ultrasonic sensor.
********************************************************************************/
void Ultrasonic_edgeProcessing(void);






#endif /* ULTRASONIC_H_ */
