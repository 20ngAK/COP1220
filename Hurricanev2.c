// COP-1220 Section 86392 
// Assignment 3-2 Hurricane Category v2.0
// Modularize v1.0 with functions.


#include <stdio.h>

// Use void function to get no return value after execution.
void hurricaneCategory(int speed) {
  if (speed >= 157) {
    printf("Category Five Hurricane\n");
  } else if (speed >= 130) {
    printf("Category Four Hurricane\n");
  } else if (speed >= 111) {
    printf("Category Three Hurricane\n");
  } else if (speed >= 96) {
    printf("Category Two Hurricane\n");
  } else if (speed >= 74) {
    printf("Category One Hurricane\n");
  } else {
    printf("Not a Hurricane\n");
  }
}

// Main program logic.
int main() {
  char userInput[10];
  int windSpeed; 
  printf("Enter the wind speed (e.g. 150 mph): ");
  fgets(userInput, 10, stdin);
  sscanf(userInput, "%d", &windSpeed);
  hurricaneCategory(windSpeed);
  return 0;
}