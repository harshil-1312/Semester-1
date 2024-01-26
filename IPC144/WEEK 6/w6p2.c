//**
// Full Name  : Harshil Prajapati
// student ID#: 175255215
// Email       : hprajapati8@myseneca.ca
// Section    :IPC144ZRA.5605.2227
// Authenticity Declaration:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation
//**

#include <stdio.h>

const int max = 400000;
#define MAXITEMS 10
const int min = 500;

int main(void)

{

    double netincome, total, costp;
    double price[10]; // declaring the aarays
    int f, a, b = 0;
    int x = 1;
    int y;
    int end = 1;
    int year, month;
    int item[10];     // declaring the aarays
    char finance[10]; // declaring the aarays

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    printf("\nEnter your monthly NET income: $");

    do
    {
        scanf(" %lf", &netincome);

        if (netincome >= 400000)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");

            printf("\n\nEnter your monthly NET income: $");
        }
        else if (netincome < 500)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00");

            printf("\n\nEnter your monthly NET income: $");
        }
    } while (netincome >= 400000 || netincome <= 500);

    do

    {
        printf("\nHow many wish list items do you want to forecast?: ");

        scanf("%d", &f);

        if (f < 1 || f > 10)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

    } while (f < 1 || f > 10);

    for (a = 0; a < f; a++)
    {

        printf("\nItem-%d Details:\n", (a + 1));

        do
        {

            printf("   Item cost: $");

            scanf(" %lf", &price[a]);

            if (price[a] < 100)

            {

                printf("      ERROR: Cost must be at least $100.00\n");
            }

        } while (price[a] < 100);

        do

        {

            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");

            scanf(" %d", &item[a]);

            if (item[a] < 1 || item[a] > 3)

            {

                printf("      ERROR: Value must be between 1 and 3\n");
            }

        } while (item[a] < 1 || item[a] > 3);

        do

        {

            printf("   Does this item have financing options? [y/n]: ");

            scanf(" %c", &finance[a]);

            if ((finance[a] != 'y') && (finance[a] != 'n'))

            {

                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while ((finance[a] != 'y') && (finance[a] != 'n'));
    }
    printf("\nItem Priority Financed        Cost\n");

    printf("---- -------- -------- -----------\n");

    while (b < f)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", b + 1, item[b], finance[b], price[b]);
        total = total + price[b];
        b++;
    }
    printf("---- -------- -------- -----------");

    printf("\n                      $%11.2f\n\n", total);

    do

    {

        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &x);

        if (x == 0)
        {
            end = 0;
        }
        else if (x > 2 || x < 0)
        {

            printf("\nERROR: Invalid menu selection.\n\n");
        }

        else if (x == 1)
        {

            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total);
            year = (int)(total / (double)netincome) / 12;
            month = (int)(total / (double)netincome) % 12;
            printf("Forecast: %d years, %d months\n", year, month + 1);
            printf("NOTE: Financing options are available on some items.\n"
                   "      You can likely reduce the estimated months.\n"
                   "====================================================\n\n");
        }

        else if (x == 2)
        {

            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &y);

            for (x = 0; x < f; x++)
            {
                if (y == item[x])
                {
                    costp = costp + price[x];
                }
            }
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", y);
            printf("Amount:   $%1.2lf\n", costp);
            year = (int)(costp / (double)netincome) / 12;
            month = (int)(costp / (double)netincome) % 12;

            printf("Forecast: %d years, %d months\n", year, month + 1);
            costp = 0;

            if (y == 1 || y == 3)
            {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
            printf("\n");
        }

    } while (!(x == 0 && end == 0));

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}