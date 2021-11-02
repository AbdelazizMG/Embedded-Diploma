/*
 * assignment 5.c
 *
 *  Created on: Aug 14, 2021
 *      Author: sigmaa
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



typedef struct                /* task1  */
{
  char name[20];
  int  marks[6];
  char roll;
}student;

typedef struct
{
    float inch;
    float feet;
}distance;

typedef struct
{
	float real;
	float img;
}complex;

typedef struct
{
	int hours;
	int min;
	int sec;
}time;

typedef struct
{
	char name[20];
	int ID;
	char grade;
}information;

typedef union
{
	char first_name[30];
	char last_name[30];
}family_name;

typedef enum
{
	Level1,
	Level2,
	Level3,
}fan_level;

void task1 ( student * st)
{
	strcpy(st->name,"Ahmed");
	printf("%s\n",st->name);
	for(int i = 0 ; i < 6 ; i ++ )
	{
		st->marks[i]=i+5;
		printf("%d ", st->marks[i]);
	}
	st->roll='A';
	printf("\n%c",st->roll);
}
/* ---------------------------------------- */
void task2 ( distance * dist1 ,  distance * dist2)
{
	printf("Sum of inches equal %f\n", dist1->inch + dist2->inch);
	printf("Sum of feet equal %f", dist1->feet + dist2->feet);
}
/* ---------------------------------------- */
void task3  (complex * comp1 ,  complex * comp2)
{
	printf("The Result equals %f + %f i", comp1->real+comp2->real , comp1->img + comp2->img);
}
/* ---------------------------------------- */
void task4 ( time * time1 , time * time2)
{
	float time_1 ;	float time_2;
	time_1 = time1->sec+ time1->min * 60 + time1->hours * 3600 ;
	time_2 = time2->sec+ time2->min * 60 + time2->hours * 3600 ;
	time_1 = time_1 - time_2;

	if(time_1 < 60 ) // in seconds
	{
	    printf("The difference is %d seconds",(int)time_1);
	}
	else if(time_1 >= 60 && time_1 < 3600)    //in minutes
	{
	    printf("The difference is %d minutes %d seconds",(int)time_1/60 ,(int)(time_1) - (int)((time_1)/60)*60);
	}
	else if(time_1 >= 3600)    //in  hours
	{
	   int min = (int)(time_1-3600);
	   while(min>=3600)
	   {
	       min=min-3600;
	   }
	  printf("The difference is %d hours %d minutes %d seconds", (int) time_1/3600,min/60 ,(int)(time_1-3600) - (int)((time_1-3600)/60)*60);
	}
}
/* ---------------------------------------- */
void task5_I( struct information * info , int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		strcpy( *(info+i)->name , "Ahmed" );
		*(info+i)->ID = i * 5;
		*(info+i)->grade = 'A';
	}
}
void task5_II( information *info , int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		printf("Name: %s ID: %d Grade: %c\n",*(info+i)->name ,*(info+i)->ID ,*(info+i)->grade);
	}
}
/* ---------------------------------------- */
void task6( family_name * fam)
{
   strcpy(fam->first_name,"Ali");
   printf("Last name %s Size of union %d" , fam->last_name, sizeof(fam));

}
/* ---------------------------------------- */

int main ()
{



	return 0 ;
}
