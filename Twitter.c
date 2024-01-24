// COP-1220 Section 86392 
// Assignment 2-1 Twitter
// Accept a user's input and verify that it's less than or equal to 140 characters.

#include <stdio.h>
#include <string.h>
// Define a constant for the max string length of 140.
#define MAX_LEN 140 

int main() {
// Must allow for a size larger than 140 characters.
  char tweet[142]; 
  printf("Enter your Tweet: \n");
// Must be over 140 characters due to fgets and the /n character contributing towards count, I guess?
  fgets(tweet, 142, stdin);
// Check string length of user input and output "Posted" if <= 140 characters, otherwise output "Rejected" if > 140 Characters.
  if (strlen(tweet) <= MAX_LEN) {
    printf("Posted\n");
  } else {
    printf("Rejected\n");
  }

  return 0;
}