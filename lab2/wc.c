/* wc.c
 *
 * Name:Elizabeth Chan
 * E-mail: lmchan@brynmawr.edu
 * Desc: Program prints number of words characters and lines based
 * off of user input
 */

#include <stdio.h>
#include <ctype.h>   // for isalpha

int main() {

  //creates variable ch as a char 
  char ch; 
  int characters = 0;
  int words = 0;
  int lines = 0;
  
  //while loop continues as long as user doesn't input CTRL+d
  //prints number of characters, words and lines in that order 
  while((ch = getchar()) != EOF) {
       
      characters++;

      if(isspace(ch)) {
       	words++;
	  if(ch == '\n') {
	    lines++;
	  }
  }
      /* if(ch == ' ') {
	  words = words -1;
	  }*/
  }
 
	  

    printf("%d \n", characters);
    printf("%d \n", words);
    printf("%d \n", lines);
	
      
  return 0;

}


