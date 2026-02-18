#include <stdio.h>
#include <stdlib.h>

int main() {
    int guess;
    int secret = 7; // lucky number
    int attempts = 5;

    printf("Welcome to the Lucky Number Game!\n");

    // do-while: Ask if the user wants to play
    char choice;
    do {
        printf("Do you want to play? (y/n): ");
        scanf(" %c", &choice);
    } while (choice != 'y' && choice != 'n');

    if (choice == 'n') {
        printf("Maybe next time!\n");
        return 0;
    }

    printf("You have %d attempts to guess the number between 1 and 10!\n", attempts);

    // for loop to track attempts
    for (int i = 1; i <= attempts; i++) {
        printf("Attempt #%d: Enter your guess: ", i);
        scanf("%d", &guess);

        // continue: invalid number range
        if (guess < 1 || guess > 10) {
            printf("Invalid! Must be between 1 and 10. Skipping this attempt.\n");
            continue;
        }

        // break: correct guess
        if (guess == secret) {
            printf("🎉 You got it right in %d tries!\n", i);
            break;
        } else {
            printf("Nope! Try again.\n");
        }

        // while loop used after all attempts to keep trying if user wants to
        if (i == attempts) {
            char retry;
            printf("You're out of tries! Want to keep going? (y/n): ");
            scanf(" %c", &retry);

            while (retry == 'y') {
                printf("Enter a new guess: ");
                scanf("%d", &guess);

                if (guess == secret) {
                    printf("🎉 You finally got it!\n");
                    break;
                } else {
                    printf("Still not it! Try again? (y/n): ");
                    scanf(" %c", &retry);
                }
            }
        }
    }

    printf("Game over. Thanks for playing!\n");
    return 0;
}
