/*This is a comment.*/
/*
 * AHPA #7: The USF Students
 *
 * The university has decided that they need to do a better job of
 * keeping track of all of the information that they have about USF 
 * students.
 *
 * They want you to create a C program that will allow them to enter a 
 * student's name, age, U number, grade point average, if they live on 
 * campus (yes/no), and if they have paid for the current semester (yes/
 * no).
 *
 * You need to create a structure that will contain this information.
 * Once you have created it, enter data into a structure variable for one 
 * student.
 *
 * Then copy that student's data to another structure variable and switch 
 * the answers for where they live and if they have paid for the current 
 * semester.
 *
 * Print out the current data for both students.

 *
 * Student Name: Gavin
 */
/*ChatGPT (Chatty) has helped bug fix this code.
Big thanks to Chatty. <3*/


#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
    // Define the student structure
    struct student {
        char Name[50];
        int Age;
        char Unumber[10];
        float GPA;
        char livesOnCampus[4]; // "yes" or "no"
        char hasPaid[4];       // "yes" or "no"
    };

    struct student student1, student2;

    // Input data for student1
    // Read name (multi-word)
    fgets(student1.Name, sizeof(student1.Name), stdin);
    // remove newline from fgets
    student1.Name[strcspn(student1.Name, "\n")] = '\0';
    /*I had to learn strcspn from ChatGPT
    it finds the first occurrence of a character in a string
    and replaces it with a null terminator to remove the newline character
    so the formatting is correct when printed out later.
    */

    scanf("%d", &student1.Age);
    scanf("%s", student1.Unumber);
    scanf("%f", &student1.GPA);
    scanf("%s", student1.livesOnCampus);
    scanf("%s", student1.hasPaid);

    // Copy data to student2 and switch livesOnCampus and hasPaid
    student2 = student1;
    // Temporary variable to hold one of the values during the switch
    char temp[4];

    // Switch livesOnCampus and hasPaid
  strcpy(temp, student1.livesOnCampus);
  strcpy(student2.livesOnCampus, student1.hasPaid);
  strcpy(student2.hasPaid, temp);

    // Helper: capitalize first letter for output
    student1.livesOnCampus[0] = toupper(student1.livesOnCampus[0]);
    student1.hasPaid[0] = toupper(student1.hasPaid[0]);
    student2.livesOnCampus[0] = toupper(student2.livesOnCampus[0]);
    student2.hasPaid[0] = toupper(student2.hasPaid[0]);
    /*I had to learn toupper from ChatGPT
    it capitalizes the first letter of a string
    so the formatting is correct when printed out later again.
    */

    // Print data for both students
    printf("--- Student 1 Information ---\n");
    printf("Name: %s\n", student1.Name);
    printf("Age: %d\n", student1.Age);
    printf("U Number: %s\n", student1.Unumber);
    printf("GPA: %.2f\n", student1.GPA);
    printf("Lives on Campus: %s\n", student1.livesOnCampus);
    printf("Has Paid: %s\n", student1.hasPaid);

    printf("\n--- Student 2 Information (After Switching) ---\n");
    printf("Name: %s\n", student2.Name);
    printf("Age: %d\n", student2.Age);
    printf("U Number: %s\n", student2.Unumber);
    printf("GPA: %.2f\n", student2.GPA);
    printf("Lives on Campus: %s\n", student2.livesOnCampus);
    printf("Has Paid: %s\n", student2.hasPaid);

  return 0;
}