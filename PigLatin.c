// COP-1220 Section 86392 
// Assignment 6-1 PigLatin Translator

// "Here’s how it works: First, pick any English word. We’ll use dictionary. Next, move the first consonant or consonant cluster to the end of the word: “ictionary-d.” Now add “ay” to the end of the word: “ictionary-day.” That’s all there is to it; you’ve formed a word in Pig Latin."


#include <stdio.h>
#include <string.h>
#include <ctype.h> // Needed for character functions.

// FUNCTION to check if a character is a vowel.
int vowelCheck(char ch) {
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// FUNCTION to translate a single word to PigLatin.
void translateToPigLatin(char *word) {
    int wordLength = strlen(word);
    int vowelPos = -1;

    // Find the position of the first vowel in the word.
    for (int i = 0; i < wordLength; i++) {
        if (vowelCheck(word[i])) {
            vowelPos = i;
            break;
        }
    }

    // If the first letter is a vowel, add "yay" to the end of the word.
    if (vowelPos == 0) {
        printf("%syay ", word);
    } 
    // Otherwise add "ay" to the end of the word.
    else if (vowelPos != -1) {
        // Print from the first vowel to the end of the word.
        for (int i = vowelPos; i < wordLength; i++) {
            printf("%c", word[i]);
        }
        // Print the original consonant cluster, then "ay".
        for (int i = 0; i < vowelPos; i++) {
            printf("%c", word[i]);
        }
        printf("ay ");
    }
}

// MAIN PROGRAM LOGIC.
int main() {
    char sentence[1000]; 

    printf("Please enter an English sentence: ");
    fgets(sentence, sizeof(sentence), stdin); 

    // Used for tokenizing the sentence.
    char *word = strtok(sentence, " ,.-\n");
    while (word != NULL) {
        translateToPigLatin(word);
        word = strtok(NULL, " ,.-\n");
    }

    return 0;
}