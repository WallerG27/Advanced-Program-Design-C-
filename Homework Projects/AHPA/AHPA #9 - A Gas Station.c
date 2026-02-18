/*This is a comment*/
/*
 * AHPA #9: A Gas Station
 *
 * You have been asked to create a C program to manage the gas 
 * pumps at a gas station. The station has four pumps connected 
 * to four tanks with capacities: 100, 75, 50, and 150. Every 
 * time a car fills up it takes 10 gallons. You’ll know that a 
 * car has arrived because the carArrived function will return 
 * with a pump number. After a car has filled up, print out the 
 * current contents of all four tanks.
 *
 * Write a program that can track each of the four tanks. 
 * Update the amount of gas remaining in a tank when a car 
 * fills up. When a tank gets to less than 20 gallons of gas 
 * remaining, make a call to request a refill truck visit the 
 * station (refillRequest). This will cause the tank to be
 * refilled automatically.
 *
 * Student Name: Gavin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function Name: carArrived
 *
 * Description: Returns a random integer between 1-4.
 *
 * Input: None
 *
 * Output: Random integer between 1-4
 *
 */

const int caps[4] = {100, 75, 50, 150};
int tanks [4] = {100, 75, 50, 150};

int carArrived (void) {
  int randomnumber;

  /* Generate a random number between 0-10. Keep generating numbers
   * until you generate one that is between 0-3. */
  
  do {
    randomnumber = rand() % 10;  
  } while (randomnumber > 3);

  /* Add one to the generated random number to make it between 1-4 */
  return randomnumber+1;
}

void TankPrints (void) {
  int i;
  printf("Tanks: [");
  for (i=0; i<4; i++) {
    printf("%d", tanks[i]);
    if (i < 3) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main(void) {
  int NumCars, S;
  scanf("%d", &NumCars);
  scanf("%d", &S);
  /* Initialize the random number generator based on current time */
  srand(S);
  int pumpNumber;
  int i;
  while (NumCars > 0) {
    pumpNumber = carArrived();
    printf("Pump %d: -10 gal\n", pumpNumber);
    tanks[pumpNumber-1] -= 10;
    
    TankPrints();

    
    for (i=0; i<4; i++) {
      if (tanks[i] < 20) {
        tanks[i] = caps[i];
        printf("Refill: Tank %d refilled to %d\n", i+1, caps[i]);
        TankPrints();
      }
    }

    NumCars -= 1;
  }
  return 0;
}