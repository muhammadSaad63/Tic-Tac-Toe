#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // for system("cls") & exit(0)
#include <windows.h>    // for Sleep()
#include <stdbool.h>    // for bool, true, false


int mainMenu()
{
    while (true)
    {
        system("cls");

        printf("=================\n");
        printf("|| Tic Tac Toe ||\n");
        printf("=================\n\n");
        Sleep(1000);

        printf("| Main Menu |");
        printf("\n   > [1] Player vs Player");
        printf("\n   > [2] Player vs AI");
        printf("\n   > [3] AI vs AI");
        printf("\n   > [4] Exit");
        Sleep(2000);

        printf("\n >> Enter an option [1-4]: ");
        char userChoice;
        scanf(" %c", &userChoice);
        switch (userChoice)
        {
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4':

            default:
                printf("\n[!] Invalid Option!");
                continue;
        }
    }
}

void PvsP()
{
    printf("Running PvsP()");
}

void PvsAI()
{
    printf("Running PvsAI()");
}

void AIvsAI()
{
    printf("Running AIvsAI()");
}

int main()
{
    while (true)
    {
        int menuChoice;
        menuChoice = mainMenu();
        switch (menuChoice)
        {
            case 1: PvsP();   break;
            case 2: PvsAI();  break;
            case 3: AIvsAI(); break;
            case 4: 
                printf("\n[!] Exiting...");
                Sleep(1000);
                return 0;
        }

        char userChoice;
        while (true)
        {
            printf("\nDo you want to continue [Y/N]: ");
            scanf(" %c", &userChoice);
            if ((userChoice != 'Y') && (userChoice != 'N')){
                printf(">> [!] Inalid Input! Enter either 'Y' or 'N'");
                continue;
            }
            else{ break; }
        }
        if (userChoice == 'N'){ 
            printf("\n[!] Exiting...");
            Sleep(1000);
            return 0;   
        }
    }
}