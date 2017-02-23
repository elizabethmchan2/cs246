/* matrix.c

   Name: Kara Breeden and Elizabeth Chan
   Resources used (websites, books other than our texts, peers):
   for recursion: https://en.wikipedia.org/wiki/Exponentiation_by_squaring

*/

#include "matrix.h"
#include <stdio.h>
#include <stdbool.h>


// checks to see if two NxM matrices are the same
bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m])
{
  if(n <= 0 || m <= 0){
    printf("Not a valid matrix.\n");
    return false;
  }else{
    for (int i = 0; i<n; i++) {
      for (int j = 0; j<m; j++) {
	if(mat1[i][j]!=mat2[i][j]) { //returns false when arrays are equal
	  return false;
	}
      }
    }
  }
  return true; //returns true if they are after checking each index
}

// prints an NxM matrix
void print_matrix(int n, int m, int mat[n][m])
{
  if(n <= 0 || m <= 0){
    printf("Not a valid matrix.\n");
  }else{
    for (int i = 0; i<n; i++) {
      for (int j = 0; j<m; j++) {
	printf("\t %d ", mat[i][j]);
      }
      printf("\n"); //moves numbers to next line
    }
  }
}


// fills in an NxN matrix with the identity matrix
void identity_mat(int n, int mat[n][n])
{
  if(n <= 0){
    printf("Not a valid matrix. Identity matrix not stored. \n");
  }else{
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
}


// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m])
{
  if(n <= 0 || m <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  }else{
    //nested for loop that multiplies each number in array by scalar
    for (int i = 0; i<n; i++) {
      for (int j = 0; j<m; j++) {
	result[i][j] = scalar * mat[i][j];
      }
    }
  }
}

// multiplies an N1xM1 matrix by a M1xM2 matrix, storing the result in `result`
void matrix_mult(int n1, int m1, int mat1[n1][m1],
                 int m2, int mat2[m1][m2],
                 int result[n1][m2])
{
  if(n1 <= 0 || m1 <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  }else if(m2 <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  }else{
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
}


// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow(int n, int mat[n][n], int power, int result[n][n])
{
  if(n <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  }else{
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
}



// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow_rec(int n, int mat[n][n], int power, int result[n][n])
{
  if(n <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  }else{
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
}
