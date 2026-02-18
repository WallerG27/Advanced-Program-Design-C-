/*This is a comment.*/
/*
 * Your program should read two lines from the user:

Line 1 – a number (the temperature value to convert)

Line 2 – a single character:

C → convert the entered value (assumed Fahrenheit) to Celsius

F → convert the entered value (assumed Celsius) to Fahrenheit

Examples of input:

100
C
0
F
 

Output Format
Your program must print the converted temperature as a number.

You may include text around it (e.g., “100.00 Fahrenheit is 37.78 Celsius”), or simply print the number (e.g., 37.78).

The autograder is flexible and will grade based on the numeric result appearing in your output.

Examples of valid output for input 100 then C:

100.00 Fahrenheit is 37.78 Celsius
or

37.78
 

 *
 * Student Name: Gavin
 */

#include <stdio.h>
//declaring variables
float temp = 0;
char scale = ' ';
float converted_temp = 0;

//conversion functions
float fahrenheit_to_celsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}
float celsius_to_fahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32;
}

//main function
int main(void) {
    
    //user inputs
    //printf("Enter temperature value: ");
    scanf("%f", &temp);
    //printf("Enter scale it is being converted to (C or F): ");
    scanf(" %c", &scale);

    //conversion logic
    if (scale == 'C') {
        // Convert Fahrenheit to Celsius
        converted_temp = fahrenheit_to_celsius(temp);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temp, converted_temp);

    } else if (scale == 'F') {
        // Convert Celsius to Fahrenheit
        converted_temp = celsius_to_fahrenheit(temp);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temp, converted_temp);
      //error handling
    } else {
        printf("Invalid scale entered. Please enter 'C' or 'F'.\n");
    }

    return 0;
}