// FUNDAMENTALS MODULE SOURCE

#define CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80

#define NUM_INPUT_SIZE 10

#include "fundamentals.h"

void fundamentals (void) {


printf("* start of Indexing Strings Demo *\n");
char bufferl [BUFFER_SIZE];
char numInput [NUM_INPUT_SIZE]; size_t position;

do{

printf("Type not empty string (q to quit):\n");
fgets (bufferl, BUFFER_SIZE, stdin);

bufferl[strlen(bufferl)-1]='\0';

if (strcmp(bufferl,"q")!=0) {
printf("Type the character position within the string:\n");
fgets (numInput, NUM_INPUT_SIZE, stdin);
numInput [strlen(numInput) - 1]='\0';
position = atoi(numInput);

if (position >= strlen (bufferl)) {
position = strlen(bufferl) - 1;
printf("Too big... Position reduced to max. availbale\n");
}
printf("The character found at %d position is \'%c\'\n", (int)position, bufferl[position]);
}

} while(strcmp(bufferl, "q") != 0);
printf("* End of Indexing Strings Demo *\n\n");


printf("*** Start of Measuring Strings Demo ***\n");
char buffer2[BUFFER_SIZE];
do {
    printf("Type a String (q - to quit):\n");
    fgets(buffer2,BUFFER_SIZE,stdin);
    buffer2[strlen(buffer2) - 1] = '\0' ;
    if (strcmp(buffer2, "q") !=0)
        printf("The length of \'%s\'is %d characters\n", buffer2, (int)strlen(buffer2)) ;
} while (strcmp(buffer2, "q") !=0);
printf("*** End of Measuring Strings Demo ***\n\n");
}
