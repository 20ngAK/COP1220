// COP-1220 Section 86392 
// Assignment 4-1 HomeSales v2.0

// In Module 2, you wrote a HomeSales application for three salespeople: Danielle, Edward, and Francis. Now, modify the program to use arrays to store the salesperson names, allowed initials, and accumulated sales values.

// You will need to create parallel arrays where one array stores the SalesPerson and the other array stores the sales for that SalesPerson.

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main()
{
    // Set the locale to allow commas in the grand total output.
    setlocale(LC_NUMERIC, "");
    // initialize array for salesperson initial.
    char initials[] = {'D', 'E', 'F'};
    // initialize array for salesperson total.
    double totals[] = {0, 0, 0};
    double grand_total = 0;
    double highest_total = 0;
    char top_salesperson;

    char initial;
    double amount;

    do {
        printf("Enter the salesperson's initial (D, E, F or Z to exit): ");
        scanf(" %c", &initial);
        initial = toupper(initial);

        if (initial != 'Z') {
            int index = -1;

            for (int i = 0; i < 3; i++) {
                if (initials[i] == initial) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                printf("Enter the amount of the sale: ");
                scanf("%lf", &amount);
                grand_total += amount;
                totals[index] += amount;

                if (totals[index] > highest_total) {
                    highest_total = totals[index];
                    top_salesperson = initials[index];
                }
            } else {
                printf("Error: Invalid salesperson selected, please try again\n");
            }
        }
    } while (initial != 'Z');
// Print grand_total & top_salesperson when Z is entered.
    printf("Grand total: $%'.0f\n", grand_total);
    printf("Highest sale: %c\n", top_salesperson);

    return 0;
} 