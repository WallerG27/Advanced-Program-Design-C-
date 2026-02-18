/*This is a comment*/
/*
The password must be:
8 characters long
contain at least one uppercase letter
one lowercase letter
one digit
one special character

Read the pw.txt file to see if the password is valid from the list above
*/
/*
Homework No. 1
Password Strength Meter

XYZ Corporation has a problem. Their network was broken into last week by a hacker who successfully guessed one of their employees' passwords. 

Bob Jenkins, XYZ's head of security, has decided that it's time to solve this password problem once and for all.

This program:
- Reads proposed passwords from pw.txt
- Evaluates whether each password is STRONG or WEAK
- Prints reasons for weak passwords
- Counts totals at the end
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Checks for uppercase letters
int has_upper(const char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') return 1;
        str++;
    }
    return 0;
}
// Check for lowercase letters
int has_lower(const char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') return 1;
        str++;
    }
    return 0;
}
// Check for digits
int has_digit(const char *str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') return 1;
        str++;
    }
    return 0;
}
// Check for special characters
int has_special(const char *str) {
    while (*str) {
        if ((*str >= 33 && *str <= 47) || (*str >= 58 && *str <= 64) ||
            (*str >= 91 && *str <= 96) || (*str >= 123 && *str <= 126)) {
            return 1;
        }
        str++;
    }
    return 0;
}
// Main function
int main(void) {

    // Open the password file
    FILE *file = fopen("pw.txt", "r");
    if (!file) {
        printf("Error: Could not open pw.txt\n");
        return 1;
    }
    FILE *report = fopen("report.txt", "w");

    // password buffer and counters
    char password[MAX_LEN];
    int strongCount = 0, weakCount = 0;

    // Process each password in the file
    while (fgets(password, MAX_LEN, file)) {
        // Remove newline if present
        password[strcspn(password, "\n")] = '\0';

        // Evaluates password
        int length = strlen(password);
        int upper = has_upper(password);
        int lower = has_lower(password);
        int digit = has_digit(password);
        int special = has_special(password);

        fprintf(report, "Password: %s - ", password);

        if (length >= 8 && upper && lower && digit && special) {
            fprintf(report, "STRONG\n");
            strongCount++;
        } else {
            fprintf(report, "WEAK\n");
            if (length < 8) { fprintf(report, "Missing: Minimum Length\n"); }
            if (!upper) { fprintf(report, "Missing: Uppercase Letter\n"); }
            if (!lower) { fprintf(report, "Missing: Lowercase Letter\n"); }
            if (!digit) { fprintf(report, "Missing: Number\n"); }
            if (!special) { fprintf(report, "Missing: Special Character\n"); }
            
            weakCount++;
        }
    }

    fclose(file);

    // Totals
    printf( "Total Strong Passwords: %d\n", strongCount);
    printf("Total Weak Passwords: %d\n", weakCount);

    fclose(report);
    return 0;
}
