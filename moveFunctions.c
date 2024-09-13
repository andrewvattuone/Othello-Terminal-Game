#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "moveFunctions.h"

void flipTiles(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol, int endRow, int endCol)
{
  int currRow = startRow;
  int currCol = startCol;

  board[currRow][currCol] = color;

  while(currRow != endRow || currCol != endCol)
  {
    if(currRow < endRow)
    {
      currRow++;
    }
    else if(currRow > endRow)
    {
      currRow--;
    }

    if(currCol < endCol)
    {
      currCol++;
    }
    else if(currCol > endCol)
    {
      currCol--;
    }

    board[currRow][currCol] = color;
  }
}

int checkTiles(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol, int isMove)
{
  if(board[startRow][startCol] != '*' || startRow >= NUM_ROWS || startRow < 0 || startCol >= NUM_COLS || startCol < 0)
  {
    return 0;
  }

  int flippedTile = 0;
  int oppColorFound[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int breaks[] = {0, 0, 0, 0, 0, 0, 0, 0};

  int i = 1;
  while(startRow + i < NUM_ROWS || startRow - i >= 0 || startCol + i < NUM_COLS || startCol - i >= 0)
  {
    //                   +horizontal,  -horizontal,    +vertical,    -vertical,   ++diagonal,   +-diagonal,   -+diagonal, --diagonal
    int rowOptions[] = {    startRow,     startRow, startRow + i, startRow - i, startRow + i, startRow + i, startRow - i, startRow - i};
    int colOptions[] = {startCol + i, startCol - i,     startCol,     startCol, startCol + i, startCol - i, startCol + i, startCol - i};
    for(int j = 0; j < NUM_DIRECTIONS; j++)
    {
      if(rowOptions[j] >= NUM_ROWS || colOptions[j] >= NUM_COLS || rowOptions[j] < 0 || colOptions[j] < 0)
      {
        continue;
      }
      if(board[rowOptions[j]][colOptions[j]] == '*')
      {
        breaks[j] = 1;
        continue;
      }

      if(board[rowOptions[j]][colOptions[j]] != color && breaks[j] != 1)
      {
        oppColorFound[j] = 1;
      }
      else if(oppColorFound[j] && breaks[j] != 1)
      {
        if(isMove)
        {
          flipTiles(board, color, startRow, startCol, rowOptions[j], colOptions[j]);
        }
        else
        {
          return 1;
        }
        breaks[j] = 1;
        flippedTile = 1;
      }
      else
      {
        breaks[j] = 1;
      }
    }
    i++;
  }
  
  return flippedTile;
}

int makeMove(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol)
{
  return checkTiles(board, color, startRow, startCol, 1);
}

int checkMove(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol)
{
  return checkTiles(board, color, startRow, startCol, 0);
}

int hasPossibleMove(char board[NUM_ROWS][NUM_COLS], char color)
{ 
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      if(checkMove(board, color, r, c))
      {
        return 1;
      }
    } 
  }
  return 0;
}

int calcScore(char board[NUM_ROWS][NUM_COLS], char color)
{
  int colorTotal = 0;
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      if(board[r][c] == color)
      {
        colorTotal++;
      }
    } 
  }

  return colorTotal;
}

int calcWeightedScoreDiff(char board[NUM_ROWS][NUM_COLS])
{
  int staticWeightBoard[NUM_ROWS][NUM_COLS] = {{ 4,-3, 2, 2, 2, 2,-3, 4}, 
                                               {-3,-4,-1,-1,-1,-1,-4,-3},
                                               { 2,-1, 1, 0, 0, 1,-1, 2},
                                               { 2,-1, 0, 1, 1, 0,-1, 2},
                                               { 2,-1, 0, 1, 1, 0,-1, 2},
                                               { 2,-1, 1, 0, 0, 1,-1, 2}, 
                                               {-3,-4,-1,-1,-1,-1,-4,-3},
                                               { 4,-3, 2, 2, 2, 2,-3, 4}};

  int weightedScoreDiff = 0;

  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      if(board[r][c] == 'w')
      {
        weightedScoreDiff += staticWeightBoard[r][c];
      }
      else if(board[r][c] == 'b')
      {
        weightedScoreDiff -= staticWeightBoard[r][c];
      }
    }
  }

  return weightedScoreDiff;
}