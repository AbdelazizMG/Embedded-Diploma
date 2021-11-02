/*
 * assignment 3.c
 *
 *  Created on: Aug 9, 2021
 *      Author: Abdelaziz Mohammad
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



/* ---------------------------------------------------- */
int task1(int * numbers , int numbers_size)
{
	int sum = 0;
	for ( int i =0 ; i < numbers_size ; i ++ )
	{
		sum = sum + *(numbers+i);
	}
	return sum;
}
/* ---------------------------------------------------- */
int task2 (char * text)
{
	int counter=0;
	for (int i =0 ; text[i] ; i ++)
	{
		for ( int j =0 ; text[j] ; j++)
		{
			if(i==j) continue;
			if(text[i]==text[j]) return 0;
		}
	}
	return 1;
}
/* ---------------------------------------------------- */
void task3 (int * array)        /*    Bubble Sort Algorithm */
{

}
/* ---------------------------------------------------- */
void task4 (int * array)       /*     Selection Sort Algorithm   */
{

}
/* ---------------------------------------------------- */
int task5 ( int * array , int size , int number)
{
	int index =-1;
	for ( int i = 0 ; i < size ; i ++ )
	{
		if(number == *(array+i))
			{
			   index = i ;
			   return index;
			}
	}
	return index;
}
/* ---------------------------------------------------- */
int task6 ( int * array , int size , int number)
{
	int index =-1;
	for ( int i = 0 ; i < size ; i ++ )
	{
		if(number == *(array+i))
			{
			   index = i ;
			}
	}
	return index;
}
/* ---------------------------------------------------- */
int task7 ( int number )
{
	return 2 * number + 1;
}
/* ---------------------------------------------------- */
int task8 (int number)
{
	int sum =1;
	for ( int i = 1 ; i <= number ; i ++ )
	{
		sum = sum * 3 ;
	}
	return sum;
}
/* ---------------------------------------------------- */
/*int task9 ( int number)
{
   if( number == 1 || number == 2 ) return 1;

}*/
/* ---------------------------------------------------- */
void task10 ( char * text   )
{
	for ( int i =0 ; text[i] ; i ++ )
	{
		if( *(text+i) >= 65 && *(text+i) <= 90 )
		{
			*(text+i) += 32;
		}
	}
	printf("%s", text);
}
/* ---------------------------------------------------- */
void task11 ( char * text  , char target)
{
	int counter = 0 ;

	for ( int i = 0 ; text[i] ; i ++ )
	{
		if(target == * ( text + i ) ) counter ++;
	}
	printf("Counter = %d" , counter );
}
/* ---------------------------------------------------- */
int task12 ( char * text)
{
	int len = 0 ;
	for ( int i = 0 ; text[i] ; i ++)
	{
		len ++;
	}
	return len;
}
/* ---------------------------------------------------- */
void task13 ( char * text )
{
    char text2[20];
    int j =0;
	for ( int i = 0 ; text[i] ; i ++)
	{

		if( (*(text+i) >= 65 && *(text+i) <= 90)  ||  (*(text+i) >= 97 && *(text+i) <= 122) )
		{
				text2[j]=text[i];
				j++;
		}
		else continue;

	}
	printf("%s",text2);

}
/* ---------------------------------------------------- */
void task14 ( char * text )
{
	char temp;
	for ( int i=0 ; i < strlen(text)/2 ; i ++ )
	{
		temp = * ( text + i ) ;
		* ( text + i ) = * (text + strlen(text)-(i+1));
		* (text + strlen(text)-(i+1)) = temp ;
	}
	printf("%s", text);
}
/* ---------------------------------------------------- */
void task15 ( char * text1 , char * text2 )
{
	/*  a h m e d
	 *  0 1 2 3 4   text1[len] = null   text1[len+1]= ' ' */
	int len = 0 ;
	int j =0;
	for ( int i = 0 ; text1[i] ; i ++)
	{
		len ++;
	}
	text1[len] = ' ';

	for(int i = len+1 ; text2[j] ; i ++ )
	{
		text1[i]=text2[j];
		j++;
	}
	printf("%s\n",text1);
}
/* ---------------------------------------------------- */
void task16 ( int * array , int size )
{
	int temp;
	for ( int i = 0 ; i < size/2 ; i ++ )
	{
		temp = *(array+i);
		*(array+i)= *(array+size-(i+1));
		*(array+size-(i+1)) = temp;
	}
}
/* ---------------------------------------------------- */
void task17 (int a_size,int *a,int b_size,int *b)
{
	int * temp;
	for( int i = 0 ; i < b_size ; i++)
	{
		temp = * (a+i);
		*(a+i) = *(b+i);
		*(b+i) = temp;
	}
}
/* ---------------------------------------------------- */
int task18 ( int * array , int size )
{
	int counter = 0 ;
	int temp[size];
	for ( int i = 0 ; i < size ; i ++ )
	{
	    temp[i]=0;
		for ( int j =0 ; j < size ; j ++ )
		{
			if( *(array+i) == * (array+j) && *(array+i) == * (array+j+1)) temp[i] ++;
		    else if(*(array+i) == * (array+j) && *(array+i) != * (array+j+1))
			{
				temp[i]++;
				break;
			}
		}

	}
	int max = temp[0];
	for(int i = 1 ; i < size ; i ++ )
	{
	    if(temp[i]>max) max = temp[i];
	}
	return max;
}
/* ---------------------------------------------------- */
int task19 ( int * array1 , int * array2 , int size )
{
	for ( int i = 0 ; i < size ; i ++ )
	{
		if( *(array1+i) != *(array2+i)) return 1;
	}
	return 0;
}
/* ---------------------------------------------------- */

