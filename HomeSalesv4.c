// COP-1220 Section 86392 
// Assignment 8-1 HomeSales v4.0 GO LIVE
// Modified to read input from a file

// Modify the program to read the input from a file. Continue to use structs for SalesPerson and SalesData.
// No data should be be found in the program.
// All data will be read from a file.

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

// Create a struct.
typedef struct {
    char initial; 
    double sales; 
} Salesperson;

// MAIN PROGRAM LOGIC.
int main() {
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

    // Open the sales file.
    FILE *file = fopen("sales.txt", "r");

    // Check if the sales file was successfully opened.
    if (file == NULL) {
        perror("Error: Unable to open file");
        return -1;
    }

    // Read the data until EOF.
    while (fscanf(file, " %c %lf", &initial, &amount) == 2) {
        initial = toupper(initial);

        if (initial == 'Z') {
            break;
        }

        int found = 0;

        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            if (salespersons[i].initial == initial) {
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

    // Close the sales file.
    fclose(file);

    // Print grand_total & top_salesperson when 'Z' is entered or EOF is reached.
    printf("Grand total: $%'.0f\n", grand_total);
    printf("Highest sale: %c\n", top_salesperson_initial);

    return 0;
}