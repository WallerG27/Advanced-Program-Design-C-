/*This is a comment*/
/*
 * AHPA #8: The C ATM Machine
 *
 * Two people, "a" and "b", have checking and savings accounts. 
 *
 * Create a 2x2 array to hold their amounts: a – checking: $500, savings: 
 * $1,000; b – checking: $750, savings: $325.
 *
 * Have the ATM machine ask the user their name.
 *
 * Ask the user if they want to withdraw from their checking or their 
 * savings account.
 *
 * Use a switch statement to process different types of accounts.
 *
 * Create software that will provide an ATM user with the proper change 
 * for any dollar amount up to $200.
 *
 * Example: Run the code for $19, $55, and $200.
 *
 * Student Name: Gavin
 */
/*ChatGPT helped bug fix because idk what is auto grader wanted*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void) {
  /*2x2 Array*/
  int accounts[2][2] = {
    {500, 1000}, /*a*/
    {750, 325} /*b*/
  };
  /*Variables*/
  char name;
  int personIndex;
  char accountType;
  int accountIndex;
  int amount;
  int withdrawAmount;
  int bill;



  /*Checks Name*/
  printf("Enter your name:\n");
  scanf(" %c", &name);

  if (name == 'a') personIndex = 0;
    else if (name == 'b') personIndex = 1;
    else {
        printf("Invalid name, try again.\n");
        return 1;
    }
    
    accountIndex = 1;
    /*Checks Account Type*/
  printf("Would you like to withdraw from (c)hecking or (s)avings?\n");
  scanf(" %c", &accountType);

  
switch (accountType) {
  case 'C':
  case 'c': accountIndex = 0;
    break;
  case 'S':
  case 's': accountIndex = 1;
    break;
	  default: printf("Invalid account type.\n");
    accountIndex = 1;
	  return 1;
}

/*Amount check which I keep forgetting about*/
  printf("How much would you like to withdraw?\n");
  scanf(" %d", &amount);

  if ( amount > 200) {
      printf("Amount is greater than 200, please enter a valid amount.\n");
      return 1;
  }


/* Deduct amount */
    withdrawAmount = amount;
    accounts[personIndex][accountIndex] -= amount;

    /*Math*/
    printf("Amount in account to be withdrawn from: $%d\n", amount);
    int temp = withdrawAmount;
    while (temp > 0) {
        bill = 0;
          if (temp >= 100) {
              temp -= 100;
              bill = 100;
          }
          else if (temp >= 50) {
              temp -= 50;
              bill = 50;
          }
          else if (temp >= 20) {
              temp -= 20;
              bill = 20;
          }
          else if (temp >= 10) {
              temp -= 10;
              bill = 10;
          }
          else if (temp  >= 5) {
              temp  -= 5;
              bill = 5;
          }
          else if (temp  >= 1) {
              temp  -= 1;
              bill = 1;
      }
      printf("$   %d bill\n", bill);
    }
    
    printf("Amount in account after withdrawal: $%d\n", accounts[personIndex][accountIndex]);
  return 0;
}