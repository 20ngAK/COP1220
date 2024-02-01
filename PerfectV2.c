// COP-1220 Section 86392 
// Assignment 3-1 Perfection V2.0

// Modularize the original code to use functions.
// Accept user input and determine every perfect number from 1 through 10,000.
// A number is perfect if it equals the sum of all the smaller positive integers that divide evenly into it.

#include <stdio.h>
#include <string.h>

// Function to check if a number is perfect. Just move for loop structure from original program into this function.
int PerfectNumber(int number) {
  int sum = 0;
  for (int i = 1; i < number; i++) {
    if (number % i == 0) {
      sum += i;
    }
  }
  if (sum == number) {
// return 1 will terminate the loop
    return 1;
  } else {
    return 0;
  }
}

// Main program logic.
int main() {
  int userNumber;
  printf("Please enter a number between 1 and 10000:  ");
  scanf("%d", &userNumber);
  if (PerfectNumber(userNumber)) {
    printf("Perfect Number\n");
  } else {
    printf("Not A Perfect Number\n");
  }
  return 0;
}