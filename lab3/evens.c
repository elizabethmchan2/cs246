/* evens.c
 *
 * Name:Amanda Quintero and Elizabeth Chan
 * Email: aquintero@haverford.edu and lmchan@brynmawr.edu
 * Desc: Function prints out numbers that user in puts, evens first and then odds.
 * Program outputs numbers when 0 is entered
 */
#include <stdio.h>
#include <math.h>

int main() {

  int numbers[10];
  //int size_evens, size_odds;
  int i = 0, num;

  printf("Enter up to ten numbers:\n"); //asks user to give up to ten numbers
  do {
    scanf("%d", &num); //scans numbers and saves number into an array
    numbers[i] = num;
    i++;
  } while(i < 10 && num !=0); //checks if input is less than 10 numbers and is not zero

   for (int j = 0; j<i-1; j++){ //iterates through array in which the boundary is one less than the number of nums (-1 to not consider zero)

      if (numbers[j] % 2 == 0) { //checks if number is even
         printf("%d\n", numbers[j]); //prints them
      }
    }

    for (int j = 0; j<i-1; j++){ //checks if number is odd
      if (numbers[j] % 2 == 1) { //prints them
	       printf("%d\n", numbers[j]);
      }
    }

   return 0;
}
