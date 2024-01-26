//*****************************************************************************
// Full Name  : Harshil Prajapati
//student ID#: 175255215
//Email       : hprajapati8@myseneca.ca
//Section    :IPC144ZRA.5605.2227
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation
//*****************************************************************************




#include <stdio.h>
#define LOG_DAYS 3

int main(void)
{

    int year;
    int month;
    int i;
    double mrating, erating, mtotal, etotal ,total,atotal;

    printf("General Well-being Log");
    printf("\n======================\n");

    do
    {

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year < 2012 || year > 2022) && (month < 1 || month > 12))

        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

        else if (year < 2012 || year > 2022)

        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }

        else if (month < 1 || month > 12)

        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (2012 > year || year > 2022 || month < 1 || month > 12);

    printf("\n");
    printf("*** Log date set! ***\n");

    switch (month)
    {
    case 1:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-JAN-0%d\n", year, i);
            else
                printf("\n%d-JAN-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
            printf("\n");
        }
        break;

    case 2:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-FEB-0%d\n", year, i);
            else
                printf("\n%d-FEB-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }
        break;
    case 3:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-MAR-0%d\n", year, i);
            else
                printf("\n%d-MAR-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }
        break;
    case 4:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-APR-0%d\n", year, i);
            else
                printf("\n%d-APR-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 5:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-MAY-0%d\n", year, i);
            else
                printf("\n%d-MAY-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 6:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-JUN-0%d\n", year, i);
            else
                printf("\n%d-JUN-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 7:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-JUL-0%d\n", year, i);
            else
                printf("\n%d-JUL-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 8:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-AUG-0%d\n", year, i);
            else
                printf("\n%d-AUG-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 9:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-SEP-0%d\n", year, i);
            else
                printf("\n%d-SEP-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 10:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-OCT-0%d", year, i);
            else
                printf("%d-OCT-%d", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 11:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-NOV-0%d\n", year, i);
            else
                printf("\n%d-NOV-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    case 12:
        for (i = 1; i <= LOG_DAYS; i++)

        {
            if (i < 10)
                printf("\n%d-DEC-0%d\n", year, i);
            else
                printf("\n%d-DEC-%d\n", year, i);

            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf(" %lf", &mrating);
                if (mrating < 0.0 || mrating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (mrating < 0.0 || mrating > 5.0);
            mtotal += mrating;

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf(" %lf", &erating);
                if (erating < 0.0 || erating > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            } while (erating < 0.0 || erating > 5.0);
            etotal += erating;
        }        break;
    }


    total = mtotal + etotal;
printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %5.3lf\n", mtotal);
    printf("Evening total rating:  %5.3lf\n", etotal);
    printf("----------------------------\n");
    printf("Overall total rating: %5.3lf\n",total);
    atotal =( ( mtotal/LOG_DAYS + etotal/LOG_DAYS ) / 2 );
    printf("\nAverage morning rating:  %2.1lf\n", mtotal / LOG_DAYS);
    printf("Average evening rating:  %2.1lf\n", etotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %2.1lf\n",atotal);

    return 0;
}
