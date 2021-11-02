/*
 * assignemnt2.c
 *
 *  Created on: Aug 5, 2021
 *      Author: sigmaa
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ------------------------------------------------------------------------
void task1(int number)
{
	printf("Cube of a number is %d", number*number*number);
}
// ------------------------------------------------------------------------
void task2(char character)
{
	if( (character >= 65 && character <= 90 ) || (character >= 97 && character <= 122 ) )
	{
		printf("Alphabetic\n");
	}
	else
	{
		printf("Not Alphabetic\n");
	}
}
// ------------------------------------------------------------------------
void task3(int number)
{
	if(number>0) printf("Positive");
    else printf("Negative");
}
// ------------------------------------------------------------------------
void task4( float num1 , float num2, char operation)
{
	switch(operation)
	{
	case '+': printf("%d/n", num1 + num2);
	          break;

	case '-': printf("%d/n", num1 - num2);
		          break;

	case '*': printf("%d/n", num1 * num2);
		          break;

	case '/': printf("%d/n", num1 + num2);
		          break;

	default:  printf("Invalid Operation/n");
	}
}
// ------------------------------------------------------------------------
int task5 (int number)
{
	if(number %2 ==0 ) return 0;
	else return 1;
}
// ------------------------------------------------------------------------
void task6 (char character)
{
	printf("%c", character -=32);
}
// ------------------------------------------------------------------------
void task7 (int num1 , int num2)
{
	if(num1 % num2 ==0 ) printf("True\n");
	else printf("False\n");
}
// ------------------------------------------------------------------------
void task8 (int num1 , int num2 )
{
	for(int i = num1 ; i <= num2 ; i++)
		{
		    int prime = 1;
			for(int j =2 ; j <= i/2  ; j++)
			{
				if(i % j ==0  && i != j)
				{
					prime = 0;
					break;
				}
			}
			if(prime && i!=1) printf("%d ", i);
		}
}
// ------------------------------------------------------------------------
void task9(int num1 , int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
// ------------------------------------------------------------------------
int task10 (int number)
{
	   int total_number_of_holes = 0;
	   int check_num = 10;
	   int check_bool =0;
	   int digit_number=1;
		 while (! check_bool)
		  {
		        if(number >= check_num) //10
		        {
		            digit_number+=1;
		            check_num *=10;   // check 100 1000 10000 ...
		        }
		        else
		        {
		            check_bool =1;
		            break;
		        }
		    }

		for(int i = 0 ; i < digit_number ; i ++ )
		{
		    int temp = number % 10 ;
		    if(temp == 0 || temp == 4 || temp == 6 || temp == 9) total_number_of_holes++;
		    else if ( temp == 8) total_number_of_holes +=2;

		    number = number / 10;
		}
	return total_number_of_holes;
}
// ------------------------------------------------------------------------
int task11 (int number)
{
	int counter = 0;
	int flag =0;
	int loop =1;
	int power_value=0;
	while(loop)
	{
		power_value = pow(2,counter);
		if(power_value == number)
		{
			flag =1;
			break;
		}
		if(power_value > number)
		{
			flag = 0;
			break;
		}
		counter++;
	}
	if(flag) return 1;
	else return 0;
}
// ------------------------------------------------------------------------
int task12(int temperature)
{
	int heating_time;
	if(temperature >=0 && temperature < 30) heating_time = 7;
	else if (temperature >=30 && temperature < 60)  heating_time = 5;
	else if (temperature >=60 && temperature < 90)  heating_time = 3;
	else if (temperature >=90 && temperature < 100)  heating_time = 1;
	else if (temperature > 100) heating_time =0;
	return heating_time;
}
// ------------------------------------------------------------------------
void task13 ( float num1 , float num2 )
{
    float result = num1 + num2;
    int result_int = (int)result;
    printf("%d",result_int);
}
// ------------------------------------------------------------------------
void task14 ()
{

}
// ------------------------------------------------------------------------
void task15(unsigned int number)
{
	   int counter = 0;
	   int temp;
	   for ( int i = 31 ; i > 0 ; i -- )
	   {
	     temp = number << i & 0x80000000 ;
	     temp? counter++: printf("");
	   }
	   printf("%d",counter);
}
// ------------------------------------------------------------------------
void task16(unsigned int number)
{
	   int counter = 0;
	   int temp;
	   for ( int i = 7 ; i > 0 ; i -- )
	   {
	     temp = number << i & 0x80 ;
	     temp? counter++: printf("");
	   }
	   printf("%d",counter);
}
// ------------------------------------------------------------------------
void task17 ( int L , int R )
{
	int result = 0;
	int max = 0;
	for ( int i = L ; i <=R ; i ++)
	{
		for ( int j = i ; j<= R ; j++)
		{
			result = i ^ j;
			if(result > max ) max = result;
			printf("%d xor %d = %d  \n", i , j , result);
		}
	}
}
// ------------------------------------------------------------------------
int task18 (int number)
{

	    int flag =0 ;
	    int check = 0;
	    int power_1 = 0;
	    int base=0;
	    for ( int i = 1 ; i <= number ; i ++)
	    {

	        while(power_1 < 1000)
	        {
	            check = power(i,power_1);
	            if(check == number)
	            {
	               base = i;
	               flag =1 ;
	               break;
	            }
	            power_1 ++;
	        }
	        if(flag) break;
	    }
	    printf("P = %d , Q = %d ", base , power_1);
	    return base;
}
// ------------------------------------------------------------------------
int task19 (int number)
{
	    int counter = 1;
		int flag =0;
		int loop =1;
		int power_value=0;
		while(loop)
		{
			power_value = pow(3,counter);
			if(power_value == number)
			{
				flag =1;
				break;
			}
			if(power_value > number)
			{
				flag = 0;
				break;
			}
			counter++;
		}
		if(flag) return 1;
		else return 0;
}
// ------------------------------------------------------------------------
int main()
{
	printf("H");
	return 0;
}