void task20 ( unsigned int LowerValue , unsigned int UpperValue)
{
	int counter=0;
    for(int i = UpperValue-1 ; i>LowerValue ; i--)
    {
       counter++;
    }
    int array[counter];
    int j=0;
    for(int i = UpperValue-1 ; i>LowerValue ; i--)
    {
    	array[j]=i;
    	j++;
    }
    for(int i=0; i <counter ; i ++ )
    {
    	printf("%d ", array[i]);
    }
}
/* ---------------------------------------------------- */
void task21 ( unsigned int LowerValue , unsigned int UpperValue)
{
	int counter=0;
    for(int i = UpperValue ; i>=LowerValue ; i--)
    {
       counter++;
    }
    int array[counter];
    int j=0;
    for(int i = UpperValue ; i>=LowerValue ; i--)
    {
    	array[j]=i;
    	j++;
    }
    for(int i=0; i <counter ; i ++ )
    {
    	printf("%d ", array[i]);
    }
}
/* ---------------------------------------------------- */
int task22 (int arr_old[], int n_old, int arr_new[], int *n_new)
{
	int counter =0 ;

	for ( int i = 0 ; i < n_old ; i ++ )
	{
		for ( int j = 0 ; j < n_old ; j++)
		{
			if( arr_old[i] == arr_old[j] && i>j)
			{
				break;
			}
			else if( arr_old[i] == arr_old[j] && i==j)
			{
				counter++;
				arr_new[arr_old[i] -1]= arr_old[i];
				break;
			}
		}
		counter=0;
	}
	for(int i = 0 ; i <6; i ++ )
	{
		printf("%d ", arr_new[i]);
	}
}
/* ---------------------------------------------------- */
void task23 (char * text )
{
	int len = 0 ;
	for ( int i = 0 ; text[i] ; i ++)
	{
		len ++;
	}
	int array[len];
	for( int i = 0 ; text[i] ; i++)
	{
		array[i]=0;
		for ( int j=0; text[j] ; j++ )
		{
             if( *(text+i) == *(text+j)  ) array[i]++;
		}
	}
	for ( int i =0 ; i < len ; i++ )
	{
		printf("%d ", array[i]);
	}
}
/* ---------------------------------------------------- */
int main ()
{
    char name[20]= "ieee";
    printf("%d", task2(name));

	return 0;
}
