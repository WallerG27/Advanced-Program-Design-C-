//Dr. Holloman's Coding Corner

#include <stdio.h>


void printReceipt(float total) {
    float tax = total * 0.07;
    float grandTotal = total + tax;
    printf("Receipt: \n");
    printf("Subtotal: $%.2f\n", total);
    printf("Tax (7%%) $%.2f\n", tax);
    printf("Grand Total: $%.2f\n", grandTotal);
}


//Add Totals
float getPrice(int item) {
    switch (item) {
        case 1: return 15.00;
        case 2: return 1.30;
        case 3: return 3.50;
        default: return 0.0;
    }
}


//Print Menu
void printMenu(){
    printf("Welcome to COP 3515 Cafe\n");
    printf("1. Steak Sandwhich - $15.00\n");
    printf("2. French Fries - $1.30\n");
    printf("3. Beverage - $3.50\n");
    printf("4. Exit\n");
    

}

//Main Logic Func
float takeOrder(){
   int choice;
   float total = 0.0;

   do{
        printMenu();
        printf("Please Enter Your Desired Choice 1- 4: \n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3) {
            total += getPrice(choice);
            printf("Item added! Current total is: $%.2f\n", total);
        } else if(choice != 4) {
            printf("Invalid Choice. Please Try Again.");
        }
   } while (choice != 4);

    return total;
}


int main () {
    float total = takeOrder();

    printReceipt(total);

    return 0;
}
