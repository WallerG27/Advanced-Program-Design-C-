/*This is a comment*/
/*
 * AHPA #5: Caesar's Cipher
 *
 * Open the file "clearMessage.txt".
 * 
 * Read each character of text using fgetc.
 *
 * Convert each ASCII character to its numeric equivalent.
 *
 * Apply the Caesar Cipher and increment each character by 3.
 *
 * Only convert alphabetic characters – leave all other characters 
 * unchanged.
 *
 * Convert each character back to its ASCII value.
 *
 * Write the encoded message out to the file "secretMessage.txt".
 *
 * Student name: Gavin
 *
 */



#include <stdio.h>

int main(void) {
    //Set up file and variables
  FILE *file;
    char letters[50];
    int i = 0;
    int ch;

    //Open the file for reading
    file = fopen("clearMessage.txt", "r");

    //Check if file opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    //Read characters from file using
    int fgetc(FILE *stream);
    while ((ch = fgetc(file)) != EOF) {
        letters[i] = ch;
        i++;
    }

    //close the file after reading
    fclose(file);

    //output file for writing
    file = fopen("secretMessage.txt", "w");

    //Check if file opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    //Apply Caesar Cipher and write to output file
    for (int j = 0; j < i; j++) {
        if (letters[j] >= 'a' && letters[j] <= 'z') {
            letters[j] = ((letters[j] - 'a' + 3) % 26) + 'a';
        } else if (letters[j] >= 'A' && letters[j] <= 'Z') {
            letters[j] = ((letters[j] - 'A' + 3) % 26) + 'A';
        }
        fputc(letters[j], file);
    }

    //close the output file
    fclose(file);

  return 0;
}