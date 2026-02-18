/*This is a comment.*/
#include <stdio.h>
#include <string.h>

// Define a struct to represent a transmission
struct Transmission {
    char sender[50];
    char receiver[50];
    char message[100];
    int checksum;
    int isCorrupted; // 0 = clean, 1 = tampered
};



/*   Forward declarations   */
// Odd number of characters
int parityCheck(char message[]) 
{
    printf("Running error check 1: Parity Check...");
    if (strlen(message) % 2 == 1) {
        printf("No errors!\n");
        return 1; // odd character found
    }
    printf("Warning: Unexpected length!\n");
    return 0; // even characters/not odd
}



// adds the ASCII values by 256
int checksumAlgo(char message[]) {
    printf("Running error check 2: Checksum...");
    
    int sum = 0;
    for (int i = 0; i < strlen(message); i++) {
        sum += (unsigned char)message[i];
    }
    int modSum = sum % 256;
        printf("Checksum... total = [%d]\n", modSum);
        return 0;
}



// counts the number of times the target or 'z' appears
int charCountCheck(char message[], char target) {
printf("Running error check 3: Character Count Check...");
    int count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == target) {
            count++;
        }
    }
    if (count > 3) {
        printf("No errors!\n");
    }
    else {
    printf("Weird letter found!\n");
    }
    return count;
}



void printReport(struct Transmission transmissions[], int n) {
    // Basic Title thing it wanted
    printf("\n--- Final Transmission Report ---\n");
    for (int i = 0; i < n; i++) {
        printf("From: %s -> To: %s  :  ", transmissions[i].sender, transmissions[i].receiver);
        if (transmissions[i].isCorrupted == 0) {
            printf("CLEAN\n");
        } else {
            printf("TAMPERED\n");
        }
}
  
    // Closing card it wanted
    printf("Thank you for helping protect WhimsyTown from the Rascalians!");
}




int main() {
    // Initialize example transmissions
    // (char)sender, (char)receiver[50], (char)message, (int)checksum, (int)isCorrupted {0=Clean/1=Tampered}
    struct Transmission transmissions[3] = {
        {"Lollipop Tower", "Bubblegum Bridge", "The marshmallows are melting", 0, 0},
        {"Whimsy Labs", "Taffy Tunnel", "Zizzle zap zorp zonk", 0, 0},
        {"Candy Corn HQ", "Mayor’s Office", "Emergency: Rainbow leak", 0, 0}
    };

    // number of transmissions
    int n = 3;
    
    printf("Welcome to WhimsyTown Secure Message Checker!\n");

    // Goes through all the transmissions for each check
    for (int i = 0; i < n; i++) {
        // t is a pointer to the current Transmission struct.
        struct Transmission *t = &transmissions[i];

        // Print information about the current transmission
        printf("\nTransmission %d Report:\n", i + 1);
        printf("Message: %s\n", transmissions[i].message);

        // Perform all 3 error detection checks
        int p = parityCheck(t->message); // Even/Odd check
        int c = checksumAlgo(t->message); // checksum validation thing
        int x = charCountCheck(t->message, 'z'); // suspicious character count

        // Update transmission status
        t->checksum = c;
        t->isCorrupted = (p == 0 || x > 3); // simplified logic
    }

    // Print results
    printReport(transmissions, n);

    return 0;
}