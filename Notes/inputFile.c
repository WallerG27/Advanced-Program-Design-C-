#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int score;

    file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Student Scores:\n");

    while (fscanf(file, "%s %d", name, &score) == 2) {
        printf("%s scored %d\n", name, score);
    }

    fclose(file);
    return 0;
}
