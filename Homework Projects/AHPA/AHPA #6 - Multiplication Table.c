/*This is a comment*/
/*
 * AHPA #6:Multiplication Table
 *
 * Write a program in C to display the 
 * multiplication table for numbers 1-12 in 
 * a square table.
 *
 * Create a number guessing game that sets 
 * a number and then allows the user to 
 * guess it. The number will be between 1 
 * and 10.
 *
 * To calculate a random number between 
 * 1-10 for the game use:
 * int guessAnswer = (rand() % 20) + 1;
 *                          // random number
 *
 * Student Name: Gavin
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
  //variable declarations
  int row;
  int column;

//print the multiplication table
printf("Multiplication Table\n");
for (row = 1; row <= 12; row++) {
  for (column = 1; column <= 12; column++) {
    printf("%4d", row * column);
  }
  printf("\n");
}
printf("\n");
//number guessing game
int guessAnswer = (rand() % 20) + 1;
printf("Enter your guess (1-10)\n");

//get users guess
int userGuess;
scanf("%d", &userGuess);

//loop until user guesses the correct number
while (userGuess != guessAnswer) {

  if (userGuess > guessAnswer) {
    printf("Too high!\n");
  } else if (userGuess < guessAnswer) {
    printf("Too low!\n");
  } else {
    printf("Idk how you got here.\n");
  }
  printf("Enter your guess (1-10)\n");
  scanf("%d", &userGuess);
}

//user guessed the correct number
    printf("You guessed it!\n");
  return 0;
}