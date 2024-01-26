
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
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MIN_PATHLENGTH 10
#define MAX_PATHLENGTH 70
#define MULTIPLE 5

struct playerinfo
{
	char Character;
	int lives;

};

struct gameinfo
{
	int path_length;
	int bombs[MAX_PATHLENGTH];
	int treasure[MAX_PATHLENGTH];
	int Moves;
};

int main(void)
{
    int end = 1;
    int q = 0,p = 0;
	struct playerinfo player;
	struct gameinfo game;
    int maxium_moves;

printf("================================\n");

printf("         Treasure Hunt!\n");

printf("================================\n");

printf("\nPLAYER Configuration\n");

printf("--------------------\n");

printf("Enter a single character to represent the player: ");

scanf(" %c", &player.Character);


end = 1;
while (end)
{
        printf("Set the number of lives: ");

		scanf(" %d", &player.lives);

		if (player.lives < MIN_LIVES || player.lives > MAX_LIVES)
		{
			printf("     Must be between 1 and 10!\n");

		}
		else
		{
			printf("Player configuration set-up is complete\n");
			end = 0;
		}
}


	printf("\nGAME Configuration\n");
	printf("------------------\n");
    end = 1;
	
    while (end)
    {

    
            
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);

		scanf(" %d", &game.path_length);

		if (game.path_length > MIN_PATHLENGTH || game.path_length < MAX_PATHLENGTH)
		{
			if (game.path_length % MULTIPLE == 0)
            {
				end = 0;
			}
			else
            {
				printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);
			}
		}
		else
        {
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);
		} 
        
    }
    
    end = 1;
    maxium_moves = (game.path_length * 75) / 100;
	while (end)
	{
		printf("Set the limit for number of moves allowed: ");

		scanf(" %d", &game.Moves);

		if (game.Moves <= maxium_moves && game.Moves >= player.lives)
		{
			end = 0;

		}
		
		else
		{
          	printf("    Value must be between %d and %d\n", player.lives, maxium_moves);
				 
		}
	} 
	
	
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n",MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    for (p = 0; p < (game.path_length / MULTIPLE); p++ ) 
    {
        printf("   Positions [%2d-%2d]: ", MULTIPLE * p + 1, MULTIPLE * p + 5);
        for (q = 0; q < MULTIPLE; q++)
        {
            scanf("%d", &game.bombs[q + ( 5 * p)]);
        }
    }

    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.",
       MULTIPLE);
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    for (p = 0; p < (game.path_length / MULTIPLE); p++) {
        printf("   Positions [%2d-%2d]: ",MULTIPLE * p + 1,
            MULTIPLE * p + 5);
        for (q = 0; q < MULTIPLE; q++) {
            scanf("%d", &game.treasure[q + ( 5 * p)]);
        }
    }
    printf("TREASURE placement set\n");




printf("\nGAME configuration set-up is complete...\n");

    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------");
    printf("\nPlayer:");
    printf("\n   Symbol     : %c", player.Character);
    printf("\n   Lives      : %d", player.lives);
    printf("\n   Treasure   : [ready for gameplay]");
    printf("\n   History    : [ready for gameplay]");

    printf("\n\nGame:\n");
    printf("   Path Length: %d\n", game.path_length);
    printf("   Bombs      : ");


    for (p = 0; p < game.path_length; p++) {
        printf("%d", game.bombs[p]);
    }
	printf("\n");
	printf("   Treasure   : ");

    for (p = 0; p < game.path_length; p++) {
        printf("%d", game.treasure[p]);

}
    printf("\n");
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~");
    printf("\n====================================\n");

return 0;
}