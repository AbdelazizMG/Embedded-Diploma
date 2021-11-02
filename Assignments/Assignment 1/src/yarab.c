/*
 ============================================================================
 Name        : Assignment 1 .c
 Author      : Abdedlaziz Mohammad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------------------------------------------------------
/*     Assignment 1   Problem (1)
 *
 * int main(void) {


	int num1 , num2;
	printf("Enter First number: ");
	scanf("%d", &num1);
	printf("Enter Second number: ");
	scanf("%d", &num2);
	int result = ((num1+num2)*3)-10;
	printf("Result = %d ",result);
	return EXIT_SUCCESS;
}*/

// -------------------------------------------------------
/*
 * Assignment 1   Problem (2)
 * int main(void)
{

	printf("My name is Abdelaziz Mohammad.\nMy grade is A+\n");
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (3)
 * int main(void)
{

	float C , F ;
	F = C * (9/5) +32 ;
	return EXIT_SUCCESS;
}
*/

//--------------------------------------------------------

/*
 * Assignment 1   Problem (4)
 *  int main(void)
{

	float radius , area , circumference ;
	printf("Enter the radius: ");
	scanf("%f", &radius);
	area = (22/7) * radius * radius ;
	circumference = (44/7) * radius ;
	printf("Area = %f Circumference = %f " , area , circumference);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------

/*
 * Assignment 1   Problem (5)
 *   int main(void)
{

	char input;
	printf("Enter Character: ");
	scanf("%c", &input);
	printf("ASCII CODE IS %d" ,input);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (6)
 *   int main(void)
{
	    int num1 , num2;
	   	printf("Enter First number: ");
	   	scanf("%d", &num1);
	   	printf("Enter Second number: ");
	   	scanf("%d", &num2);
	   	if(num1 > num2)
	   	{
	   		printf("%d is greater than %d\n",num1,num2);
	   	}
	   	else if (num2 > num1 )
	   	{
	   		printf("%d is greater than %d\n",num2,num1);
	   	}
	   	else
	   	{
	   		printf("The two numbers are equal\n");
	   	}

	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (7)
 *    int main(void)
{
	   int num1,num2,num3;
	   printf("Enter First number: ");
	   scanf("%d", &num1);
	   printf("Enter Second number: ");
	   scanf("%d", &num2);
	   printf("Enter Third number: ");
	   scanf("%d", &num3);
	   if(num1 < num2 && num1 < num3 ) printf("%d is the smallest number", num1);
	   else if (num2 < num1 && num2 < num3) printf("%d is the smallest number", num2);
	   else printf("%d is the smallest number", num3);

	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 *  Assignment 1   Problem (8)
 *    int main(void)
{
	  double number,result;
	  printf("Enter the number: ");
	  scanf("%if",&number);
	  result = sqrt(number);
      if(result * result == number) printf("Perfect Square Number\n");
      else printf("NO!");
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------

/*
 *  Assignment 1   Problem (9)
 *    int main(void)
{

    float percentage;
    printf("Enter percentage: ");
    scanf("%f",&percentage);
    if(percentage >= 85) printf("Excellent\n");
    else if(percentage >=75 && percentage < 85 )  printf("Very Good\n");
    else if(percentage >=65 && percentage < 75 )  printf("Good\n");
    else if(percentage >=50 && percentage <65  )  printf("Pass\n");
    else printf("Fail\n");
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 *  Assignment 1   Problem (10)
 *     int main(void)
{

    char operation;
    float num1 , num2 , result;
    printf("Enter First number: ");
    scanf("%f", &num1);
    printf("Enter Second number: ");
    scanf("%f", &num2);
    printf("Enter Operation: ")
    scanf("%c", &operation);
    switch(operation)
    {
    case '+' : result = num1 + num2 ;
    break;
    case '-' : result = num1 - num2 ;
    break;
    case '*' : result = num1 * num2 ;
    break;
    case '/' : result = num1 / num2 ;
    break;
    }
    printf("Result = %f" , result);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (11)
 *     int main(void)
{

    int sum = 0;
    for (int i = 1 ; i <= 100 ; i ++)
    {
    	sum += i;
    }
    printf("Summation of first 100 integers = %d", sum);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (12)
 *       int main(void)
{

    int number,result;
    printf("Enter the number: ");
    scanf("%d", &number);
    int temp = number -1;
    result = number;
    while(temp != 0 )
    {
    	result = result * temp;
    	temp --;
    }
    printf("Result equals %d", temp);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------

 /*
  * Assignment 1   Problem (13)
  *      int main(void)
{

	int number;
	int flag =0;
	printf("Enter the number: ");
	scanf("%d", &number);
	for (int i=2 ; i<= number; i ++ )
	{
		if(i== number) continue;
		if(number % i ==0)
		{
			flag =0;
			break;
		}
		else
		{
			flag=1;
		}

	}
	if(flag||number==1) printf("%d is a Prime number\n",number);
	else printf("%d is Not a Prime number\n",number);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
 /*
  * Assignment 1   Problem (14)
  *       int main(void)
{

	for (int i = 65 ; i <= 90 ; i ++)
	    {
	    	printf("%c\n",i);
	    }

	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (15)
 *         int main(void)
{

	int number , power;
	printf("Enter number: ");
	scanf("%d", &number);
	printf("Enter power: ");
	scanf("%d", &power);
	int sum = 1;
	for(int i =1 ; i<= power ; i++)
	{
		sum = sum * number;
	}
	printf("Result = %d", sum);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------



 /*          int main(void)
{


	return EXIT_SUCCESS;
}

*/

 /*
  * Assignment 1   Problem (17)
  *         int main(void)
{

	int number, check_num, check_bool, digit_number;
	printf("Enter number: ");
	scanf("%d", &number);
	check_num = 10;
	check_bool =0;
	digit_number=1;
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
	    printf("number of digits = %d \n",digit_number);
	return EXIT_SUCCESS;
}
*/
//--------------------------------------------------------
/*
 * Assignment 1   Problem (18)
 *           int main(void)
   {

            	 for (int i =1; i <=5 ; i++)
            	    {
            	        for( int j=1 ; j<=i ; j++)
            	        {
            	            printf("* ");
            	        }
            	        printf("\n");
            	    }
        return EXIT_SUCCESS;
 }
 */
