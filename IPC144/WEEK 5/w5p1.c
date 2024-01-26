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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{


     int year ; 
     int month; 


    printf("General Well-being Log");
    printf("\n======================\n");

 do
 {
 
    printf("Set the year and month for the well-being log (YYYY MM): ");
    scanf("%d %d", &year, &month);
    
    
    if ((year<2012 || year>2022) && (month<1 || month>12))

    {
    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
    printf("   ERROR: Jan.(1) - Dec.(12)\n");    
    }
        
    else  if (year<2012 || year>2022)
    
    {
    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
    }

    else if(month<1 || month>12)

    {
    printf("   ERROR: Jan.(1) - Dec.(12)\n");
    }


 } while (2012 > year || year > 2022 || month < 1 || month > 12);
 
    printf("\n");
    printf("*** Log date set! ***\n");
     
     switch (month)
     {
         case 1: printf("\nLog starting date: %d-JAN-01\n", year);
         break;
         case 2: printf("\nLog starting date: %d-FEB-01\n", year);
         break;
         case 3: printf("\nLog starting date: %d-MAR-01\n", year);
         break;
         case 4: printf("\nLog starting date: %d-APR-01\n", year);
         break;
         case 5: printf("\nLog starting date: %d-MAY-01\n", year);
         break;
         case 6: printf("\nLog starting date: %d-JUN-01\n", year);
         break;
         case 7: printf("\nLog starting date: %d-JUL-01\n", year);
         break;
         case 8: printf("\nLog starting date: %d-AUG-01\n", year);
         break;
         case 9: printf("\nLog starting date: %d-SEP-01\n", year);
         break;
         case 10: printf("\nLog starting date: %d-OCT-01\n", year);
         break;
         case 11: printf("\nLog starting date: %d-NOV-01\n", year);
         break;
         case 12: printf("\nLog starting date: %d-DEC-01\n", year);
         break;
     }
     
return 0;
}