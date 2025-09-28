/*
    see notes 4,5
*/

#include <time.h>       // for time()
#include <stdio.h>
#include <string.h>     // for strlen()
#include <stdlib.h>     // for rand(), srand()
//#include <stdbool.h>


int lvl1_firstAvailable(char gameBoard[], char emptyPositionCharacter)     // plays 1st available position; returns postion, not index
{
    int moveToPlay;

    for (int i = 1; i <= strlen(gameBoard); i++)
    {
        if (gameBoard[i-1] == emptyPositionCharacter){
            moveToPlay = i;
            break;
        }
    }

    return moveToPlay;
}

int lvl2_randomPosition(char gameBoard[], char emptyPositionCharacter)     // play any random position
{
    /*
        had 2 possible approaches for this:
            1) keep generating random numbers and then using them as index in a long character array to see if it is empty at that position 
            2) make another array of the size of the original array and keep appending to it the index of empty positons in the orignal array. and then picking a random address from the new array
        chose approach 2 since it gives uniform results in a consistent timeframe
    */
    
    int moveToPlay;

    // creates an array containing index of all empty spaces in gameBoard
    int emptyPositionArray[strlen(gameBoard)];      // make an array with length equal to the size of the gameBoard
    int index = 0;
    for (int i = 1; i <= strlen(gameBoard); i++)
    {
        if (gameBoard[i-1] == emptyPositionCharacter){
            emptyPositionArray[index] = i;
            index++;        // index will always be >= 1
        }
    }

    srand(time(NULL));      // seeding random generater (rand())
    int randomIndex = rand() % index;       // generates a random integer between 0 and index
    moveToPlay = emptyPositionArray[randomIndex];         // the element at the random index is saved into moveToPlay

    return moveToPlay;
}

int lvl3_centerCornerRandom(char gameBoard[], int boardSize, char emptyPositionCharacter)     // prioritizes corners & the centre, then plays like thani()
{
    /*
        prioritizes corners & centres, then plays like random()
    */ 
    int moveToPlay;
    
    return moveToPlay;
}

int lvl4_checkWinLvl3(char gameBoard[], int boardSize)     // tries to play win, then plays lvl3
{
    /*
        Before playing, check all possible moves:
            - If a move immediately wins, take it.
            - Otherwise, play random (or follow another strategy).
    */
    int moveToPlay;

    return moveToPlay;
}

int lvl5_checkWinStopLossLvl3(char gameBoard[], int boardSize)     // try to win --> try to not lose --> then play lvl3
{    
    /*
        1) if i can win, i will play that
        2) if the opponent can win, i will block that
        3) else i will play like lvl3
    */
    int moveToPlay;

    return moveToPlay;
}

int lvl6_joker(char gameBoard[], int boardSize)     // joker/goon
{
    int moveToPlay;

    return moveToPlay;
}

int lvl7_babyMiniMax(char gameBoard[], int boardSize)     // mini minimax (looks 2 moves ahead)
{
    int moveToPlay;

    return moveToPlay;
}

int lvl8_miniMax(char gameBoard[], int boardSize)     // minimax (only for 3x3)
{
    int moveToPlay;

    return moveToPlay;
}

void aiMenu()
{
    printf
    (       "Select AI:"   
            "\n  [1]  Mr. Guess     (Random)"
            "\n    (I am a BOT!)"
            "\n  [2]  Mr. Click     (First open)"
            "\n    (I am a BOT!)"
            "\n  [3]  Mr. Edge      (Center/corner priority)"
            "\n    (I am a BOT!)"
            "\n  [4]  Mr. Block     (Win/Block moves)"
            "\n    (I am a BOT!)"
            "\n  [5]  Mr. Fork      (Advanced traps)"
            "\n    (I am a BOT!)"
            "\n  [6]  Mr. Infinite  (Unbeatable)"
            "\n    (I am a BOT!)"
    );
}


int main()
{ 
    aiMenu();
    
    return 0; 
}