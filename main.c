#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "testFunctions.h"
#include "moveFunctions.h"
#include "bestMove.h"

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
void displayBoard(char board[NUM_ROWS][NUM_COLS])
{
  for (int r = 0; r < NUM_ROWS; r++)
  {
    for (int c = 0; c < NUM_COLS; c++)
    {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
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

  displayBoard(board);

  int i = 0;
  while (hasPossibleMove(board, 'b') || hasPossibleMove(board, 'w'))
  {
    char currColor;
    char *colorString;
    if (i % 2 == 0)
    {
      currColor = 'b';
      colorString = "Black";
    }
    else
    {
      currColor = 'w';
      colorString = "White";
    }

    if (!hasPossibleMove(board, currColor))
    {
      printf("%s has no possible moves.\n", colorString);
      i++;
      continue;
    }

    if (i % 2 == 0)
    {
      printf("It is now %s\'s turn. Please input the row and column values of the tile you wish to place, separated by a space.\n", colorString);
      int row;
      int col;
      scanf("%d %d", &row, &col);

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
    printf("White is the winner!");
  }
  else if (blackScore > whiteScore)
  {
    printf("Black is the winner!");
  }
  else
  {
    printf("The game is a tie!");
  }
}