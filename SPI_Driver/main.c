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



int main (void)
{
	SPI_ConfigType config_struct = { SPI_Enabled,\
			Interrupt_Disabled,\
			MSB_First,\
			Rising_Edge,\
			Leading_Edge,\
			divided_By_4,\
	};

	SPI_initMaster(&config_struct);

	while (1)
	{

	}


	return 0;
}

