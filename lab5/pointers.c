/* pointers.c

   Name:
   Resources used (websites, books other than our texts, peers):

*/

#include <stdlib.h>

#include "pointers.h"

/* Returns whether or not the region pointed to by p1 (of length n)
   overlaps with the region pointed to by p2 (of length m). Do not
   assume that p2 is greater than p1. */
 bool overlaps(int n, int* p1, int m, int* p2)
 {
   if (p1 == p2) { //checks if array are the same
     return true;
   }
   if (p1 < p2 ) {
     if (p1 + n > p2) { //checks if p2 is larger than p1
       return true;
     }
   }
   if (p2 < p1) { //checks if p1 is larger than p2
     if (p2 + m > p1) {
       return true;
     }
   }
   else { //if none of these cases, return false
     return false;
   }
 }

 /* Changes the value in *a, *b, and *c so that *a, *b, and *c are
    in non-decreasing order. */
 void minisort(int* a, int* b, int* c)
 {
   if (*a > *b) { //checks if a is greater than b and if so, swap
     int temp = *a;
     *a = *b;
     *b = temp;
   }
   if (*b > *c) { //checks if b is greater than c and if so, swap
     int temp = *b;
     *b = *c;
     *c = temp;
   }
   if (*a > *c) { //checks if a is greater than c and if so, swap
     int temp = *a;
     *a = *c;
     *c = temp;
   }
 }

 /* Computes the sum of the ints that sit in memory between p
    (inclusive) and q (exclusive). You may assume that q comes
    after p -- that is, q >= p. */
 int partial_sum(int* p, int* q)
 {
   int sum = 0;
   while (p<q) { //continues while p is less than q
     sum += *p; //adds value at p to sum
     p++;
   }
   return sum; //return sum
 }


/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
 int check_line(int* start, int step, int n)
 {
   int winner = 0;
   for (int i=0; i<n; i++) { //iterates through i until n
     int x = i * step; //x represents each step value as i increases
     if(*(start + x) == *start) {  //checks whether values are all the same
       winner = *start;
     } else { //if not return blank
       return BLANK;
     }
   }
   return winner; //if so return winner (X or O)
 }

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
 int tic_tac_toe_winner(int n, int* board)
 {
   //checking rows
   for (int r = 0; r < n; r++) {
     int winner = check_line(board+(n*r), 1, n);
     if (winner != BLANK) { //if not blank, return winner
       return winner;
     }
   }

   //checking columns
   for (int c = 0; c < n; c++) {
     int winner = check_line(board+c, n, n);
     if (winner != BLANK) { //if not blank, return winner
       return winner;
     }
   }

   //checking major diagonal
   int x = check_line(board, n+1, n);
   if (x != BLANK) { //if not blank, return winner
     return x;
   }
   //checking other major diagonal
   int y = check_line(board+(n-1), n-1, n);
   if (y != BLANK) { //if not blank, return winner
     return y;
   }
   else {
     return BLANK; //if none of the cases return, return blank
   }
   return 0;
 }
