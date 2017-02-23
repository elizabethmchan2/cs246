/* fifteen.c
 *
 * Name: Amanda Quintero and Elizabeth Chan
 * Email: aquintero@haverford.edu and lmchan@brynmawr.edu
 * Desc: Allows the user to play the "Fifteen puzzle"
 */

#include <stdio.h>
#include <stdbool.h>


// These lines define constants which can be used throughout your program
// to aid in your code. They are explained on p. 315 of King and have a
// nice introduction on this page:
// http://www.dummies.com/programming/c/how-to-declare-and-use-constants-in-the-c-language/

// representation for the empty spot in the puzzle
#define BLANK        0

// side-length of the puzzle
#define PUZZLE_SIZE  4

// arrays do strange and wonderful things when passed as parameters, so we'll just
// use a global variable. This puzzle variable is accessible anywhere in your program.
int puzzle[PUZZLE_SIZE][PUZZLE_SIZE]
=  { {1, 10, 15,     4},
      {13, 6,  3,     8},
      {2,  9, 12,     7},
      {14, 5, BLANK, 11} }; // global puzzle array

int puzzle_solved[PUZZLE_SIZE][PUZZLE_SIZE]
  = { {1,   2,  3,      4},
      {5,   6,  7,      8},
      {9,  10, 11,     12},
      {13, 14, 15,  BLANK} };

// the functions below are a suggestion for a way to write this assignment, though
// they are not a requirement

// prints the puzzle
void print_puzzle()
{
  for (int i = 0; i<PUZZLE_SIZE; i++) { //iterates through 2D array
    for (int j = 0; j<PUZZLE_SIZE; j++) {
      if(puzzle[i][j] == BLANK) {
        printf("\t"); //replaces 0 with blank space
      } else {
        printf("\t %d ", puzzle[i][j]); //prints puzzle
        }
      }
      printf("\n"); //prints like a puzzle instead of one straight line
    }

}

// prompts the user to enter a tile number and returns that number
int prompt()
{
  int tile;
  printf("Enter the title you would like to move: "); //asks users to give tile they want to move
  scanf("%d", &tile);
  return tile;
}


// returns true when the puzzle is solved
bool solved()
{
  for(int i = 0; i<PUZZLE_SIZE; i++) { //iterates through 2D array
    for(int j=0; j<PUZZLE_SIZE; j++) {
      if(puzzle[i][j] != puzzle_solved[i][j]) { //checks if arrays are equal
	       return false; //if not returns false
       }
     } //closes i loop
   } //closes j loop
  return true; //if so returns true
}

// moves the tile in the puzzle, if possible.
void move_tile(int tile) //moves tile to blank space
{
  int temp1 = 0; //variables to save the coordinates of the tile chosen
  int temp2 = 0;
  if(tile >15 || tile <=0)  { //checks if tile is greater than 15 or less than 0
	printf("Invalid tile.\n");
  }
  else {
    for (int i = 0; i<PUZZLE_SIZE; i++) { //checks if tile is within array
    for (int j = 0; j<PUZZLE_SIZE; j++) {
      if (tile==puzzle[i][j]) {
	       temp1 = i; //saves tile's coordinates into temporary variables
	       temp2 = j;

        if(puzzle[temp1+1][temp2] == BLANK){ //checks if neighbor below is blank

          puzzle[i+1][j] = tile; //replaces blank with tile chosen
	        puzzle[temp1][temp2] = BLANK; //replaces tile's original location with blank
	        print_puzzle(); //prints puzzle
	        goto done; //go to done which checks if its solved and if not runs through function again


        }
        else if(puzzle[temp1-1][temp2] == BLANK){ //checks if neighbor above is blank

        	puzzle[i-1][j] = tile; //same as above
        	puzzle[temp1][temp2] = BLANK;
          print_puzzle();
          goto done;


        }
        else if(puzzle[temp1][temp2+1] == BLANK){ //checks if right neighbor is blank

        	 puzzle[i][j+1] = tile; //same as above
        	 puzzle[temp1][temp2] = BLANK;
        	 print_puzzle();
        	 goto done;

        }
        else if(puzzle[temp1][temp2-1] == BLANK){ //checks if left neighbor is blank

        	 puzzle[i][j-1] = tile; //same as above
        	 puzzle[temp1][temp2] = BLANK;
        	 print_puzzle();
        	 goto done;
        }

        else{
      	printf("I can't move that tile.\n"); //if no spaces are blank around it then returns statement
          }
        }
      } //closes j for loop
    } //closes i for loop
  } //closes first else statement

  done: if(solved() == true) { //checks if puzzle is solved
      printf("Solved!\n");
    } else { move_tile(prompt()); //if not, function is called again on new tile chosen
      }

} //closes move_tile




int main()
{
  print_puzzle(); //prints initial puzzle
  //asks what tile to move, checks if tile can be moved/valid,checks if puzzle is solved
  move_tile(prompt());
  return 0;
}
