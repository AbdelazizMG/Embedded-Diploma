/******************************************************************************
*  Module:    SPI
*  File name: SPI.h
*  Created on: Oct 12, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#include "SPI.h"
#include "avr/io.h"
#include "common_macros.h"
#include "GPIO.h"
/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
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
void SPI_initMaster(const SPI_ConfigType * Config_Ptr)
{
	/******** Configure SPI Master Pins *********
		 * SS(PB4)   --> Output
		 * MOSI(PB5) --> Output
		 * MISO(PB6) --> Input
		 * SCK(PB7) --> Output
		 ********************************************/
		GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);

	switch( Config_Ptr ->activiation_mode)
	{
	case SPI_Disabled:  CLEAR_BIT(SPCR,SPE);
		                break;
	case SPI_Enabled:   SET_BIT(SPCR,SPE);
		                break;
	}
	switch( Config_Ptr ->interrupt_mode )
	{
	case Interrupt_Disabled:  CLEAR_BIT(SPCR,SPIE);
		                      break;
	case Interrupt_Enabled:   SET_BIT(SPCR,SPIE);
		                      break;
	}
	switch( Config_Ptr ->data_order )
	{
	case MSB_First:   CLEAR_BIT(SPCR,DORD);
		                      break;
	case LSB_First:   SET_BIT(SPCR,DORD);
		                      break;
	}

	   /*Set it as MASTER*/
	   SET_BIT(SPCR,MSTR);


	switch( Config_Ptr ->clock_polarity )
	{
	case Rising_Edge:    CLEAR_BIT(SPCR,CPOL);
		                      break;
	case Falling_Edge:   SET_BIT(SPCR,CPOL);
		                      break;
	}
	switch( Config_Ptr ->clock_phase )
	{
	case Leading_Edge:    CLEAR_BIT(SPCR,CPHA);
		                      break;
	case Trailing_Edge:   SET_BIT(SPCR,CPHA);
		                      break;
	}
	switch( Config_Ptr ->clock_rate )
	{
	case divided_By_4:    CLEAR_BIT(SPCR,SPR0);
	                      CLEAR_BIT(SPCR,SPR1);
	                      CLEAR_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_16:   SET_BIT(SPCR,SPR0);
	                      CLEAR_BIT(SPCR,SPR1);
	                      CLEAR_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_64:   CLEAR_BIT(SPCR,SPR0);
	                      SET_BIT(SPCR,SPR1);
	                      CLEAR_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_128:  SET_BIT(SPCR,SPR0);
	                      SET_BIT(SPCR,SPR1);
	                      CLEAR_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_2:    CLEAR_BIT(SPCR,SPR0);
	                      CLEAR_BIT(SPCR,SPR1);
	                      SET_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_8:    SET_BIT(SPCR,SPR0);
	                      CLEAR_BIT(SPCR,SPR1);
	                      SET_BIT(SPSR,SPI2X);
		                      break;
	case divided_By_32:   CLEAR_BIT(SPCR,SPR0);
	                      SET_BIT(SPCR,SPR1);
	                      SET_BIT(SPSR,SPI2X);
		                      break;


	}
}
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
void SPI_initSlave(const SPI_ConfigType * Config_Ptr)
{
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/
	GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);


	switch( Config_Ptr ->activiation_mode)
		{
		case SPI_Disabled:  CLEAR_BIT(SPCR,SPE);
			                break;
		case SPI_Enabled:   SET_BIT(SPCR,SPE);
			                break;
		}
		switch( Config_Ptr ->interrupt_mode )
		{
		case Interrupt_Disabled:  CLEAR_BIT(SPCR,SPIE);
			                      break;
		case Interrupt_Enabled:   SET_BIT(SPCR,SPIE);
			                      break;
		}
		switch( Config_Ptr ->data_order )
		{
		case MSB_First:   CLEAR_BIT(SPCR,DORD);
			                      break;
		case LSB_First:   SET_BIT(SPCR,DORD);
			                      break;
		}

		/*Set it as Slave*/
		 CLEAR_BIT(SPCR,MSTR);


		switch( Config_Ptr ->clock_polarity )
		{
		case Rising_Edge:    CLEAR_BIT(SPCR,CPOL);
			                      break;
		case Falling_Edge:   SET_BIT(SPCR,CPOL);
			                      break;
		}
		switch( Config_Ptr ->clock_phase )
		{
		case Leading_Edge:    CLEAR_BIT(SPCR,CPHA);
			                      break;
		case Trailing_Edge:   SET_BIT(SPCR,CPHA);
			                      break;
		}
		switch( Config_Ptr ->clock_rate )
		{
		case divided_By_4:    CLEAR_BIT(SPCR,SPR0);
		                      CLEAR_BIT(SPCR,SPR1);
		                      CLEAR_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_16:   SET_BIT(SPCR,SPR0);
		                      CLEAR_BIT(SPCR,SPR1);
		                      CLEAR_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_64:   CLEAR_BIT(SPCR,SPR0);
		                      SET_BIT(SPCR,SPR1);
		                      CLEAR_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_128:  SET_BIT(SPCR,SPR0);
		                      SET_BIT(SPCR,SPR1);
		                      CLEAR_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_2:    CLEAR_BIT(SPCR,SPR0);
		                      CLEAR_BIT(SPCR,SPR1);
		                      SET_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_8:    SET_BIT(SPCR,SPR0);
		                      CLEAR_BIT(SPCR,SPR1);
		                      SET_BIT(SPSR,SPI2X);
			                      break;
		case divided_By_32:   CLEAR_BIT(SPCR,SPR0);
		                      SET_BIT(SPCR,SPR1);
		                      SET_BIT(SPSR,SPI2X);
					              break;
		}

}
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
uint8 SPI_sendReceiveByte(uint8 data)
{
    SPDR = data;

    /*Wait until flag turns to 1*/
    while ( BIT_IS_CLEAR(SPSR,SPIF) );

    return SPDR;

}
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
void SPI_sendString( const uint8 * Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}
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
void SPI_receiveString (uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_receiveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_receiveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
