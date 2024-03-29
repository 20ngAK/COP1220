// COP-1220 Section 86392 
// Assignment 7-1 HomeSales v3.0

//Now, you will modify the program to use structs to store the salesperson names, allowed initials, and accumulated sales values.
// You will need to refactor and remove the parallel arrays and create a struct which will store the SalesPerson and their sales
// One struct should be all you need - 
// You will use that one struct to initialize (instantiate) multiple structs for each SalesPerson and their sales for that Unit Test

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

// Create a struct.
typedef struct {
    char initial; 
    double sales; 
} Salesperson;

// MAIN PROGRAM LOGIC.
int main()
{
    // Set the locale to allow commas in the grand total output.
    setlocale(LC_NUMERIC, "");

    // Initialize structs for each salesperson.
    Salesperson salespersons[] = {
        {'D', 0},
        {'E', 0},
        {'F', 0}
    };
    const int NUM_SALESPERSONS = sizeof(salespersons) / sizeof(salespersons[0]);

    double grand_total = 0;
    double highest_total = 0;
    char top_salesperson_initial = '\0';

    char initial;
    double amount;

    do {
        printf("Enter the salesperson's initial (D, E, F or Z to exit): ");
        scanf(" %c", &initial);
        initial = toupper(initial);

        if (initial != 'Z') {
            int found = 0;

            for (int i = 0; i < NUM_SALESPERSONS; i++) {
                if (salespersons[i].initial == initial) {
                    printf("Enter the amount of the sale: ");
                    scanf("%lf", &amount);
                    grand_total += amount;
                    salespersons[i].sales += amount;

                    if (salespersons[i].sales > highest_total) {
                        highest_total = salespersons[i].sales;
                        top_salesperson_initial = salespersons[i].initial;
                    }
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Error: Invalid salesperson selected, please try again\n");
            }
        }
    } while (initial != 'Z');

    // Print grand_total & top_salesperson when 'Z' is entered.
    printf("Grand total: $%'.0f\n", grand_total);
    printf("Highest sale: %c\n", top_salesperson_initial);

    return 0;
}