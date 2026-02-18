//Dr. Kateology's Koding Korner
//Sept. 18, 2025

#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 3
#define NUM_TESTS 3
#define MAX_NAME_LEN 100

// Structure to represent a student
struct Student {
    char name[MAX_NAME_LEN];
    int id;
    float scores[NUM_TESTS];  // Nested array inside struct
};

float calculateAvg(float scores[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum/size;

}

int main() {
    struct Student students[NUM_STUDENTS];

    //Input Student Data
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  // Read full name with spaces
        printf("ID: ");
        scanf("%d", &students[i].id); 

        for (int j = 0; j < NUM_TESTS; j++) {
            printf("Score for test %d: ", j + 1);
            scanf("%f", &students[i].scores[j]); 
        }
    }

    printf("\n*** Student Report ***\n");
   int topStudentIndex = 0;
    float highestAverage = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
     //Saving a function to a variable   
    // 1        2. 3.      4.             5.                     6
        float avg = calculateAvg(students[i].scores, NUM_TESTS);
        printf("Name: %s  | ID: %d  |  Average:  %.2f\n", students[i].name, students[i].id, avg);

        if(avg > highestAverage) {
            highestAverage = avg;
            topStudentIndex = i;
        }

    }
    //Display Top Studnet Info
    printf("\nTop Performer Is:  %s |  Avergae:  %.2f\n", students[topStudentIndex].name, highestAverage);


    return 0;
}


