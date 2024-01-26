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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"


void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}



void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


int inputInt(void)
{

    int variable = -1;
    char new_char = '\0';
    int done = 1;
    do
    {
        scanf(" %d%c", &variable, &new_char);
        if (new_char != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            done = 0;
        }

    } while (done);

    return variable;
}



int inputIntPositive(){
    int result = -1;
    do{
        result = inputInt();
    } while (result < 0 && printf("ERROR! Value must be > 0: "));
    return result;
}




int inputIntRange(int min_limit, int max_limit)
{
   int value = inputInt();
  
   while (value < min_limit || value > max_limit)
   {
       printf("Error! Value must be between %d and %d inclusive: ", min_limit, max_limit);
       value = inputInt();
   }
   return value;
}


char inputCharOption(const char *character)
{
    char result = '\0';
    char next_char = '\0';
    int x = 0;
    int len =strlen(character);
    int done = 1;
    do
    {
        scanf(" %c%c", &result, &next_char);

        if (next_char == '\n')
        {
            for (x = 0; x < len && done; x++)
                if (character[x] == result)
                    done = 0;
        }
        else 
        printf("ERROR: Character must be one of [%s]: ", character);


    } while (done);

    return result;
}



void inputCString(char *input_string, int min_l, int max_l)
{
    char string_input[200] = {'\0'};
    int done = 0;
    int i = 0;


    do
    {
        scanf(" %199[^\n]%*c", string_input);
        for (i = 1; string_input[i]; i++);

        if (min_l == max_l)
        {
            if (i == min_l)
            {
               strcpy(input_string,string_input);
                done = 1;
            }
        }
        else
        {
            if (i >= min_l && i <= max_l)
            {
                strcpy(input_string,string_input);
                done = 1;
            }
        }
        if (!done)
        {
            if (min_l == max_l)
            {
                printf("ERROR: String length must be exactly %d chars: ", min_l);
            }
            else if (min_l == 0||i>max_l)
            {
                printf("ERROR: String length must be no more than %d chars: ", max_l);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min_l, max_l);
            }
        }

    } while (!done);
}



void displayFormattedPhone(const char *phone)
{
    int i = 0;

    int done = 1;
    
    if (phone != NULL)
    {
        for (i = 0; phone[i] && done; i++)
        {

            if (phone[i] < 48 || phone[i] > 57)
            {
                done = 0;
            }
        }
    }
    if (done && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", phone[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", phone[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", phone[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}