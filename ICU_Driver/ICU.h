/******************************************************************************
*  Module:    UART
*  File name: UART.h
*  Created on: Oct 14, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

#ifndef ICU_H_
#define ICU_H_

/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "std_types.h"


/*******************************************************************************
*                                                                              *
*                             User-Defined Data Types                          *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Name: Noise_Canceler
* Type: Enumeration
* Range: Noise_Canceler_Disabled - Noise_Canceler_Enabled
* Description: Data Type for symbolic name for ICU Noise Canceler
********************************************************************************/
typedef enum
{
	Noise_Canceler_Disabled,
	Noise_Canceler_Enabled
}Noise_Canceler;
/*******************************************************************************
* Name: Edge_Select
* Type: Enumeration
* Range: Falling_Edge - Rising_Edge
* Description: Data Type for symbolic name for ICU Edge Select
********************************************************************************/
typedef enum
{
	Falling_Edge,
	Rising_Edge
}Edge_Select;
/*******************************************************************************
* Name: Clock_Select
* Type: Enumeration
* Range: No_Clock : External_Rising_Edge
* Description: Data Type for symbolic name for ICU Clock_Select
********************************************************************************/
typedef enum
{
	No_Clock,
	Divide_By_1,
	Divide_By_8,
	Divide_By_64,
	Divide_By_256,
	Divide_By_1024,
	External_Falling_Edge,
	External_Rising_Edge
}Clock_Select;
/*******************************************************************************
* Name: ICU_ConfigType
* Type: Structure
* Range: Hardware dependent structure
* Description: Type of the external data structure containing the initialization
*              data for this module. This is the one that is sent to the init
*              function.
********************************************************************************/
typedef struct
{
     Noise_Canceler noise_caneler;
     Edge_Select edge_select;
     Clock_Select clock_select;
}ICU_ConfigType;
/*******************************************************************************
*                                                                              *
*                                  FUNCTIONS PROTOTYPE                         *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       ICU_Init
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the ICU mode.
********************************************************************************/
void ICU_Init(const ICU_ConfigType * Config_Ptr);
/*******************************************************************************
* Service Name:       ICU_setCallBack
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Call Back TIMER1 Function.
********************************************************************************/
void ICU_setCallBack(void(*a_ptr)(void));
/*******************************************************************************
* Service Name:       ICU_EdgeDetectionType
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Change the Edge Detection Type.
********************************************************************************/
void ICU_EdgeDetectionType(const Edge_Select edge_select);
/*******************************************************************************
* Service Name:       ICU_getInputCaptureValue
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       uint16
* Description:        Save TIMER1 value when Input is captured in ICR Register.
********************************************************************************/
uint16 ICU_getInputCaptureValue(void);
/*******************************************************************************
* Service Name:       ICU_clearTimerValue
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Clear Timer1 Value to start from 0.
********************************************************************************/
void ICU_clearTimerValue(void);
/*******************************************************************************
* Service Name:       ICU_deInit
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        DeInit ICU Driver by Disabling TIMER1.
********************************************************************************/
void ICU_deInit(void);

#endif /* ICU_H_ */
