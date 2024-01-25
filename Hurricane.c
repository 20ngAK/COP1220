// COP-1220 Section 86392 
// Assignment 2-2 Hurricane Category
// Use conditional statements to determine the hurricane category based on the speed of the hurricane.

// Category 5  >= 157mph
// Category 4  >= 130mph && <157mph
// Category 3  >= 111mph && <130mph
// Category 2  >= 96mph && <111mph
// Category 1  >= 74mph && <96mph
// Not a hurricane if <74mph

#include <stdio.h>
#include <string.h>

int main() {
  char input[10];
  int windSpeed; 
  printf("Enter the wind speed (e.g. 150 mph): ");
  fgets(input, 10, stdin);
// Read and format input variable into windSpeed variable to separate integer value from "mph"
  sscanf(input, "%d", &windSpeed);

  if (windSpeed >= 157) {
    printf("Category Five Hurricane\n");
  } else if (windSpeed >= 130) {
    printf("Category Four Hurricane\n");
  } else if (windSpeed >= 111) {
    printf("Category Three Hurricane\n");
  } else if (windSpeed >= 96) {
    printf("Category Two Hurricane\n");
  } else if (windSpeed >= 74) {
    printf("Category One Hurricane\n");
  } else {
    printf("Not a Hurricane\n");
  
  return 0;
}

  

   
  
  
  












  
}