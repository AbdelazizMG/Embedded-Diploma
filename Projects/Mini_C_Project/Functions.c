/*
 *  Functions.c
 *  Functions Body File
 *  Created on: Sep 9, 2021
 *  Author: Abdelaziz Mohammad
 */

#include "Functions.h"

void Set_Traffic_Light(Data * System_Data)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char User_Color_Input;
	printf("Enter the required color: ");
	scanf(" %c", &User_Color_Input);
	switch(User_Color_Input)                   /*Setting The Vehicle Speed according to Traffic Light Sensor*/
	{
	   case 'G':  System_Data->Vehicle_Speed=100;
		          break;

	   case 'O':  System_Data->Vehicle_Speed=30;
		          break;

	   case 'R':  System_Data->Vehicle_Speed=0;
		          break;
	}
	Display_Data(System_Data);
}


void Set_Room_Temp(Data * System_Data)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int temp;
	printf("Enter Room Temp: ");
	scanf(" %d", &temp);
	System_Data->Room_Temp=temp;
	if(System_Data->Room_Temp <10  || System_Data->Room_Temp > 30)
	{
		System_Data->AC_State = ON;
		System_Data->Room_Temp=20;
	}
	else
	{
		System_Data->AC_State = Off;
	}
	Display_Data(System_Data);
}


void Set_Engine_Temp(Data * System_Data)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int temp;
	printf("Enter Engine Temp: ");
	scanf(" %d", &temp);
	System_Data->Engine_Temp= temp;
	if(System_Data->Engine_Temp <  100  || System_Data->Engine_Temp >  150)
	{
		System_Data->Engine_Temp = 125;
		System_Data->Engine_Temp_Controller_State =ON;
	}
	else
	{
		System_Data->Engine_Temp_Controller_State =Off;
	}
	Display_Data(System_Data);
}

void Sensor_Set_Menu_Display(Data * System_Data )
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char User_Option;                                       /*Holding User Option*/
	while(1)
	{


	printf("\n\t\t\t a. Turn off the engine\n\t\t\t b. Set the traffic light color\n\t\t\t c. Set the room temperature\n\t\t\t d. Set the engine temperature\n\n");
    printf("You Choose: ");
    scanf(" %c", &User_Option);
	switch(User_Option)
	{
	  case 'a': return;                                      /*Turning off the Engine*/
	            break;

	  case 'b': Set_Traffic_Light(System_Data);             /* Setting The Traffic Light*/
		        break;

	  case 'c': Set_Room_Temp(System_Data);                /* Setting Room Temperature */
		        break;

	  case 'd':
		        #if Engine_Control_Flag                   /*Controlling the Engine Temperature call by the flag*/
		        Set_Engine_Temp(System_Data);
                #endif
		        break;

	  default:  break;
	}

	}


}

void System_Data_Init(Data * System_Data)                      /*Giving Initial Values to the system*/
{
	System_Data->AC_State=Off;
	System_Data->Engine_State=Off;
	System_Data->Engine_Temp_Controller_State=Off;
	System_Data->Room_Temp=25;
	System_Data->Engine_Temp=20;
	System_Data->Vehicle_Speed=35;
}

void Display_Data(Data * System_Data)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	 if(System_Data->Vehicle_Speed==30)                          /*Modifing the system if the speed equals 30*/
	   {
		   System_Data->Engine_State=ON;
		   System_Data->Room_Temp= System_Data->Room_Temp * 1.25 + 1;

           #if Engine_Control_Flag                               /*Controlling the Modification by the flag*/
		   System_Data->Engine_Temp_Controller_State=ON;
		   System_Data->Engine_Temp = System_Data->Engine_Temp * 1.25 + 1 ;
           #endif
	   }
   if(System_Data->Engine_State)                                 /*Condition for writing ON if 1 and Off if 0*/
   {
	   printf("\nEngine State: ON\n");
   }
   else
   {
	   printf("Engine State: Off\n");
   }
   if(System_Data->AC_State)                                     /*Condition for writing ON if 1 and Off if 0*/
   {
   printf("AC State: ON\n");
   }
   else
   {
    printf("AC State: Off\n");
   }
   printf("Vehicle Speed: %d km/hr ", System_Data->Vehicle_Speed);
   printf("\nRoom Temperature: %d°C\n", System_Data->Room_Temp);

   #if Engine_Control_Flag                                      /*Controlling the Conditions execution by the flag */
   if(System_Data->Engine_Temp_Controller_State)
   {
     printf("Engine Temp Controller State: ON\n");
   }
   else
   {
       printf("Engine Temp Controller State: Off\n");
   }
   printf("Engine Temperature: %d°C \n", System_Data->Engine_Temp);
   #endif



}
