/* triple.c
 *
 * Name:Amanda Quintero and Elizabeth Chan
 * Email: aquintero@haverford.edu and lmchan@brynmawr.edu
 * Desc: Function prints out numbers that user in puts expect if it notices a runs
 * then it will not print that run and print the rest of the numbers
 * Program outputs numbers when 0 is entered
 */


#include <stdio.h>
#include <math.h>
#include <stdbool.h>



int main() {

 bool checker = false;
 int numbers[10];
 int i = 0, num;
 printf("Enter up to ten numbers:\n");

  do {
    scanf("%d", &num); //scans input and puts it into an array
    numbers[i] = num;
    i++;
  } while(i < 10 && num !=0); //checks if input is less than 10 numbers and number is not 0

  int start = 0;
  for (int j=0; j<i; j++){
    if ((numbers[j+1]) == (numbers[j]+1) && (numbers[j+2]) == (numbers[j]+2) ) {

      start = j;
    /*  printf("start %d", start);
      printf(" a1: %d",  numbers[start] );
      printf(" a2: %d", numbers[start+1] );
      printf(" a2: %d", numbers[start+2] ); */
      checker = true;
    }
  }



if (checker == true) {
  printf("run found\n");
  numbers[start] = 0;
  numbers[start+1] = 0;
  numbers[start+2] = 0;
  /*printf("start: %d", start);
  printf(" b1: %d",  numbers[start-1] );
  printf(" b2: %d", numbers[start] );
  printf(" b3: %d", numbers[start+1] ); */
  for (int k=0; k<i; k++) {
    if(numbers[k] != 0) {
    printf("%d\n", numbers[k]);
    }
  }
}
if(checker == false){
  printf("no run found\n");
   for (int k=0; k<i; k++) {
    printf("%d\n", numbers[k]);
    }
  }
}
