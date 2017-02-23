/* main.c

   Name:
*/


#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void print_matrix(int n, int m, int mat[n][m])
{
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
        printf("\t %d ", mat[i][j]);
        }
        printf("\n"); //moves numbers to next line
      }

    }


// fills in an NxN matrix with the identity matrix
void identity_mat(int n, int mat[n][n])
{
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (i==j) { //when i is equivalent to j, then set it equal to 1
        mat[i][j] = 1;
      }
      else { //when i is not equivalent to j, then set it equal to 0
        mat[i][j] = 0;
      }
    }
  }
}

// multiplies an N1xM1 matrix by a M1xM2 matrix, storing the result in `result`
void matrix_mult(int n1, int m1, int mat1[n1][m1],
                 int m2, int mat2[m1][m2],
                 int result[n1][m2])
{
  //nested for loop that multiples correct rows and columns and adds products accordingly
  //values are then stored in total and placed in correct index in result array
  //total is then set back to zero
  int total = 0;
  for(int h = 0; h<n1; h++){
    for (int i = 0; i<m2; i++) {
      for (int j = 0; j<m1; j++) {
        total = total + (mat1[h][j] * mat2[j][i]);
      }
      result[h][i] = total;
      total = 0;
    }
  }
}

// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m])
{
  //nested for loop that multiplies each number in array by scalar
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      result[i][j] = scalar * mat[i][j];
    }
  }
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow(int n, int mat[n][n], int power, int result[n][n])
{
  if (power == 0) { //checks when power is 0
    identity_mat(n, result);
  }
  else if (power == 1) { //checks when power is 1
    scalar_mult(1, n, n, mat, result);
  }
  else {
    int temp[n][n];
    scalar_mult(1, n, n, mat, temp);

    for (int i = 0; i<power-1; i++) {
      matrix_mult(n, n, mat, n, temp, result);
      scalar_mult(1, n, n, result, temp);
    }
  }
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow_rec(int n, int mat[n][n], int power, int result[n][n])
{
  int temp[n][n]; //creates array to temporarily store array

  if (power == 0) { //checks when power is 0
    identity_mat(n, result);
  }
  else if (power == 1) { //checks when power is 1
    scalar_mult(1, n, n, mat, result);
  }
  else if (power % 2 == 0 ) { //checks when power is even
    matrix_mult(n, n, mat, n, mat, temp);
    matrix_pow_rec(n, temp, power/2, result);

  }
  else if (power % 2 != 0 ) { //checks when power is odd
    matrix_mult(n, n, mat, n, mat, temp);
    matrix_pow_rec(n, temp, (power-1)/2, temp);
    matrix_mult(n, n, mat, n, temp, result);
  }
}



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
