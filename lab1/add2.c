/* add2.c 
/*****************************************
 * Assignment 1
 * Name:   Kara Breeden and Elizabeth Chan 
 * E-mail: krbreeden@brynmawr.edu  & lmchan@brynmawr.edu 
 * Desc: Adding two numbers  program for Assignment 1. Will print add two
 * numbers that are inputed by user and then prints the result. 
 *****************************************/
 

#include <stdio.h>

int main() 
{

  int x, y, final;
  
  printf ("Enter a number:  ");
  scanf("%d", &x);
  printf ("Enter a number:  ");
  scanf("%d", &y);
  final = x+y; 
  printf ("%d + %d = %d \n", x, y, final ); 
  return 0;

}
