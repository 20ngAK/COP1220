// COP-1220 Section 86392 
// Assignment 2-4 HomeSales
// Accept user input for a salesperon's inital (D, E or F) 
// While the user does not type Z, continue by prompting for the amount of a sale. 
// Issue an error message for any invalid initials entered. 
// Keep a running total of the amounts sold by each salesperson. After the user types Z or z for an initial, display each salesperson’s total, a grand total for all sales, and the name of the salesperson with the highest total. 


#include <stdio.h>
#include <ctype.h> // Needed for character handling.
#include <locale.h> // Needed to remove trailing zeroes and add commas in grand total output.

int main()
{
  // Set the locale to allow commas in the grand total output.
    setlocale(LC_NUMERIC, "");
  // declare and intialize variables.
    char initial;
    double amount;
    double total_D = 0; 
    double total_E = 0;
    double total_F = 0;
    double grand_total = 0;
    double highest_total = 0;
    char top_salesperson;

    do {
        printf("Enter the salesperson initial (D, E, or F, Z to exit): ");
        scanf(" %c", &initial);
      // converts initials to upper case
        initial = toupper(initial);

        if (initial != 'Z') {
            if (initial == 'D' || initial == 'E' || initial == 'F') {
                printf("Enter the amount of the sale: ");
                scanf("%lf", &amount);
                grand_total += amount;
// Use a switch statement to determine the total for each salesperson.
                switch (initial) {
                    case 'D':
                        total_D += amount;
                        break;
                    case 'E':
                        total_E += amount;
                        break;
                    case 'F':
                        total_F += amount;
                        break;
                }

                if (total_D > highest_total) {
                    highest_total = total_D;
                    top_salesperson = 'D';
                }
                if (total_E > highest_total) {
                    highest_total = total_E;
                    top_salesperson = 'E';
                }
                if (total_F > highest_total) {
                    highest_total = total_F;
                    top_salesperson = 'F';
                }

            } else {
                printf("Error, invalid salesperson selected, please try again\n");
            }
        }
    } while (initial != 'Z');
// $%'.0f is used to remove trailing zeroes and add commas in the grand total output.
    printf("Grand total: $%'.0f\n", grand_total);
    printf("Highest sale: %c\n", top_salesperson);

    return 0;
}