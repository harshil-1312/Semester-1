//*********
// Full Name  : Harshil Prajapati
// student ID#: 175255215
// Email       : hprajapati8@myseneca.ca
// Section    :IPC144ZRA.5605.2227
// Authenticity Declaration:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation
//*********

#include <stdio.h>
#include <stdlib.h>

int main(void)

{
    int a;

    int x = 0;

    char p;

    printf("+----------------------+\n"
           "Loop application STARTED\n"
           "+----------------------+\n\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &p, &a);

        if (p == 'Q' && a != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            continue;
        }
        else if ((p != 'Q' && p != 'D') && (p != 'W' && p != 'F'))
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
            continue;
        }

        else if ((p != 'Q') && (a < 3 || a > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            continue;
        }

        switch (p)
        {
        case 'D':
            printf("DO-WHILE: ");
            do
            {
                printf("D");
                x++;

            } while (x < a);
            x = 0;
            printf("\n\n");
            break;

        case 'W':
            printf("WHILE   : ");
            do
            {
                printf("W");
                x++;

            } while (x < a);
            x = 0;
            printf("\n\n");
            break;

        case 'F':
            printf("FOR     : ");
            do
            {
                printf("F");
                x++;

            } while (x < a);
            x = 0;
            printf("\n\n");
            break;
        }
    } while (!(p == 'Q' && a == 0));

    printf("\n\n+--------------------+");
    printf("\nLoop application ENDED\n");
    printf("\n+--------------------+\n\n");

    return 0;
}