//--------------------------------------------------------
 /*
  * Assignment 1   Problem (19)
  *         int main(void)
   {

	for(int i =1 ; i<=5 ; i++)
	   {
	        for(int j =5 ; j>=i ; j--)
	        {
	            printf("* ");
	        }
	         printf("\n");
	   }
        return EXIT_SUCCESS;
 }
*/
//--------------------------------------------------------
  /*
   * Assignment 1   Problem (20)
   *         int main(void)
   {

	int point = 5;
	   for(int i =1 ; i<=5 ; i +=1)
	   {
	        for(int j =1 ; j<=9 ; j++)
	        {
	            if(j==point && i==1) printf("*");
	            else if ((j==point|| j==point+1||j==point-1)&& i==2 )
	            {
	                printf("*");

	            }
	            else if (((j==point|| j==point+2||j==point-2)||(j==point|| j==point+1||j==point-1))&& i==3)
	            {
	                printf("*");

	            }
	            else if ((((j==point|| j==point+2||j==point-2)||(j==point|| j==point+1||j==point-1))||(j==point|| j==point+3||j==point-3))&& i==4)
	            {
	                printf("*");

	            }
	            else if (((((j==point|| j==point+2||j==point-2)||(j==point|| j==point+1||j==point-1))||(j==point|| j==point+3||j==point-3))||(j==point|| j==point+4||j==point-4))&& i==5)
	            {
	                printf("*");

	            }
	            else
	            {
	                   printf(" ");
	            }

	        }
	         printf("\n");
	   }
        return EXIT_SUCCESS;
 }
*/
//--------------------------------------------------------
/*
 *  Assignment 1   Problem (21)
 *          int main(void)
 {
	for(int i =1 ; i<=10 ; i ++)
	   {
	       for(int j =1 ; j<=11 ;  j ++)
	       {
	           if( ((j==1)||(j==11)) && i==1) printf("*");
	           else if (((j==2)||(j==10)) && i==2) printf("*");
	           else if (((j==3)||(j==9)) && i==3) printf("*");
	           else if (((j==4)||(j==8)) && i==4) printf("*");
	           else if (((j==5)||(j==7)) && i==5) printf("*");
	           else if (((j==5)||(j==7)) && i==6) printf("*");
	           else if (((j==4)||(j==8)) && i==7) printf("*");
	           else if (((j==3)||(j==9)) && i==8) printf("*");
	           else if (((j==2)||(j==10)) && i==9) printf("*");
	           else if( ((j==1)||(j==11)) && i==10) printf("*");
	           else
	           {
	                printf(" ");
	           }
	       }
	       printf("\n");
	   }
        return EXIT_SUCCESS;
 }
*/
//--------------------------------------------------------
int main()
{
	 extern void fun (int x);
	   void fun (int x);
	return 0;
}
