// CONVERTING MODULE SOURCE #define CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 80

#include "converting.h"

// Vi

void converting (void) {

printf("* Start of Converting strings to int Demo *\n");

char intstring[BUFFER_SIZE];

int intNumber;

do {
printf("Type an int numeric string (q to quit):\n"); 
fgets (intstring, BUFFER_SIZE, stdin); 
intstring[strlen (intstring) - 1] = '\0';

if (strcmp(intstring, "q") != 0) { 
    intNumber = atoi (intstring);
    printf("Converted number is %d\n", intNumber);
}
} while (strcmp(intstring, "q") != 0); 
printf("* End of Converting Strings to int Demo *\n\n");





// V2
 printf("*** Start of Converting Strings to double Demo ***\n");
 char doubleString[BUFFER_SIZE];
 double doubleNumber;
 do 
 {
  printf ("Type the double numeric string (q - to quit):\n");
  fgets (doubleString, BUFFER_SIZE, stdin);
  doubleString[strlen(doubleString) - 1] = '\0'; 
    if ((strcmp (doubleString,"q") !=0)) {
        doubleNumber = atof(doubleString);
        printf("Converted number is %f\n",doubleNumber);
    }
 
    }while (strcmp(doubleString , "q")!=0);
    printf("*** End of Converting Strings to double Demo ***\n\n");
}
    