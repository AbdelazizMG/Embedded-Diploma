/******************************************************************************
*  Module: PWM
*  File name: PWM.h
*  Created on: Oct 9, 2021
*  Author: Abdelaziz Mohammad
******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "std_types.h"
/*******************************************************************************
*                                                                              *
*                             FUNCTIONS PROTOTYPE                              *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       PWM_Timer0_Start
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Duty Cycle
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize Timer0 and Rotating DC Motor with a defined speed
********************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
