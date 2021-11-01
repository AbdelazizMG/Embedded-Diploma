/******************************************************************************
*  Module:    Operations_II
*  File name: Operations_II.h
*  Created on: Oct 26, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

#ifndef OPERATIONS_II_H_
#define OPERATIONS_II_H_

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "Timers.h"
extern TIMER_ConfigType TIMER_Config_Struct;

/*******************************************************************************
*                                                                              *
*                              FUNCTIONS PROTOTYPE                             *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       Motor
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in the ISR
********************************************************************************/
void OPERATIONS_II_Motor (void);
/*******************************************************************************
* Service Name:       OPERATIONS_II_Buzzer
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in the ISR
********************************************************************************/
void OPERATIONS_II_Buzzer (void);
/*******************************************************************************
* Service Name:       OPERATIONS_II_UART_HANDLE
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function to be called in main function to handle UART
*                     input from first MCU.
********************************************************************************/
void OPERATIONS_II_UART_HANDLE (const TIMER_ConfigType * TIMER_Config_STRUCT);







#endif /* OPERATIONS_II_H_ */
