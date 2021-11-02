/*
 * assignment 4.c
 *
 *  Created on: Aug 9, 2021
 *      Author: sigmaa
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* --------------------------------------------------- */
int task1( int * array , int size)
{
	int sum =0;

	for(int i = 0 ; i < size ; i++)
	{
		sum += *(array+i);
	}
	return sum;
}
/* --------------------------------------------------- */
int task2 (char * text)
{
	int counter = 0;
	for ( int i = 0 ; text[i] ; i ++  )
	{
		counter ++;
	}
	return counter;
}
/* --------------------------------------------------- */
void task3(int * array , int size)
{
	for (int i =0 ; i < size ; i ++ )
	{
		scanf("%d", array[i]);
	}
	for(int i = size -1 ; i >= 0 ; i -- )
	{
		printf("%d" , *(array+i));
	}
}
/* --------------------------------------------------- */
int task4 (int * array , int size)
{
	int smallest =  *(array);
	for(int i = 0 ; i < size ; i ++ )
	{
		if(smallest < *(array+i) ) smallest = *(array+i);
	}
	return smallest;
}
/* --------------------------------------------------- */
void task5 ( int * array1 , int * array2 , int size )
{
	for ( int i = 0 ; i < size; i ++ )
	{
		*(array1+i) = *(array2+i);
	}
}
/* --------------------------------------------------- */
void task6 (int * array , int size)
{
	int *ptr[size];
   for (int i = 0 ; i < size ; i ++)
   {
	   *(ptr+i) =   & array[i];
   }
   int max = *ptr[0];
   for (int i = 0 ; i < size ; i ++)
    {
	   printf("%d ", *ptr[i] );
  	   if( *ptr[i]  > max ) max = *ptr[i];
    }
   printf("\nMax number is %d ", max);

/* --------------------------------------------------- */
void task7(int * num1 , int * num2 )
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
/* --------------------------------------------------- */
void task8 (int * arr1 , int * arr2 , int size)
{
	for( int i = 0 ; i < size ; i ++)
	{
		int temp =  *(arr1+i);
		*(arr1+i) = *(arr2+i);
		*(arr2+i) = temp;
	}
}
/* --------------------------------------------------- */
void task9 ( char * text )
{
	char text2[3];
	while(*text != '\0')
	{
		text++;
	}
	text[0]= *(text-1);
	text[1]= ' ';
	text[2]= *(text-2);
}
/* --------------------------------------------------- */
void task10 ( int ** ptr1 , int ** ptr2)
{
	int * temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
/* --------------------------------------------------- */
void task11 (int number)
{
	short temp = number >> 16;
	int temp2 = number << 16;
    number = temp ^ temp2;
    printf("%d ",temp2);
}
/* --------------------------------------------------- */
int task12 ( int * array , int size)
{
	int counter;
	for(int i = 0 ; i < size ; i ++ )
	{
		for ( int j = 0 ; j < size ; j++)
		{
			if( * (array+i) == *(array+j) )
			{
				counter ++;
			}
		}
		if(counter %2 != 0) return *(array+i);

		counter=0;
	}
}
/* --------------------------------------------------- */
int main()
{
	printf("Hello World");
	return 0;
}

