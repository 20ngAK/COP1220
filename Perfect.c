// COP-1220 Section 86392 
// Assignment 2-3 Perfection 

// Accept user input and determine every perfect number from 1 through 10,000.
// A number is perfect if it equals the sum of all the smaller positive integers that divide evenly into it.

#include <stdio.h>
#include <string.h>

int main() {
  int userNumber;
  int sum = 0;
  printf("Please enter a number between 1 and 10000:  ");
  scanf("%d", &userNumber);
// Use a for loop to iterate through all positive integers less than the userNumber
  for (int i = 1; i < userNumber; i++) {
// Check the divisor using the modulo operator, to see if it returns no remainder 
    if (userNumber % i == 0) {
// Use the += operator to add the variables sum and i together, then assign the new value back to sum
      sum += i;
      }
  }
    if (sum == userNumber) {
      printf("Perfect Number\n");
    } else {
      printf("Not A Perfect Number\n");
    }
  return 0;
}