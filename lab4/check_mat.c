/* check_mat.c

   Name: Kara Breeden and Elizabeth Chan

   Unit tests for the matrix functions.

   These tests use the `check` library, available here:
   https://libcheck.github.io/check/

   Documentation for the functions is here:
   https://libcheck.github.io/check/doc/doxygen/html/check_8h.html

   When linking this file into an executable (with `gcc -o`), make sure
   to pass in `-lcheck` to link to the "check" library. For example,
   to compile this with the matrix.c file you would do

     gcc -c matrix.c
     gcc -c check_mat.c
     gcc -o check_mat matrix.o check_mat.o -lcheck

   or, if you wanted to compile and link at the same time,

     gcc -o check_mat matrix.c check_mat.c -lcheck
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "matrix.h"

START_TEST(test_eq_matrix)
{
  //testing if true when mat1 is set equal to itself, mat2 is set equal to itself
  //testing if false when mat1 is set equal to mat2
  int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
  int mat2[2][3] = { {7, 8, 9}, {10, 11, 12} };
  ck_assert(eq_matrix(2, 3, mat1, mat1));
  ck_assert(eq_matrix(2, 3, mat2, mat2));
  ck_assert(!eq_matrix(2, 3, mat1, mat2));
}
END_TEST

START_TEST(test_identity_mat)
{
  //testing if ident is equal to result
  int ident[2][2] = { {1, 0}, {0, 1} };
  int result[2][2];
  identity_mat(2, result);
  int ident2[6][6] = { {1, 0, 0, 0, 0, 0},
		      {0, 1, 0, 0, 0, 0},
		      {0, 0, 1, 0, 0, 0},
		      {0, 0, 0, 1, 0, 0},
		      {0, 0, 0, 0, 1, 0},
		      {0, 0, 0, 0, 0, 1} };
  int result2[6][6];
  identity_mat(6, result2);
  ck_assert(eq_matrix(2, 2, ident, result));
  ck_assert(eq_matrix(6, 6, ident2, result2));
}
END_TEST


START_TEST(test_scalar_mult)
{
  //testing if mat2 is equal to mat1 * 2
  int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
  int mat2[2][3] = { {2, 4, 6}, {8, 10, 12} };
  int mat3[2][3] = { {5, 10, 15}, {20, 25, 30} };
  int result[2][3];
  scalar_mult(2, 2, 3, mat1, result);
  int result2[2][3];
  scalar_mult(5, 2, 3, mat1, result2);
  ck_assert(eq_matrix(2, 3, result, mat2));
  ck_assert(eq_matrix(2, 3, result2, mat3));
}
END_TEST

START_TEST(test_matrix_mult)
{
  //testing if mat3 is equal to mat1 * mat2 
  int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
  int mat2[3][2] = { {7, 8}, {9, 10}, {11, 12}  };
  int mat3[2][2] = { { 58, 64}, {139, 154 } };
  int result[2][2];
  int mat4[3][3];
  identity_mat(3, mat4);
  int result2[3][3];
  matrix_mult(2, 3, mat1, 2, mat2, result);
  matrix_mult(2, 3, mat1, 3, mat4, result2);
  ck_assert(eq_matrix(2, 2, result, mat3));
  ck_assert(eq_matrix(2, 2, result2, mat1));
}
END_TEST

START_TEST(test_matrix_pow)
{
  int mat1[2][2] = { {1, 2 }, {3, 4} };

  //checking power of 0
  int identity[2][2];
  identity_mat(2, identity);
  int result[2][2];
  matrix_pow(2, mat1, 0, result);
  ck_assert(eq_matrix(2, 2, identity, result));

  //checking power of 1
  int result1[2][2];
  matrix_pow(2, mat1, 1, result1);
  ck_assert(eq_matrix(2, 2, mat1, result1));

  //checking power of even
  int squared[2][2] = { { 7, 10}, { 15, 22 } };
  int result2[2][2];
  matrix_pow(2, mat1, 2, result2);
  int even[2][2] = { { 165751, 241570}, { 362355, 528106} };
  int result4[2][2];
  matrix_pow(2, mat1, 8, result4);
  ck_assert(eq_matrix(2, 2, squared, result2));
  ck_assert(eq_matrix(2, 2, even, result4));

  //checking power of odd
  int cubed[2][2] = { { 37, 54 }, { 81, 118 } };
  int result3[2][2];
  matrix_pow(2, mat1, 3, result3);
  ck_assert(eq_matrix(2, 2, cubed, result3));
  int odd[2][2] = { { 1069, 1558 }, { 2337, 3406 } };
  int result5[2][2];
  matrix_pow(2, mat1, 5, result5);
  ck_assert(eq_matrix(2, 2, odd, result5));
}
END_TEST

START_TEST(test_matrix_pow_rec)
{
  int mat1[2][2] = { {1, 2 }, {3, 4} };

  //checking power of 0
  int identity[2][2];
  identity_mat(2, identity);
  int result[2][2];
  matrix_pow(2, mat1, 0, result);
  ck_assert(eq_matrix(2, 2, identity, result));

  //checking power of 1
  int result1[2][2];
  matrix_pow(2, mat1, 1, result1);
  ck_assert(eq_matrix(2, 2, mat1, result1));

  //checking power of even
  int squared[2][2] = { { 7, 10}, { 15, 22 } };
  int result2[2][2];
  matrix_pow(2, mat1, 2, result2);
  int even[2][2] = { { 165751, 241570}, { 362355, 528106} };
  int result4[2][2];
  matrix_pow(2, mat1, 8, result4);
  ck_assert(eq_matrix(2, 2, squared, result2));
  ck_assert(eq_matrix(2, 2, even, result4));

  //checking power of odd
  int cubed[2][2] = { { 37, 54 }, { 81, 118 } };
  int result3[2][2];
  matrix_pow(2, mat1, 3, result3);
  ck_assert(eq_matrix(2, 2, cubed, result3));
  int odd[2][2] = { { 1069, 1558 }, { 2337, 3406 } };
  int result5[2][2];
  matrix_pow(2, mat1, 5, result5);
  ck_assert(eq_matrix(2, 2, odd, result5));
}
END_TEST

START_TEST(test_matrix_pow_vs_matrix_pow_rec)
{
  //creating random matrix
  int mat1[5][5];
  for(int i=0; i<5; i++) { //fills 5x5 array with random integers from 0 to 100
    for(int j=0; j<5; j++) {
  	    mat1[i][j] = rand()/(double)RAND_MAX*100;
    }
  }
  int random_power = rand()/(double)RAND_MAX*100; 
  int result1[5][5];
  matrix_pow(5, mat1, random_power, result1); 
  int result2[5][5];
  matrix_pow_rec(5, mat1, random_power, result2);
  
  //checking
  ck_assert(eq_matrix(5, 5, result1, result2));
}
END_TEST

// the main() function for unit testing is fairly prescribed.
// Just copy & paste, but make sure to update the test names!
int main()
{
  // `check` allows for multiple test suites, but we'll always
  // just have one, called "main"
  Suite* s = suite_create("main");

  // Inside a suite are potentially many `TCase`s.
  TCase* tc = tcase_create("matrix");

  // Each TCase can have many individual testing functions.
  tcase_add_test(tc, test_eq_matrix);
  tcase_add_test(tc, test_identity_mat);
  tcase_add_test(tc, test_scalar_mult);
  tcase_add_test(tc, test_matrix_mult);
  tcase_add_test(tc, test_matrix_pow);
  tcase_add_test(tc, test_matrix_pow_rec);
  tcase_add_test(tc, test_matrix_pow_vs_matrix_pow_rec);

  // Having set up the TCase, add it to the suite:
  suite_add_tcase(s, tc);

  // To run the tests, we need a runner:
  SRunner* sr = srunner_create(s);

  // You can see options for running only some of the tests at
  // the documentation link above. The CK_NORMAL indicates to
  // print only failing tests.
  srunner_run_all(sr, CK_NORMAL);

  // after running, we can retrieve the number of failures
  int number_failed = srunner_ntests_failed(sr);

  // We're done now with the testsuite, so dispose of it properly
  srunner_free(sr);

  // conveniently, number_failed makes a nice exit code.
  // a non-zero answer means a failed test!
  return number_failed;
}
