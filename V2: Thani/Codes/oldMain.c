


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void mainMenu()
{
    while (true)
    {
        system("cls");

        printf("\n=================");
        printf("\n|| Tic Tac Toe ||");
        printf("\n=================\n\n");

        printf("| Main Menu |");
        printf("\n   > [1] Player vs Player");
        printf("\n   > [2] Player vs AI");
        printf("\n   > [3] AI vs AI");
        printf("\n   > [4] Exit");

        printf("\n >> Enter an option [1-4]: ");
        char userChoice;
        scanf(" %c", &userChoice);
        switch (userChoice)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("\n[ Exiting... (•‿•) ]");
                exit(0);
            default:
                printf("\n[!] Invalid Option!");
                continue;
        }
    }
}

void initializeGame(char player1Name[], char player2Name[], char *player1SymbolPointer, char *player2SymbolPointer)
{
    // for player 1
    printf("[Player 1]\n");
    printf(" > Enter your name: ");
    scanf("%s", player1Name);
    printf(" > Enter your symbol: ");
    scanf(" %c", player1SymbolPointer);   

    // for player 2
    printf("\n[Player 2]\n");
    printf(" > Enter your name: ");
    scanf("%s", player2Name);
    printf(" > Enter your symbol: ");
    scanf(" %c", player2SymbolPointer);
}

void displayBoard(char boardToDisplay[], int boardSize)
{
    printf("\n");
    for (int i = 1; i <= strlen(boardToDisplay); i++)       // starting from index 1 instead of 0
    {
        if ((i % boardSize) != 0){   // if it is not the last element of the row
            printf("   %c   |", boardToDisplay[i-1]);
        }
        else{
            printf("   %c   \n\n", boardToDisplay[i-1]);
            if (i < strlen(boardToDisplay)){      // if it is not the last row
                for (int j = 1; j <= boardSize; j++){ printf("--------"); }
            }
        }
    }   
}

int getPlayerMove(char gameBoard[], char playerName[])
{
    printf("\n[%s]\n", playerName);

    while (true)
    {
        printf("Enter position: ");
        int playerMove;
        scanf("%d", &playerMove);

        if (playerMove < 1 || playerMove > 9){
                printf("> Position doesn't exist!\n");
                continue;
        }
        else if (gameBoard[playerMove - 1] != '0'){
                printf("> Position already filled!\n");
                continue;
        }
        
        return playerMove;
    }
}

void updateBoard(char boardToUpdate[], int playerMove, char playerSymbol)
{
    boardToUpdate[playerMove - 1] = playerSymbol;
}

int checkBoard(char boardToCheck[], char player1Symbol, char player2Symbol)
{
    /*
        checks every postion along the first diagonal from position 1

        returns -1, 0, or 1
        -1: draw
        0: continue
        1: player 1 won
        2: player 2 won
    */

    // u can use a 3 for loops for the below 3 sections: 1) horizontally 2) vertically 3) diagonally
    // for i in range 3, and inside of []: [i], [i+3], [i+6]
    // use a counter for total moves played by the 1st player; impelment the following if statements when count is >= 3


    // checking horizontally (rows) for equality
    if      ((boardToCheck[0] == boardToCheck[1]) && (boardToCheck[1] == boardToCheck[2])){     // row 1 (1,2,3)
        char winnerSymbol = boardToCheck[0];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    else if ((boardToCheck[3] == boardToCheck[4]) && (boardToCheck[4] == boardToCheck[5])){     // row 2 (4,5,6)
        char winnerSymbol = boardToCheck[3];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    else if ((boardToCheck[6] == boardToCheck[7]) && (boardToCheck[7] == boardToCheck[8])){     // row 3 (7,8,9)
        char winnerSymbol = boardToCheck[6];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    } 

    // checking vertically (columns) for equality
    else if ((boardToCheck[0] == boardToCheck[3]) && (boardToCheck[3] == boardToCheck[6])){     // column 1 (1,4,7)
        char winnerSymbol = boardToCheck[0];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    else if ((boardToCheck[1] == boardToCheck[4]) && (boardToCheck[4] == boardToCheck[7])){     // column 2 (2,5,8)
        char winnerSymbol = boardToCheck[1];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    else if ((boardToCheck[2] == boardToCheck[5]) && (boardToCheck[5] == boardToCheck[8])){     // column 3 (3,6,9)
        char winnerSymbol = boardToCheck[2];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }

    // checking diagonally (diagonals) for equality
    else if ((boardToCheck[0] == boardToCheck[4]) && (boardToCheck[4] == boardToCheck[8])){     // diagonal 1 (1,5,9)
        char winnerSymbol = boardToCheck[0];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    else if ((boardToCheck[2] == boardToCheck[4]) && (boardToCheck[4] == boardToCheck[6])){     // diagonal 2 (3,5,7)
        char winnerSymbol = boardToCheck[2];
        if      (winnerSymbol == player1Symbol) { return 1; }
        else if (winnerSymbol == player2Symbol) { return 2; }
    }
    
    for (int i = 0; i < 9; i++)
    {
        if       (boardToCheck[i] == '0')  { return 0;  }        // there is still empty space available on the board, so returns 0 (continue game)
        else if  (i == 8)                  { return -1; }        // the loop reached the end of the board and found no empty space ('0'), so returns -1 (draw)
    }
}

int main()
{
    char gameBoard[] = "000000000";
    char player1Name[15], player2Name[15];
    char player1Symbol, player2Symbol;

    initializeGame(player1Name, player2Name, &player1Symbol, &player2Symbol);
    displayBoard(gameBoard);

    int playerTurn = 0;
    char playerName[15];
    char playerSymbol;  
    while (true)
    {
        
        if ((playerTurn % 2) == 0){
            strcpy(playerName, player1Name);
            playerSymbol = player1Symbol;
        }
        else{
            strcpy(playerName, player2Name);
            playerSymbol = player2Symbol;
        }

        int playerMove = getPlayerMove(gameBoard, playerName);
        updateBoard(gameBoard, playerMove, playerSymbol);
        displayBoard(gameBoard);

        int gameStatus = checkBoard(gameBoard, player1Symbol, player2Symbol);   
        switch (gameStatus)
        {
            case  0:  playerTurn++;  break;     // do nothing & continue game

            case -1:  printf("\n==================\n[ >< ]  DRAW!  [ >< ]\n================");               return 0;
            case  1:  printf("\n=======================\n[* * *] WINNER: %s!\n=======================", player1Name);  return 0;
            case  2:  printf("\n=======================\n[* * *] WINNER: %s!\n=======================", player2Name);  return 0;
        }
    }
}