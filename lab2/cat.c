/* cat.c
 *
 * Assignment 2 
 * Name:Elizabeth Chan 
 * E-mail: lmchan
 * Desc:Program works exactly like the command-line "cat" runs in which
 * characters are entered and the program prints those characters. Program
 * ends when user clicks CTRL+D
 */

#include <stdio.h>

int main ()
{
  //declare the char c variable and asks user to enter characters
  char c;
  printf("Enter characters: ");

  //while loop runs into CTRL+D is entered
  //spits out entered characters in same format it was given in 
  while((c= getchar()) != EOF) {

    printf("%c", c);
    
   }
  
   return(0);
}
