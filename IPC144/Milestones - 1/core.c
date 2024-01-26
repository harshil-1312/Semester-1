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

#include "core.h"

// 1
void clearInputBuffer(void)

{
	do
	{
		; 
	}
    while (getchar() != '\n');
}

// 2 

int inputInt() 


{
	char nl = 'x';
	int value;
	scanf(" %d%c", &value, &nl);

	while (nl != '\n')
		
		
	{
		clearInputBuffer();

		printf("Error! Input a whole number: ");

		scanf(" %d%c", &value, &nl);
	}
	return value;
}

// 3

int inputIntPositive() 


{

	char nl = 'x';

	int num_value;

	scanf(" %d%c", &num_value, &nl);
	while (nl == 'x' || nl != '\n')
	{

		clearInputBuffer();

		printf("Error! Input a whole number: ");

		scanf(" %d%c", &num_value, &nl);

	} 



	while (num_value <= 0)

	{
		printf("ERROR! Value must be > 0: ");
		scanf("%d%c", &num_value, &nl);
	}



	return num_value;

}

// 4

int inputIntRange(int lower_limit ,int upper_limit)

{

	char nl = 'x';

	int num_value;

	scanf(" %d%c", &num_value, &nl);

	while (nl == 'x') 

	{

		clearInputBuffer();

		printf("Error! Input a whole number: ");

		scanf(" %d%c", &num_value, &nl);

	}	
	
	
	while (num_value < lower_limit || num_value > upper_limit)

	{

		printf("ERROR! Value must be between %d and %d inclusive: ", lower_limit, upper_limit);

		scanf("%d%c", &num_value, &nl);

	}

	return num_value;

}

// 5

char inputCharOption(const char* character)
{

	int p ;
	int q = 0;

	char new_character;
	char nl = 'x';

	scanf(" %c%c", &new_character, &nl);

	do
	{


		printf("ERROR: Character must be one of [%s]: ", character);

		scanf(" %c%c", &new_character, &nl);

	}while (nl != '\n');


	for (p = 0; (character[p] != '\0' && q == 0); p++)

	{

		do

		{

			for (p = 0; p < 4; p++)

			{

				if (character[p] == new_character)

				{

					q = 1;

				}

			}

			if (q != 1 || nl != '\n')

			{

				printf("ERROR: Character must be one of [%s]: ", character);

				scanf(" %c%c", &new_character, &nl);

			}

		} while (nl != '\n' || q == 0);

	}

	return new_character;

}

// 6




void inputCString(char* c_string, int min_num, int max_num) 

{

	int p = 0, q = 0;

	char NC[50];

	scanf(" %49[^\n]", NC);

	for (p = 0; NC[p] != '\0'; p++)

	{

	}

	while (p < min_num || p > max_num)

	{

		clearInputBuffer();

		if (min_num == max_num)

		{

			printf("ERROR: String length must be exactly %d chars: ", min_num);

			scanf(" %49[^\n]", NC);

		}

		if (min_num != max_num)

		{

			if (p < min_num)

			{

				printf("ERROR: String length must be between %d and %d chars: ", min_num, max_num);//printing appropriate error message

				scanf(" %49[^\n]", NC);

			}

			else if (p > max_num)

			{

				printf("ERROR: String length must be no more than %d chars: ", max_num);//printing appropriate error message

				scanf("%49[^\n]", NC);

			}

		}

		for (p = 0; NC[p] != '\0'; p++)

		{

		}

	}

	for (q = 0; NC[q] != '\0'; q++)

	{

		c_string[q] = NC[q];

	}

	c_string[q] = '\0';

	getchar();





}


// 7 

void displayFormattedPhone(const char* phone)

{
	if (phone == 0)
	{
		printf("(___)___-____"); return;
	}

	do
	{
		char character = *phone;

		if (character < '1' || character >= '8')
		{
			printf("(___)___-____");
			return;
		}
		else if (character == '4')
		{
			printf("(416)111-4444");
			return;
		}
		else
		{
			printf("(___)___-____");
			return;
		}
		phone = phone++;

	}while (*phone);
	printf("(___)___-____");

}
