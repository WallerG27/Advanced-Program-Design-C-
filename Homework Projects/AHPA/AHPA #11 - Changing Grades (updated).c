/*This is a comment.*/
#include <stdio.h>

/*
    You are going to create a C array to store final exam scores for 5 students (90, 82, 65, 79, 67).
    Later, two additional students join the class and you need to add their scores (81, 72).
    Finally, you need to look for any D (60-69) scores and boost them to C(70) scores.
    You will use pointer arithmetic to manipulate the array.

    REMEMBER to answer the questions below!!
*/

/*
    Question 1: Assuming the you had sized the finalExams array based on your class size (5), 
    what just happened when you added the scores for the two additional students to your array? 
    What would this mean in terms of programming security?

    Your Answer: They don't get added because the array is only sized for 5 elements. 
    So programming security means we should make sure our arrays are big enough to hold 
    all the data we need so information isn't lost. 
*/

/*
    Question 2: If you executed the code: testPtr = startPtr - endPtr and then tried to store 
    the value "5" in location testPtr, what would happen?

    Your Answer: If you tried to execute testPtr = startPtr - endPtr and then tried to store 
    the value of 5 in location for testPtr it would result in undefined behavior because the 
    memory location that is not in the finalExams array; leading to a negative value, which is 
    not a valid index for the array.

*/

void printArray(int *startPtr, int *endPtr)
{
    for (int *ptr = startPtr; ptr <= endPtr; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main(void)
{
    // Step 0: Create and initialize the array and pointers
#define N 10
    int finalExams[N] = {0};
    int *startPtr = &finalExams[0];
    int *endPtr = &finalExams[N-1];
    int *testPtr;

    // Step 1: Print the entire array (locations 0-9)
    printf("Print entire array before modification (locations 0-9):\n");
    printArray(startPtr, endPtr);

    // Step 2: Load the first 5 scores: 90, 82, 65, 79, 67
    int given5[5] = {90, 82, 65, 79, 67};
    printf("Load the contents of the finalExams array...\n");
    for (int i = 0; i < 5; i++) {
        *(startPtr + i) = given5[i];
    }
    // Print the entire array after loading the first 5 (locations 0-9)
    printf("Print entire updated array (locations 0-9):\n");
    printArray(startPtr, endPtr);

    // Step 3: Two new students join: add 81, 72
    int given2[2] = {81, 72};
    printf("Adding new scores to the array...\n");
    for (int i = 0; i < 2; i++) {
        *(startPtr + 5 + i) = given2[i];
    }
    // Print the entire array (locations 0-9) again
    printf("Print entire array (locations 0-9):\n");
    printArray(startPtr, endPtr);


    // Step 4: Look for D (60-69) scores and boost them to C(70) scores
    for (int i = 0; i < N; i++) {
        if (*(startPtr + i) >= 60 && *(startPtr + i) <= 69) {
            *(startPtr + i) = 70;
        }
    }
    // Print the entire array (locations 0-9) again
    printf("Print entire array after boosting D scores to C (locations 0-9):\n");
    printArray(startPtr, endPtr);

    return 0;
}