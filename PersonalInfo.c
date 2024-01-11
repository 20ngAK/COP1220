// COP-1220 Section 86392 
// Assignment 1-1 - PersonalInfo
// Display a person's name, birthdate, work phone number, and cell phone number on separate lines.

#include <stdio.h>
#include <string.h>

int main() {
  char name[30];
  char birth_date[15];
  char work_phone[15];
  char cell_phone[15];

// Remember to use fgets() instead of scanf(), because of space delimiter issue (name char) and buffer overlow protection!
  
  printf("Enter your name: ");
  fgets(name, 50, stdin);

  printf("Enter your birthdate: ");
  fgets(birth_date, 15, stdin);

  printf("Enter your work phone number: ");
  fgets(work_phone, 15, stdin);

  printf("Enter your cell phone number: ");
  fgets(cell_phone, 15, stdin);

  printf("%s", name);
  printf("%s", birth_date);
  printf("work %s", work_phone);
  printf("cell %s", cell_phone);

  return 0;
}

  

