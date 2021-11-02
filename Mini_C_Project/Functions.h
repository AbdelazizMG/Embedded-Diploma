/*
 *  Functions.h
 *
 *  Created on: Sep 9, 2021
 *  Author: Abdelaziz Mohammad
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>

#define Engine_Control_Flag 1      /*Flag for Bonus Requirement initially = 1 , if it equals 0 the Engine Control will not run*/


typedef enum                                     /* Enum for holding AC and Engine Control States*/
{
	Off,
	ON,
}State;



typedef struct                                     /* Defining our system Properties*/
{
	int Vehicle_Speed;
	int Room_Temp;
	int Engine_Temp;
	State Engine_State;
	State Engine_Temp_Controller_State;
	State AC_State;
}Data;


void System_Data_Init(Data * System_Data);          /*System Processing Functions*/
void Set_Room_Temp(Data * System_Data);
void Set_Traffic_Light(Data * System_Data);
void Sensor_Set_Menu_Display(Data * System_Data);
void Display_Data(Data * System_Data);

#endif /* FUNCTIONS_H_ */
