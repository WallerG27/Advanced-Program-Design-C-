/*This is a comment*/
/*
You must create a linked list specified in the instructions in the lecture, two string variables for storing the course ID and course name respectively, a Boolean variable to denote if the class has been taken already, and a Node variable that links to the next node in the list if it exists.
The data must be read in from the "AHPA #12 -CyberSecurity Courses.txt" file in the Files tab of the course, keep this name as is in your final program and do not change it.
Do not submit anything other than your .c program.
When printing out the courses that have not been taken already, each course should be output as (Course ID) - (Course Name) followed by a new line character (i.e. since Ted has not taken Advanced Program Design for IT yet, it should be output as COP3515 - Advanced Program Design for IT). This should be the only output of your program.
In your program, you must properly allocate and deallocate the memory used by the nodes. Failure to do so will result in a loss of points.
Name your program AHPA12.c otherwise it may not compile in the autograder.
For reference, the output of your program should look like this when complete:

COP3515 - Advanced Program Design for IT
CIS3363 - IT Systems Security
CNT4104 - Computer Information Networks for IT
CNT4104L - Computer Information Networks for IT Lab
COP4538 - Data Structures and Algorithms for IT
CNT4403 - Network Security and Firewalls
COP4703 - Advanced Database Systems for IT
CIS4200 - Penetration Testing
CIS4366 - Hands-on Cybersecurity
ISM4323 - Information Security and IT Risk Management
LIS4414 - Information Policy and Ethics
CIS4935 - Senior Project for IT
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char courseID[10];
    char courseName[100];
    int taken;
    struct Node* next;
};

// Trim whitespace from both ends
void trim(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    memmove(str, start, strlen(start) + 1);

    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) *end-- = '\0';
}

void printList(struct Node* head) {
    struct Node* current = head;
    int index = 1;

    while (current != NULL) {
        if (current->taken == 0) {
            printf("%s - %s\n", current->courseID, current->courseName);
        }
        //else {
        //    printf("Taken: %s\n", current->courseName);
        //}
        current = current->next;
        index++;
    }
}

int main(void) {
    FILE *file = fopen("AHPA #12 -CyberSecurity Courses.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;
    char line[200];
    int index = 1;

    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) <= 1) continue;

        struct Node* newNode = malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        char *id = strtok(line, ",");
        char *name = strtok(NULL, ",");

        if (id && name) {
            trim(id);
            trim(name);

            strcpy(newNode->courseID, id);
            strcpy(newNode->courseName, name);

            // Hard-code which courses have been taken
            if (index == 1 || index == 2 || index == 5 || index == 9 || index == 12) {
                newNode->taken = 1;
            } else {
                newNode->taken = 0;
            }

            newNode->next = NULL;

            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            index++;
        } else {
            free(newNode);
        }
    }

    fclose(file);

    printList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
