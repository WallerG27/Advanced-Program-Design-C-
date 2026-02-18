/*This is a comment*/
/*
 * AHPA #10: The Secure Array
 *
 * Using pointers, access Peter's array without him knowing it 
 * and place three values that you got from the user (101, 63, 
 * 21) at locations 3, 6, and 9. Recalculate the sum value and 
 * update it.
 *
 * Student Name: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void) {
  int theArray[] = {54,2,3,4,5,6,7,8,9,10}; 
  int value, position;

  for (int i = 0; i < 3; i++) {
    printf("Enter value and position (1-9): ");
    scanf("%d %d", &value, &position);
    if (position < 1 || position > 9) {
      printf("Try a number 1-9, it might work better.\n");
      i--; // let's them still input 3 times
      continue;
    }
    *(theArray + position) = value; // Update the array using pointer arithmetic
    // Recalculate the sum
    theArray[0] = 0;
    // Sum the other elements
    for (int j = 1; j < 10; j++) {
      theArray[0] += *(theArray + j);
    }
  }
  //prints the array
  for (int i = 0; i < 10; i++) {
    printf("%d ", *(theArray + i));
  }
  return 0;
}