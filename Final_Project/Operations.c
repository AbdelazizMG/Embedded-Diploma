/******************************************************************************
*  Module:    Operations
*  File name: Operations.h
*  Created on: Oct 25, 2021
*  Author: Abdelaziz Mohammad
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*                                  INCLUDES                                    *
*                                                                              *
********************************************************************************/
#define F_CPU 8000000
#include "LCD.h"
#include "keypad.h"
#include "util/delay.h"
#include "Operations.h"
#include "Timers.h"
#include "UART.h"
#include "avr/io.h"

/*******************************************************************************
*                                                                              *
*                              Global Variables                                *
*                                                                              *
********************************************************************************/
uint8 g_Password_Entry1[ARRAY_SIZE];
uint8 g_Password_Entry2[ARRAY_SIZE];

/*To be Deleted when writing EEPROM*/
uint8 g_EEPROM_ARRAY[ARRAY_SIZE];

/*Variable used in call back functions*/
uint16 g_Interrupt_Number=0;

/*Timer Configuration Structure*/
extern const TIMER_ConfigType Config_Struct;

/*******************************************************************************
*                                                                              *
*                              FUNCTIONS Definitions                           *
*                                                                              *
********************************************************************************/
/*******************************************************************************
* Service Name:       OPERATION_EnterPassword
* Sync/Async:         Synchronous
* Reentrancy:         Reentrantoopippp
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Ask user to enter the password
********************************************************************************/
void OPERATION_EnterPassword(void)
{
	/*Clear Screen from prvious operation*/
	LCD_clearScreen();

   /*Variable to hold keypadd press*/
	uint8 key1;

   /*counter for while loop*/
    uint8 counter = 0;

   /*Actual Operation*/
   LCD_displayString("Enter Password:");
   LCD_moveCursor(1, 0);

   while ( counter < 5)
   {
	   /*Get Keypress from the user*/
	   key1 = KEYPAD_getPressedKey();

	   /*Store keypress in the array*/
	   g_Password_Entry1[counter]=key1;

	   /*Display Key Press on LCD */
	   LCD_intgerToString(key1);

	  // LCD_displayCharacter('*');
	   _delay_ms(800);

	   /*Increament counter*/
	   counter ++;
   }


}
/*******************************************************************************
* Service Name:       OPERATION_reEnterPassword
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Ask useer to re-enter the password
********************************************************************************/
void OPERATION_reEnterPassword(void)
{
    /*Clear screen from previous operation*/
	LCD_clearScreen();

   /*Variable to hold keypad press*/
	uint8 key;

   /*counter for while loop*/
    uint8 counter = 0;

   /*Actual Operation*/
   LCD_displayString("Re Enter Pass:");
   LCD_moveCursor(1, 0);

   /*Take 5 digits from the user*/
   while ( counter < 5)
   {
	   /*Get Key press from the user*/
	   key = KEYPAD_getPressedKey();

	   /*Save the key press in the array*/
	   g_Password_Entry2[counter]=key;

	   /*Display Key Press on LCD*/
	   LCD_intgerToString(key);

	  // LCD_displayCharacter('*');
	   _delay_ms(800);

	   /*Increament counter*/
	   counter ++;
   }


}
/*******************************************************************************
* Service Name:       OPERATION_checkMatch
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Check Password Match between different entries
********************************************************************************/
void OPERATION_checkPasswordMatch(void)
{
   /*counter for while loop*/
   uint8 counter = 0;

   /*flag for matching detection - initially matched*/
   uint8 flag = 1 ;

   /*Variable to hold number of miss matches*/
   static uint8 missmatch_counter = 0;

   /*Check Each Element in the Array*/
   while (counter < 5 )
   {
       if ( g_Password_Entry1[counter] != g_Password_Entry2[counter])
       {
    	   flag = 0 ;
       }
       counter ++ ;
   }

  /*Reset Counter*/      /*To be deleted when writting EEPROM*/
   counter=0;

   switch (flag)
   {
      /*Missmatched Case*/
      /*Repeat Step 1 */
      case 0 :  missmatch_counter++;
                if(missmatch_counter== 3)
                {

                	LCD_clearScreen();
                	LCD_displayString("Error");

                	/* Send 'a' by UART to Second MCU to detect an error
                	 * Turn ON BUZZER for 1-minute
                	 */
                	UART_sendByte('a');
                	missmatch_counter = 0;
                }
                else
                {
                	OPERATION_EnterPassword();
                	OPERATION_reEnterPassword();
                	OPERATION_checkPasswordMatch();
                }

    	        break;

      /*Matched Case*/

      /*Save Password in EEPROM and Go to Main Options*/
      case 1 :

    	  /*To Be deleted when writting EEPROM*/
    	  /*Save Passowrd in EEPROM*/

    	  /*indicate that the following incoming data is to be saved in EEPROM*/
    	  UART_sendByte('e');

    	  while (counter < 5 )
    	  {
    		  g_EEPROM_ARRAY[counter]= g_Password_Entry1[counter];
    		  UART_sendByte(g_Password_Entry1[counter]);
    		  counter ++ ;
    	  }
    	        /*Go to Main Options*/
    	        OPERATION_MainOptions();
    	        break;
   }
}
/*******************************************************************************
* Service Name:       OPERATION_checkEEPROMMatch
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Check Password Match EEPROM and Entry
********************************************************************************/
uint8 OPERATION_checkEEPROMMatch(void)
{
	   /*counter for while loop*/
	   uint8 counter = 0;

	   /*flag for matching detection - initially matched*/
	   uint8 flag = 1 ;



	   while (counter < 5 )
	   {
		   if(g_EEPROM_ARRAY[counter] != g_Password_Entry1[counter])
		   {
			   flag = 0;
		   }
		   counter ++ ;
	   }

	   return flag;


}
/*******************************************************************************
* Service Name:       OPERATION_MainOptions
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Display Main Options for user
********************************************************************************/
void OPERATION_MainOptions(void)
{
    /*Clear screen from previous operation*/
	LCD_clearScreen();

	/*variable to hold keypad press*/
	uint8 key;

	/*Variable to check Driving Motor*/
	uint8 Motor_Drive_Check = 0;

	/*Variable to hold number of miss matches*/
	 static uint8 missmatch_counter = 0;

	/*Actual Operation*/
	LCD_displayString("+: Open Door");
	LCD_moveCursor(1, 0);
	LCD_displayString("-: Change Pass");

	/*Get Key Press */
	key = KEYPAD_getPressedKey();

	_delay_ms(800);

	switch (key)
	{
	  /*Motor Drive Case*/
	  case '+' :  /*Enter Password*/
		          OPERATION_EnterPassword();

	             /*IF matched with password saved in EEPROM - Drive Motor*/
	             Motor_Drive_Check = OPERATION_checkEEPROMMatch();

	             /*Matched Case*/
	             if(Motor_Drive_Check == 1)
	             {
	            	 /*Send By UART something to drive Motor*
	            	 *
	            	 *
	            	 */

	            	 UART_sendByte('b');

	            	 /*Init Timer*/
	            	 Timer_init(&Config_Struct);

	            	 /*I-Bit*/
	            	 SET_BIT(SREG,7);

	            	 LCD_clearScreen();
	            	 LCD_displayString("Opening Door");

	            	 /*Setting Time for 15 seconds*/
	            	 g_Interrupt_Number=461;

	            	 /*Start Taking ACTION in ISR*/
	           	     Timer0_setCallBack(OPERATION_LCD_Control);

	             }
	             /*Miss Matched Case*/
	             else
	             {
	            	 while ( Motor_Drive_Check != 1 )
	            	 {
	            		 missmatch_counter++;
		            	 if(missmatch_counter == 3)
		            	 {
		                 	LCD_clearScreen();
		                 	LCD_displayString("Error");

		                 	/* Send 'a' by UART to Second MCU to detect an error
		                 	 * Turn ON BUZZER for 1-minute
		                 	 */
		                 	UART_sendByte('a');
		                 	missmatch_counter = 0;

		                 	break;
		            	 }

	            		 /*Enter Password*/
	            		 OPERATION_EnterPassword();
	            		 Motor_Drive_Check = OPERATION_checkEEPROMMatch();

	            	 }
	            }

	             break;

	 /*Change Password Case*/
	  case '-' :
		         /*repeat step 1*/
    	         OPERATION_EnterPassword();
    	         OPERATION_reEnterPassword();
    	         OPERATION_checkPasswordMatch();

	             break;
	  default:
		         break;
	}
}
/*******************************************************************************
* Service Name:       OPERATION_
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       uint8
* Description:        Function to be called when ISR happens
********************************************************************************/
void OPERATION_LCD_Control(void)
{
	/*Variable to hold interrupt counts*/
	static uint16 counter = 0;

	/*Variable to detect which direction the motor is rotating*
	 * 0 indicated CW , 1 indicates CCW
	 */

	static uint8 flag = 0;

	counter ++ ;

	/*Holdind Motor for three seconds perparing for second rotation*/
	if(counter ==  g_Interrupt_Number && g_Interrupt_Number == 461 && flag ==0)
	{
		LCD_clearScreen();
		LCD_displayString("Holding Motor");
   	    g_Interrupt_Number=92;
		counter=0;
		flag = 1;
	}
	/*Rotating Motor in CCW Direction*/
	else if (counter ==  g_Interrupt_Number && g_Interrupt_Number == 92)
	{
   	      LCD_clearScreen();
   	      LCD_displayString("Closing Door");
   	      g_Interrupt_Number=215;
   	      counter = 0;
	}
	/*after 5 seconds stop the timer*/
	else if(counter ==  g_Interrupt_Number && g_Interrupt_Number == 215 && flag ==1)
	{
 	    LCD_clearScreen();
 	    LCD_displayString("Finished");
		Timer_Deinit(0);

	}

}

