// COP-1220 Section 86392 
// Assignment 6-2 CipherMessage

// Write a program that will encrypt a message using a Caesar cipher. 
// Only use alphabets. 

#include <stdio.h>
#include <string.h>

// encryptMessage function to shift the letters of a user supplied message based on a caeser cipher.
void encryptMessage(char *message, int shift, char *encryptedMessage) {
    int i = 0;
    char ch;
    // Normalize the shift to ensure it's within the range of 0-25
    shift = shift % 26;

    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            encryptedMessage[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            // Allow for uppercase letters too!
            encryptedMessage[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        } else {
            // Copy the character as it is, including all spaces or other characters.
            encryptedMessage[i] = ch;
        }
        i++;
    }
    encryptedMessage[i] = '\0'; // Null-terminator for the encrypted message string.
}

// MAIN PROGRAM LOGIC.
int main() {
    char originalMessage[1000];
    char encryptedMessage[1000];
    int shift;

    printf("Please enter a message to encrypt: ");
  // Read the user input, including spaces.
    fgets(originalMessage, sizeof(originalMessage), stdin);
  // Remove newline character.
    originalMessage[strcspn(originalMessage, "\n")] = 0; 

    printf("Please enter a number to shift by (key): ");
  // Read the user input shift key. 
    scanf("%d", &shift);

    encryptMessage(originalMessage, shift, encryptedMessage);

  // Print outputs in proper format.
    printf("Text: %s\n", originalMessage);
    printf("Shift: %d\n", shift);
    printf("Cipher: %s\n", encryptedMessage);

    return 0;
}