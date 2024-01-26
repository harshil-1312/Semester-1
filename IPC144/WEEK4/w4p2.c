
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
int main()
{
    int a1,a2,p1,p2,o1,o2,t1,t2,c1,c2,x;
do
{
    

    printf("Grocery Shopping\n");
    printf("================\n");
   
   
   
    do
    {
        printf("How many APPLES do you need? : ");
        scanf(" %d", &a1);
        if (a1 < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");// For APPLES
        }

    } while (a1 < 0);

    do
    {
        printf("\nHow many ORANGES do you need? : ");
        scanf(" %d", &o1);
        if (o1 < 0)
        {
            printf("ERROR: Value must be 0 or more.");// For ORANGES
        }

    } while (o1 < 0);

    do
    {
        printf("\nHow many PEARS do you need? : ");
        scanf(" %d", &p1);
        if (p1 < 0)
        {
            printf("ERROR: Value must be 0 or more.");// For PEARS
        }

    } while (p1 < 0);

    do
    {
        printf("\nHow many TOMATOES do you need? : ");
        scanf(" %d", &t1);
        if (t1 < 0)
        {
            printf("ERROR: Value must be 0 or more.");// For TOMATOES
        }

    } while (t1 < 0);

    do
    {
        printf("\nHow many CABBAGES do you need? : ");
        scanf(" %d", &c1);
        if (c1 < 0)
        {
            printf("ERROR: Value must be 0 or more.");// For Cabbages
        }

    } while (c1 < 0);

  //////////////////////////////////////////////////////////////////////  
    
    
     printf("\n--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");
    
  if (a1 != 0)
        {
            do
            {

                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &a2);

                if (a2 > a1)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", a1);
                    a2 = 0;
                }
                else
                {
                    if (a2 <= 0)
                        printf("ERROR: You must pick at least 1!\n");
                    else
                    {
                           a1 -= a2; 

                            if (a1 != 0)

                            printf("Looks like we still need some APPLES...\n");
                    


                    }
                }

            } while (a1 != 0);
            printf("Great, that's the apples done!\n\n");
        }


        if (o1 != 0)
        {
  
            do
            {

                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &o2);

                if (o2 > o1)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", o1);
                    o2 = 0;
                }
                else
                {
                    if (o2 <= 0)
                        printf("ERROR: You must pick at least 1!\n");
                    else
                    {

                        o1 = o1 - o2;
                        if (o1 != 0)
                            printf("Looks like we still need some ORANGES...\n");

                    }
                }

            } while (o1 != 0);
            printf("Great, that's the oranges done!\n\n");
        }


        if (p1 != 0)
        {
     
            do
            {

                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &p2);

                if (p2 > p1)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", p1);
                    p2 = 0;
                }
                else
                {
                    if (p2 <= 0)
                        printf("ERROR: You must pick at least 1!\n");
                    else
                    {

                        p1 = p1 - p2;
                        if (p1 != 0)
                            printf("Looks like we still need some PEARS...\n");

                    }
                }

            } while (p1 != 0);
            printf("Great, that's the pears done!\n\n");
        }

        if (t1 != 0)
        {
       
            do
            {

                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &t2);

                if (t2 > t1)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", t1);
                    t2 = 0;
                }
                else
                {
                    if (t2 <= 0)
                        printf("ERROR: You must pick at least 1!\n");
                    else
                    {

                        t1 = t1 - t2;
                        if (t1 != 0)
                            printf("Looks like we still need some TOMATOES...\n");

                    }
                }

            } while (t1 != 0);
            printf("Great, that's the tomatoes done!\n\n");
        }

        if (c1 != 0)
        {
            c2 = 0;    do
            {

                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &c2);

                if (c2 > c1)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", c1);
                    c2 = 0;
                }
                else
                {
                    if (c2 <= 0)
                        printf("ERROR: You must pick at least 1!\n");
                    else
                    {

                        c1 = c1 - c2;
                        if (c1 != 0)
                            printf("Looks like we still need some CABBAGES...\n");

                    }
                }

            } while (c1 != 0);
            printf("Great, that's the cabbages done!\n\n");
        }


        printf("All the items are picked!\n");
        printf("\nDo another shopping? (0=NO): ");
        scanf("%d", &x);
        printf("\n");
    
    }while (x == 1);
    
    printf("Your tasks are done for today - enjoy your free time!\n");



    return 0;
}
