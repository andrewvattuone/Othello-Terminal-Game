#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "testFunctions.h"
#include "moveFunctions.h"
#include "bestMove.h"
#include "displayFunctions.h"

void displayBoard(char board[NUM_ROWS][NUM_COLS]);

void playGame();

int main(void)
{

  testAll();
  playGame();
  // 0, 0  0, 2
  // 0, 0  3, 3

  // checkTiles(board, 'b', 3, 3, 1);

  // flipTiles(board, 3, 2, 3, 4, 'b');
  // flipTiles(board, 2, 2, 4, 4, 'w');
  // flipTiles(board, 5, 4, 3, 4, 'b');
  return 0;

  // string that says whether piece is black or white
  // board that shows all the pieces on it
  // maybe store position of each piece
  // boolean that states whether a piece is on a tile of the board or not
  // create a tile out of struct
  // tile struct: char piece
}

void playGame()
{
  char board[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'w', 'b', '*', '*', '*'},
                                    {'*', '*', '*', 'b', 'w', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  // char board[NUM_ROWS][NUM_COLS] = {{'w', 'w', 'w', 'w', 'w', 'w', 'w', '*'},
  //                               {'w', 'w', 'w', 'w', 'w', 'w', 'b', '*'},
  //                               {'w', 'w', 'w', 'w', 'w', 'b', '*', '*'},
  //                               {'*', '*', '*', 'b', 'b', '*', '*', '*'},
  //                               {'*', '*', '*', 'b', 'b', 'b', '*', '*'},
  //                               {'*', '*', '*', '*', '*', '*', '*', '*'},
  //                               {'*', '*', '*', '*', '*', '*', '*', '*'},
  //                               {'*', '*', '*', '*', '*', '*', '*', '*'}};

  printf("\nWelcome to my Othello terminal game! You (the Black player) will be playing against an AI (the White player). To read the rules of the game Othello, go here: https://www.worldothello.org/about/about-othello/othello-rules/official-rules/english. Press enter to start the game:");
  char input;
  while (input != '\n')
  {
    scanf("%c", &input);
  }
  printf("\nStarting Board State:\n\n");
  displayBoard(board);

  int i = 0;
  while (hasPossibleMove(board, 'b') || hasPossibleMove(board, 'w'))
  {
    char currColor;
    char *colorString;
    char *playerString;
    if (i % 2 == 0)
    {
      currColor = 'b';
      colorString = "Black";
      playerString = "your";
    }
    else
    {
      currColor = 'w';
      colorString = "White";
      playerString = "AI\'s";
    }

    if (!hasPossibleMove(board, currColor))
    {
      printf("%s has no possible moves.\n", colorString);
      i++;
      continue;
    }

    if (i % 2 == 0)
    {
      printf("\nIt is now your turn. Please place a %s tile on the board by inputting the row and column values of the location you wish to place the tile, separated by a space (Exapmple:4 3).\n", colorString);
      int row;
      int col;
      scanf("%d %d", &row, &col);
      row--;
      col--;

      while (!makeMove(board, currColor, row, col) && i % 2 == 0)
      {
        printf("Invalid move. Please select another tile.\n");
        scanf("%d %d", &row, &col);
      }
    }
    else
    {
      double *bestMove;
      bestMove = calcBestMove(board, i, 3);
      makeMove(board, currColor, (int)bestMove[0], (int)bestMove[1]);
    }

    printf("\n");
    printf("Board after %s\'s move (%s move):\n\n", colorString, playerString);
    displayBoard(board);
    printf("\n");
    i++;
  }

  printf("Niether player can make any moves. The game has ended!\n");
  int whiteScore = calcScore(board, 'w');
  int blackScore = calcScore(board, 'b');
  printf("White has %d tiles. Black has %d tiles.\n", whiteScore, blackScore);
  if (whiteScore > blackScore)
  {
    printf("White is the winner! The AI beat you :(");
  }
  else if (blackScore > whiteScore)
  {
    printf("Black is the winner! You won :D");
  }
  else
  {
    printf("The game is a tie!");
  }
}