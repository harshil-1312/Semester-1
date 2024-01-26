
//*****************************************************************************
// Full Name  : Harshil Prajapati
// student ID#: 175255215
// Email       : hprajapati8@myseneca.ca
// Section    :IPC144ZRA.5605.2227
// Authenticity Declaration:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation
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
    int history[MAX_PATHLENGTH];
    int treasure;
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
    int q = 0, p = 0, r = 0;
    int end1 = 0;
    struct playerinfo player;
    struct gameinfo game;
    int maxium_moves;
    int nextMove = -1;
    int Treasure = 0;

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
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    for (p = 0; p < (game.path_length / MULTIPLE); p++)
    {
        printf("   Positions [%2d-%2d]: ", MULTIPLE * p + 1, MULTIPLE * p + 5);
        for (q = 0; q < MULTIPLE; q++)
        {
            scanf("%d", &game.bombs[q + (5 * p)]);
        }
    }

    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.",
           MULTIPLE);
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    for (p = 0; p < (game.path_length / MULTIPLE); p++)
    {
        printf("   Positions [%2d-%2d]: ", MULTIPLE * p + 1,
               MULTIPLE * p + 5);
        for (q = 0; q < MULTIPLE; q++)
        {
            scanf("%d", &game.treasure[q + (5 * p)]);
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

    for (p = 0; p < game.path_length; p++)
    {
        printf("%d", game.bombs[p]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (p = 0; p < game.path_length; p++)
    {
        printf("%d", game.treasure[p]);
    }
    printf("\n");
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~");
    printf("\n====================================\n");

    for (p = 0; p < game.path_length; p++)
    {
        player.history[p] = 0;
    }

    player.treasure = 0;

    do
    {
        if (nextMove > 0)
        {
            if (player.history[nextMove - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n");
            }
            else if (game.bombs[nextMove - 1] == 1 && game.treasure[nextMove - 1] == 1)
            {
                player.history[nextMove - 1] = 1;
                player.lives--;
                Treasure++;
                game.Moves--;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else if (game.bombs[nextMove - 1] == 1)
            {
                player.history[nextMove - 1] = 1;
                player.lives--;
                game.Moves--;
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            }
            else if (game.treasure[nextMove - 1] == 1)
            {
                player.history[nextMove - 1] = 1;
                Treasure++;
                game.Moves--;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            }
            else
            {
                player.history[nextMove - 1] = 1;
                game.Moves--;
                printf("===============> [.] ...Nothing found here... [.]\n");
            }

            if (game.Moves == 0)
            {
                printf("\nNo more MOVES remaining!\n");
            }
            if (player.lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }

        if (nextMove > 0)
        {
            printf("\n  ");
            for (p = 0; p < nextMove; p++)
            {
                if (p == (nextMove - 1))
                {
                    printf("%c", player.Character);
                }
                else
                {
                    printf(" ");
                }
            }
        }

        printf("\n  ");

        for (p = 0; p < game.path_length; p++)
        {
            if (player.history[p] == 0)
            {
                printf("-");
            }
            if (player.history[p] == 1)
            {
                if (game.bombs[p] == 1 && game.treasure[p] == 1)
                {
                    printf("&");
                }
                else if (game.bombs[p] == 1 && game.treasure[p] == 0)
                {
                    printf("!");
                }
                else if (game.treasure[p] == 1 && game.bombs[p] == 0)
                {
                    printf("$");
                }
                else
                {
                    printf(".");
                }
            }
        }

        printf("\n  ");

        for (p = 0; p < game.path_length; p++)
        {
            if ((p + 1) % 10 == 0)
            {
                printf("%d", ++r);
            }
            else
            {
                printf("|");
            }
        }

        r = 0;
        printf("\n  ");

        for (p = 0; p < game.path_length; p++)
        {
            if ((p + 1) % 10 == 0)
            {
                printf("0");
                r = 0;
            }
            else
            {
                printf("%d", ++r);
            }
        }
        r = 0;

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, Treasure, game.Moves);
        printf("+---------------------------------------------------+\n");

        if (player.lives > 0 && game.Moves > 0)
        {
            do
            {
                end1 = 0;
                printf("Next Move [1-%d]: ", game.path_length);
                scanf("%d", &nextMove);
                if (nextMove < 1 || nextMove > game.path_length)
                {
                    printf("  Out of Range!!!\n");
                    end1 = 1;
                }
            } while (end1 == 1);
            printf("\n");
        }

    } while (player.lives > 0 && game.Moves > 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}