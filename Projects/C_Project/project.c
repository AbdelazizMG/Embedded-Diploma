/*
 *  Project.c
 *  Vehicle Control System
 *  Created on: Sep 9, 2021
 *  Author: Abdelaziz Mohammad
 */

#include <stdio.h>

#define Engine_Control_Flag 1

typedef enum
{
	Off,
	ON,
}State;

typedef struct
{
	int Vehicle_Speed;
	int Room_Temp;
	int Engine_Temp;
	State Engine_State;
	State Engine_Temp_Controller_State;
	State AC_State;
}Data;

void System_Data_Init(Data * System_Data);
void Set_Room_Temp(Data * System_Data);
void Set_Traffic_Light(Data * System_Data);
void Sensor_Set_Menu_Display(Data * System_Data);
void Display_Data(Data * System_Data);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char User_input;
	Data System_Data;
    System_Data_Init(&System_Data);
	printf("\t\t\t Vehicle Control System \n\n");



    while(1)
    {

	printf("What do You want to do?\n\n");
	printf("a. Turn on the Vehicle Engine\nb. Turn off The Vehicle Engine\nc. Quit the System\n");

	printf("You Choose: ");
    scanf(" %c",&User_input);

    switch(User_input)
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




	return 0;
}

void Set_Traffic_Light(Data * System_Data)
{
	char User_Color_Input;
	printf("Enter the required color: ");
	scanf(" %c", &User_Color_Input);
	switch(User_Color_Input)
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
	char User_Option;
	while(1)
	{


	printf("\n\t\t\t a. Turn off the engine\n\t\t\t b. Set the traffic light color\n\t\t\t c. Set the room temperature\n\t\t\t d. Set the engine temperature\n\n");
    printf("You Choose: ");
    scanf(" %c", &User_Option);
	switch(User_Option)
	{
	  case 'a': return;
	            break;

	  case 'b': Set_Traffic_Light(System_Data);
		        break;

	  case 'c': Set_Room_Temp(System_Data);
		        break;

	  case 'd':
		        #if Engine_Control_Flag
		        Set_Engine_Temp(System_Data);
                #endif
		        break;

	  default:  break;
	}

	}


}

void System_Data_Init(Data * System_Data)
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
	 if(System_Data->Vehicle_Speed==30)
	   {
		   System_Data->Engine_State=ON;
		   System_Data->Room_Temp= System_Data->Room_Temp * 1.25 + 1;
           #if Engine_Control_Flag
		   System_Data->Engine_Temp_Controller_State=ON;
		   System_Data->Engine_Temp = System_Data->Engine_Temp * 1.25 + 1 ;
           #endif
	   }
   if(System_Data->Engine_State)
   {
	   printf("\nEngine State: ON\n");
   }
   else
   {
	   printf("Engine State: Off\n");
   }
   if(System_Data->AC_State)
   {
   printf("AC State: ON\n");
   }
   else
   {
    printf("AC State: Off\n");
   }
   printf("Vehicle Speed: %d km/hr ", System_Data->Vehicle_Speed);
   printf("\nRoom Temperature: %d°C\n", System_Data->Room_Temp);
   #if Engine_Control_Flag
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
