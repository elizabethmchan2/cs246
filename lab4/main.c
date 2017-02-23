/* main.c

   Name: Kara Breeden and Elizabeth Chan
   Email: kbreeden@brynmawr.edu and lmchan@brynmawr.edu
   Description: Program creates random integers and stores it in a 50x50 matrix, then
   displays the difference in time between recurisve and non-recursive matrix power
   algorithm.
*/

#include "matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
  //declares arrays for random integers to be stored in after calling matrix_pow_rec and matrix_pow
  int final[50][50];
  int final1[50][50];
  //sets srand seed to time
  srand(time(NULL));
  int result[50][50];
  int i, j;
  for(i=0; i<50; i++) { //fills 50x50 array with random integers from 0 to 100
    for(j=0; j<50; j++) {
  	    result[i][j] = rand()/(double)RAND_MAX*100;
    }
  }
  //print_matrix(50, 50, result);


  //calculates time for non-recursive function
  clock_t tic1 = clock();
  matrix_pow(50, result, 50, final);
  printf("Elapsed time for non-recursive: %lu clock ticks\n", clock()-tic1);

  //calculates time for recursive function
  clock_t tic2 = clock();
  matrix_pow_rec(50, result, 50, final1);
  printf("Elapsed time for recursive: %lu clock ticks\n", clock()-tic2);


  return 0;
}
