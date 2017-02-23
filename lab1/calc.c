/* calc.c
*/ 
/*****************************************
 * Assignment 1
 * Name:    Kara Breeden and Elizabeth Chan 
 * E-mail: krbreeden@brynmawr.edu  & lmchan@brynmawr.edu 
 * Desc: Calculator part of Assignment 1. Program operates as if it was a 
 * calculator. User inserts an operation and two numbers and program  
 * prints the result. Program terminates when 0 is entered as an operation.
 *****************************************/

#include <stdio.h>

int main()
{
   int  num1, num2;
   char operation;
   int result;
   
   printf("Enter an operation: ");
   scanf(" %c", &operation);
   
   while (operation != '0')
   {  
     printf("Enter a number: "); 
     scanf("%d", &num1);
     printf("Enter a number: ");
     scanf("%d", &num2);
     if (operation == '-')
       {
       result = num1 -  num2; 
       }
     else  if (operation == '+')
       {
	 result = num1 + num2;
       }
     else  if (operation == '*')
       {
	 result = num1 * num2; 
       }
     else  if (operation == '/')
       {
	 result = num1 / num2;
       }
     else
       {
	 printf("Operation not valid. \n");
	 break; 
       }
     
     printf("%d %c %d = %d \n", num1, operation, num2, result);

     printf("Enter an operation: ");
     scanf(" %c", &operation); 
   }
 
   return 0;
}
