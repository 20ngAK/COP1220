// COP-1220 Section 86392 
// Assignment 4-2 TemperaturesComparison

//Write a program named TemperaturesComparison that allows a user to input five daily Fahrenheit temperatures that must range from −30 to 130.

//If a temperature is out of range, require the user to reenter it.
//If no temperature is lower than any previous one, display a message Getting warmer.
//f every temperature is lower than the previous one, display a message Getting cooler..
//If the temperatures are not entered in either ascending or descending order, display a message It’s a mixed bag.
//Finally, display the temperatures in the order they were entered, and then display the average of the temperatures.


#include <stdio.h>

int main() {
    int temperatures[5];    
    int i;
    float sum = 0;

    // Allow user input and store in array.
  for (i = 0; i < 5; i++) {
      printf("Please enter a temperature %d (between -30 & 130): ", i + 1);
      scanf("%d", &temperatures[i]);
    if (temperatures[i] >= -30 && temperatures[i] <= 130) {
      sum += temperatures[i];
    } else {
      printf("Invalid temperature. Please enter a temperature between -30 and 130.\n");
    // Post decrement the loop to go back to Temperature 1, if the user enters an invalid temperature.
    i--;
    }
  }

  // Check to see if the temperatures are getting warmer, cooler or mixed, and then print output.
    int increasing = 1;
    int decreasing = 1;

    for (i = 1; i < 5; i++) {
        if (temperatures[i] <= temperatures[i - 1]) {
            increasing = 0;
        }

        if (temperatures[i] >= temperatures[i - 1]) {
            decreasing = 0;
        }
    }

    if (increasing == 1) {
        printf("Getting warmer");
    } else if (decreasing == 1) {
        printf("Getting cooler");
    } else {
        printf("It’s a mixed bag");
    }
    
  // Print the 5-day temperature in the proper format with brackets and commas.
    printf("\n5-day Temperature [");
    for (i = 0; i < 5; i++) {
        if (i < 4) {
          printf("%d, ", temperatures[i]);
        } else {
          printf("%d]", temperatures[i]);
        }
    }
  
  // Print the average temperature.
    float average = sum / 5;
  // Use %.1f for the tenths decimal place.
    printf("\nAverage temperature is %.1f degrees\n", average);
  
  return 0;
}
