/* adds.c 
/*****************************************
 * Assignment 1
 * Name:    Kara Breeden and Elizabeth Chan 
 * E-mail: krbreeden@brynmawr.edu  & lmchan@brynmawr.edu 
 * Desc: Adding lots of numbers program  of Assignment 1. 
 * Program adds many numbers together and continues to do so until 0 is entered.
 * Program then prints the sum of the numbers. 
 *****************************************/

#include <stdio.h>

int main()
{
   int  sum, entered_num;
   printf("Enter a number: "); 
   scanf("%d", &entered_num);
   sum = entered_num;

   while (entered_num != 0)
   {
      printf("Enter a number: ");
      scanf("%d", &entered_num);
      sum = sum  + entered_num; 
     
   }

   printf("Sum:  %d  \n", sum); 

   return 0;
}
