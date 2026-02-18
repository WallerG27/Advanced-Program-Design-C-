/*This is a comment*/
/*
 * AHPA #3: Ice Cream
 *
 * Bob’s Ice Cream sells four types of ice cream: vanilla, chocolate,
 * mint, and strawberry.
 *
 * Bob's Ice Cream sells ice cream from trucks that are parked at two 
 * different corners. They sold {$11.5, $15.75, $22, $7.25} on Saturday 
 * and {$12.75, $9.25, $16.5, $21} on Sunday [note sales are in vanilla, 
 * chocolate, mint, and strawberry order].
 *
 * Create an enum for flavors:enum flavors {vanilla, chocolate, mint, 
 * strawberry};
 *
 * Create a program that allows a user to enter the type of ice cream 
 * sold.
 *
 * Create a program that allows a user to enter the sales data.
 * 
 * Load two one-dimensional arrays with Bob’s entered sales data. Only 
 * index your arrays using an enum variable (enum flavors index = 
 * vanilla; corner1Sales[index] = 11.5;)
 *
 * Sum the contents of the flavors in the arrays together.
 *
 * Print out the resulting flavors and their sum with Bob's total sales.
 *
 * Student Name: Gavin
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void) {
    /*Variable Declarations*/
    enum flavors {vanilla, chocolate, mint, strawberry};
    const char* flavorNames[] = {"Vanilla", "Chocolate", "Mint", "Strawberry"};
    double SatSales[4] = {11.5, 15.75, 22, 7.25};
    double SunSales[4] = {12.75, 9.25, 16.5, 21};

    double InputSatSales[4];
    double InputSunSales[4];

    /*Enum Indices*/
    enum flavors index;

    /*Saturday Sales*/
    SatSales[vanilla]    = 11.5;
    SatSales[chocolate]  = 15.75;
    SatSales[mint]       = 22;
    SatSales[strawberry] = 7.25;

    /*Sunday Sales*/
    SunSales[vanilla]    = 12.75;
    SunSales[chocolate]  = 9.25;
    SunSales[mint]       = 16.5;
    SunSales[strawberry] = 21.0;

    /*
    Calculate Totals Var
    I have written daily so many times it looks wrong
    */
    double satDailyTotal = 0.0;
    double sunDailyTotal = 0.0;
    double satGrandTotal = 0.0;
    double sunGrandTotal = 0.0;
    double dailyTotal = 0.0;
    double grandTotal = 0.0;

    /*Input For Saturday*/
    printf(" Enter Saturday sales for each flavor:\n");
    for (index = vanilla; index <= strawberry; index++) {
        printf("%s: $", flavorNames[index]);
        scanf("%lf", &InputSatSales[index]);
    }

    /*Input For Sunday*/
    printf("\n Enter Sunday sales for each flavor:\n");
    for (index = vanilla; index <= strawberry; index++) {
        printf("%s: $", flavorNames[index]);
        scanf("%lf", &InputSunSales[index]);
    }

    printf("\n Total Sales per Flavor:\n");
    /*Calculate Total Sales*/
    for (index = vanilla; index <= strawberry; index++) {
        /*Saturday Sales*/
        satDailyTotal = SatSales[index] + InputSatSales[index];
        satGrandTotal += satDailyTotal;

        /*Sunday Sales*/
        sunDailyTotal = SunSales[index] + InputSunSales[index];
        sunGrandTotal += sunDailyTotal;
        
        /*Total Sales*/
        dailyTotal = satDailyTotal + sunDailyTotal;
        printf("%s: $%.2f\n", flavorNames[index], dailyTotal);
        grandTotal += dailyTotal;
        dailyTotal = 0;
    }

    /*Print Day Totals*/
    printf("\n Bob's Total Sales Per Day:\n");
    printf("Saturday Total: $%.2f\n", satGrandTotal);
    printf("Sunday Total: $%.2f\n", sunGrandTotal);

    /*Print Totals*/
    printf("\n Bob's Total Sales: $%.2f\n", grandTotal);

    return 0;
}