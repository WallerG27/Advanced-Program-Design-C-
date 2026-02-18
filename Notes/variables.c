// Dr. Kateology's Koding Korner
// September 23, 2025

// This code reflects a program that needs a little help with redesigning.
// What wouold you add/correct?

#include <stdio.h>

// Global variable (used improperly!)
int potionStock = 10;

void brewPotion() {
    int potionStock = 5; // Local variable shadows global
    printf("\nBrewing a potion... Stock: %d\n", potionStock);
    potionStock--;
}

void checkStock() {
    printf("\nGlobal potion stock is: %d\n", potionStock);
}

void refillStock() {
    //This is the global variable bc you are NOT 
    //reinitializing the same data type + same variable name.
    potionStock += 3; 
    printf("\nRefilled global potion stock. New total: %d\n", potionStock);
}

int main() {
    printf("\nWelcome to Dr. Kateology's Potion Lab!\n\n");

    checkStock(); //Check current stock first

    brewPotion();
    checkStock();  // Unexpected result?

    refillStock();
    brewPotion();

    checkStock();  // Is this what you expected?

    return 0;
}
