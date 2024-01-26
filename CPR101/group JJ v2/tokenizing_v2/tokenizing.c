#define CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 300
#include "tokenizing.h"

void tokenizing () {
printf ("* Start of Tokenizing Words Demo *\n");
char words [BUFFER_SIZE] ;
char* nextword = NULL;
int wordscounter;

do
{
 printf ("Type a few words separated by space (g - to quit): \n");
fgets (words, BUFFER_SIZE, stdin) ;
words [strlen (words) - 1] = '\0';
if (strcmp (words, "q") != 0) {
    nextword = strtok (words, " ");
    wordscounter = 1;
    while (nextword) {
        printf ("Word %d is \'%s\'\n", wordscounter++, nextword) ;
nextword = strtok (NULL," ");
    }
}
}while (strcmp (words, "q") != 0);
printf ("* End of Tokenizing Words Demo ***In\n");


printf("*** Start of Tokenizing Phrases Demo ***\n") ;
char phrases[BUFFER_SIZE];
char* nextPhrase= NULL;
int phrasesCounter;
do{
 printf ("Type a few phrases separated by comma (q- to quit) : \n");
 fgets (phrases, BUFFER_SIZE,stdin);
 phrases [strlen (phrases) - 1] = '\0';

 if ((strcmp (phrases,"q") != 0)) {
 nextPhrase = strtok(phrases,",");
 phrasesCounter = 1;
 while (nextPhrase) {
    printf ("Phrase # %d is \'%s\'\n", phrasesCounter++, nextPhrase);
   nextPhrase= strtok (NULL,",");
  }
}
}while (strcmp (phrases,"q") != 0);
printf("*** End of Tokenizing Phrases Demo ***\n\n") ;
}
