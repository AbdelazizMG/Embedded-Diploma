/*
 *      main.c
 *      Vehicle Control System
 *      Created on: Sep 9, 2021
 *      Author: Abdelaziz Mohammad
 */

#include "Functions.h"
#include<stdio.h>


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char User_input;                        /* Var for holding user choices */
	Data System_Data;                       /* Defining our System Data */
	System_Data_Init(&System_Data);         /* Giving an initial value for our system */

	printf("\t\t\t Vehicle Control System \n\n");

 while(1)
 {
		printf("What do You want to do?\n\n");
		printf("a. Turn on the Vehicle Engine\nb. Turn off The Vehicle Engine\nc. Quit the System\n");

		printf("You Choose: ");
	    scanf(" %c",&User_input);

	    switch(User_input)                 /*Holding User options*/
	    {
	      case 'a': printf("\t\t\tTurn on the Vehicle Engine\n");
	    	        System_Data.Engine_State=ON;
	                Sensor_Set_Menu_Display(&System_Data);
	    	        break;

	      case 'b': printf("\nTurn off The Vehicle Engine\n\n");
	                System_Data.Engine_State=Off;
	     	        break;

	      case 'c': printf("Quit the System\n");
	    	        return 0;
	    	        break;

	      default:  break;
	    }
 }
	return 0 ;
}
