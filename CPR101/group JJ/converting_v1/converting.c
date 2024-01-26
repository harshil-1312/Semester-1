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
}