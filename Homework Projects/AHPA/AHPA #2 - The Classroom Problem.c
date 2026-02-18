/*This is a comment*/
/*
* AHPA #2: The Classroom Problem
*
* Dr. Anderson is teaching a COP 3515 class that has 9 students in it.
* Each student has a seating location, a name (just a single letter), and a
current score in the class.
*
* The information looks like this:
* 1, B, 79.54, 2, M, 82.13, 3, T, 74.61, 4, J, 91.12, 5, P, 78.83,
* 6, E, 97.17, 7, H, 85.65, 8, R, 65.42, 9, X, 70.26
*
* Create a C program that will store the number of students in the class in a
constant called numStudents.
* Store the student seating locations, names, and current scores into individual
variables.
* Print out the number of students in the class using numStudents.
* Print out the class information on three lines in the following format:
* xxx xxx xxx
* where "xxx" is "seating location, name, current score in class".
*
* Note that the current score should be printed with just one decimal place.
*
* Student Name: Gavin
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
int main(void) {
/*Total Number of Students*/
const int numStudents = 9;
/*
Arrays are in C and would simplify, but we aren't there yet.
Examples for it will still be listed
*/
/*Student Seats*/
int seat1 = 1; int seat2 = 2; int seat3 = 3;
int seat4 = 4; int seat5 = 5; int seat6 = 6;
int seat7 = 7; int seat8 = 8; int seat9 = 9;
/*int seats[9] = {1,2,3,4,5,6,7,8,9};*/
/*Student Names*/
char name1 = 'B'; char name2 = 'M'; char name3 = 'T';
char name4 = 'J'; char name5 = 'P'; char name6 = 'E';
char name7 = 'H'; char name8 = 'R'; char name9 = 'X';
/*char names[9] = {'B','M','T','J','P','E','H','R','X'};*/
/*Student Scores*/
double score1 = 79.54; double score2 = 82.13; double score3 = 74.61;
double score4 = 91.12; double score5 = 78.83; double score6 = 97.17;
double score7 = 85.65; double score8 = 65.42; double score9 = 70.26;
/*double scores[9] = {79.54, 82.13, 74.61, 91.12, 78.83, 97.17, 85.65, 65.42,
70.26};*/
/*Printing the Results*/
printf("Number of students in the class: %d\n\n", numStudents);
printf("%d %c %.1f %d %c %.1f %d %c %.1f\n",
seat1, name1, score1, seat2, name2, score2, seat3, name3, score3);
printf("%d %c %.1f %d %c %.1f %d %c %.1f\n",
seat4, name4, score4, seat5, name5, score5, seat6, name6, score6);
printf("%d %c %.1f %d %c %.1f %d %c %.1f\n",
seat7, name7, score7, seat8, name8, score8, seat9, name9, score9);
/*
A loop for each Array Element would help here as well seat[i], name[i], score[i]
going through each of the 9 students.
I'm too lazy to type a bunch of code I'm not even going to use, but I will look
into it so I know how to do so
Okay update it's like the same as python it's not that bad, I couldn't help
myself and it's pretty simple.
*/
/*
printf("Number of students in the class: %d\n\n", numStudents);
for (int i = 1; i <= numStudents; i++) {
printf("%d %c %.1f ", seats[i-1], names[i-1], scores[i-1]);
if (i%3 == 0) {
printf("\n");
*/
return 0;
}