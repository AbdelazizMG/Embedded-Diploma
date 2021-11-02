/******************************************************************************
*  Module:    SPI
*  File name: SPI.h
*  Created on: Oct 12, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

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
* Name: ON_OFF
* Type: Enumeration
* Range: SPI_Disabled - SPI_Enabled
* Description: Data Type for symbolic name for SPI ON_OFF Mode
********************************************************************************/
typedef enum
{
	SPI_Disabled,
	SPI_Enabled
}Activiation_Mode;
/*******************************************************************************
* Name: Interrupt_Mode
* Type: Enumeration
* Range: Interrupt_Disabled - Interrupt_Enabled
* Description: Data Type for symbolic name for SPI Interrupt Mode
********************************************************************************/
typedef enum
{
	Interrupt_Disabled,
	Interrupt_Enabled
}Interrupt_Mode;
/*******************************************************************************
* Name: Data_Order
* Type: Enumeration
* Range: MSB_First - LSB_First
* Description: Data Type for symbolic name for SPI Data Order
********************************************************************************/
typedef enum
{
	MSB_First,
	LSB_First
}Data_Order;
/*******************************************************************************
* Name: Master_Slave_Select
* Type: Enumeration
* Range: Slave_Mode - Master_Mode
* Description: Data Type for symbolic name for SPI Master-Slave Select
********************************************************************************/
typedef enum
{
	Slave_Mode,
	Master_Mode
}Master_Slave_Select;
/*******************************************************************************
* Name: Clock_Polarity
* Type: Enumeration
* Range: Rising_Edge - Falling_Edge
* Description: Data Type for symbolic name for SPI Clock Polarity
*
*              if Rising: that means that clock starts from logic zero and the
*              leading edge is the rising edge , falling is the trailing edge
*
*              if Falling: that means that clock starts from logic one and the
*              leading edge is the falling edge, rising is the trailing edge.
********************************************************************************/
typedef enum
{
	Rising_Edge,
	Falling_Edge
}Clock_Polarity;
/*******************************************************************************
* Name: Clock_Phase
* Type: Enumeration
* Range: Leading_Edge - Trailing_Edge
* Description: Data Type for symbolic name for SPI Clock Phase
*
*              if Leading: that means that data sample on leading clock edge
*              which is dependent on the Clock Polarity Above
*
*              if Trailing:that means that data sample on trailing clock edge
*              which is dependent on the Clock Polarity Above
********************************************************************************/
typedef enum
{
	Leading_Edge,
	Trailing_Edge
}Clock_Phase;
/*******************************************************************************
* Name: Clock_Rate
* Type: Enumeration
* Range: divided_By_2 : divided_By_128
* Description: Data Type for symbolic name for SPI Clock Rate Select
********************************************************************************/
typedef enum
{
	divided_By_4,
	divided_By_16,
	divided_By_64,
	divided_By_128,
	divided_By_2,
	divided_By_8,
	divided_By_32,
}Clock_Rate;
/*******************************************************************************
* Name: SPI_ConfigType
* Type: Structure
* Range: Hardware dependent structure
* Description: Type of the external data structure containing the initialization
*              data for this module. This is the one that is sent to the init
*              function.
********************************************************************************/
typedef struct
{
   Activiation_Mode activiation_mode;
   Interrupt_Mode interrupt_mode;
   Data_Order data_order;
   Master_Slave_Select master_slave_select;
   Clock_Polarity clock_polarity;
   Clock_Phase clock_phase;
   Clock_Rate clock_rate;
}SPI_ConfigType;
/*******************************************************************************
*                                                                              *
*                                  FUNCTIONS PROTOTYPE                         *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       SPI_initMaster
* Sync/Async:         Synchronous
* Reentrancy:         Non-Reentrant
* Parameters (in):    configurations - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the SPI module's Master.
********************************************************************************/
void SPI_initMaster(const SPI_ConfigType * Config_Ptr);
/*******************************************************************************
* Service Name:       SPI_initSlave
* Sync/Async:         Synchronous
* Reentrancy:         Non-Reentrant
* Parameters (in):    configurations - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initialize the SPI module's Slave.
********************************************************************************/
void SPI_initSlave(const SPI_ConfigType * Config_Ptr);
/*******************************************************************************
* Service Name:       sendReceiveByte
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    data to be sent
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Send 1-Byte Data to a slave and receive a feedback from it.
********************************************************************************/
uint8 SPI_sendReceiveByte(uint8 data);
/*******************************************************************************
* Service Name:       SPI_sendString
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    String to be sent
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Send a String to other devices.
********************************************************************************/
void SPI_sendString( const uint8 * Str);
/*******************************************************************************
* Service Name:       SPI_receiveString
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       uint8
* Description:        receive a string from other devices
********************************************************************************/
void SPI_receiveString (uint8 *Str);

#endif /* SPI_H_ */
