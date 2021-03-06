/* shout.c
 * Assignment 2 
 * Name:Elizabeth Chan 
 * E-mail:lmchan@brynmawr.edu
 * Desc: Program returns user input in all caps using arthimetic and isalpha 
 */

#include <stdio.h>
#include <ctype.h>   // for isalpha

int main() {
  //creates variable ch as a char 
  char ch; 

  //while loop continues as long as user doesn't input CTRL+d
  //prints user input in all caps 
  while((ch = getchar()) !=EOF) {
    if(isalpha(ch)) { //checks if its in the alphabet 

      if('a' <= ch && ch<='z') { //prints if its lowercase into uppercase 
        ch = ch - 'a' + 'A';
	printf("%c", ch);
	 }

      else { //if its not in lowercase it prints what it was given 
	putchar(ch);
      }
    }
    else { //if its not in the alphabet it prints what its given 
      putchar(ch);

    } 
  }
  
  return 0;

}
