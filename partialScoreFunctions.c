#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "moveFunctions.h"
#include "partialScoreFunctions.h"

int partialMobilityScore(char board[NUM_ROWS][NUM_COLS], char color)
{
  int score = 0;
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      score += checkMove(board, color, r, c);
    }
  }
  return score;
}

int partialStabilityScore(char board[NUM_ROWS][NUM_COLS], char color)
{
  int score = 0;
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      score += tileStability(board, color, r, c);
    }
  }

  return score;
}

int partialPositionScore(char board[NUM_ROWS][NUM_COLS], char color)
{
  int staticWeightBoard[NUM_ROWS][NUM_COLS] = {{ 4,-3, 2, 2, 2, 2,-3, 4}, 
                                               {-3,-4,-1,-1,-1,-1,-4,-3},
                                               { 2,-1, 1, 0, 0, 1,-1, 2},
                                               { 2,-1, 0, 1, 1, 0,-1, 2},
                                               { 2,-1, 0, 1, 1, 0,-1, 2},
                                               { 2,-1, 1, 0, 0, 1,-1, 2}, 
                                               {-3,-4,-1,-1,-1,-1,-4,-3},
                                               { 4,-3, 2, 2, 2, 2,-3, 4}};
  int score = 0;
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_ROWS; c++)
    {
      if(board[r][c] == color)
      {
        score += staticWeightBoard[r][c];
      }
    }
  }
  return score;
}

int tileStability(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol)
{
  if(board[startRow][startCol] != color)
  {
   return 0;
  }
  
  if(startRow == 0 && startCol == 0 || startRow == 0 && startCol == 7 || startRow == 7 && startCol == 0 || startRow == 7 && startCol == 7)
  {
    return 1;
  }

  char oppColor;
  
  if(color ==  'w')
  {
    oppColor = 'b';
  }
  else
  {
    oppColor = 'w';
  }

  if((startRow == 0 || startRow == 7) && board[startRow][0] != '*' && board[startRow][1] != '*' && board[startRow][2] != '*' && board[startRow][3] != '*' && board[startRow][4] != '*' && board[startRow][5] != '*' && board[startRow][6] != '*' && board[startRow][7] != '*')
  {
    return 1;
  }
  
  if((startCol == 0 || startCol == 7) && board[0][startCol] != '*' && board[1][startCol] != '*' && board[2][startCol] != '*' && board[3][startCol] != '*' && board[4][startCol] != '*' && board[5][startCol] != '*' && board[6][startCol] != '*' && board[7][startCol] != '*')
  {
    return 1;
  }

  //first two pairs are up and down, next two are left and right, next two are top left to bottom right diagonal, final two are bottom left to top right diagonal
  int foundWeakness[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int foundOppColor[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int potentialOppMove[] = {0, 0, 0, 0, 0, 0, 0, 0};
  
  int i = 1;
  while(startRow + i < NUM_ROWS || startRow - i >= 0 || startCol + i < NUM_COLS || startCol - i >= 0)
  {
    if(startRow+i < NUM_ROWS)
    {
      if(checkMove(board, oppColor, startRow+i, startCol) == 1 && foundWeakness[0] != 1)
      {
        potentialOppMove[0] = 1;
      }
      else if(board[startRow+i][startCol] == oppColor)
      {
        foundOppColor[0] = 1;
        foundWeakness[0] = 1;
      }
      else if(board[startRow+i][startCol] == '*')
      {
        foundWeakness[0] = 1;
      }
    }

    if(startRow-i >= 0)
    {
      if(checkMove(board, oppColor, startRow-i, startCol) == 1 && foundWeakness[1] != 1)
      {
        potentialOppMove[1] = 1;
      }
      else if(board[startRow-i][startCol] == oppColor)
      {
        foundWeakness[1] = 1;
        foundOppColor[1] = 1;
      }
      else if(board[startRow-i][startCol] == '*')
      {
        foundWeakness[1] = 1;
      }
    }

    if(startCol-i >= 0)
    {
      if(checkMove(board, oppColor, startRow, startCol-i) == 1 && foundWeakness[2] != 1)
      {
        potentialOppMove[2] = 1;
      }
      else if(board[startRow][startCol-i] == oppColor)
      {
        foundWeakness[2] = 1;
        foundOppColor[2] = 1;
      }
      else if(board[startRow][startCol-i] == '*')
      {
        foundWeakness[2] = 1;
      }
    }    

    if(startCol+i < NUM_COLS)
    {
      if(checkMove(board, oppColor, startRow, startCol+i) == 1 && foundWeakness[3] != 1)
      {
        potentialOppMove[3] = 1;
      }
      else if(board[startRow][startCol+i] == oppColor)
      {
        foundWeakness[3] = 1;
        foundOppColor[3] = 1;
      }
      else if(board[startRow][startCol+i] == '*')
      {
        foundWeakness[3] = 1;
      }
    }
    
    if(startRow-i >= 0 && startCol-i >= 0)
    {
      if(checkMove(board, oppColor, startRow-i, startCol-i) == 1 && foundWeakness[4] != 1)
      {
        potentialOppMove[4] = 1;
      }
      else if(board[startRow-i][startCol-i] == oppColor)
      {
        foundWeakness[4] = 1;
        foundOppColor[4] = 1;
      }
      else if(board[startRow-i][startCol-i] == '*')
      {
        foundWeakness[4] = 1;
      }
    }

    if(startRow+i < NUM_ROWS && startCol+i < NUM_COLS)
    {
      if(checkMove(board, oppColor, startRow+i, startCol+i) == 1 && foundWeakness[5] != 1)
      {
        potentialOppMove[5] = 1;
      }
      else if(board[startRow+i][startCol+i] == oppColor)
      {
        foundWeakness[5] = 1;
        foundOppColor[5] = 1;
      }
      else if(board[startRow+i][startCol+i] == '*')
      {
        foundWeakness[5] = 1;
      }
    }

    if(startRow+i < NUM_ROWS && startCol-i >= 0)
    {
      if(checkMove(board, oppColor, startRow+i, startCol-i) == 1 && foundWeakness[6] != 1)
      {
        potentialOppMove[6] = 1;
      }
      else if(board[startRow+i][startCol-i] == oppColor)
      {
        foundWeakness[6] = 1;
        foundOppColor[6] = 1;
      }
      else if(board[startRow+i][startCol-i] == '*')
      {
        foundWeakness[6] = 1;
      }
    }

    if(startRow-i >= 0 && startCol+i < NUM_COLS)
    {
      if(checkMove(board, oppColor, startRow-i, startCol+i) == 1 && foundWeakness[7] != 1)
      {
        potentialOppMove[7] = 1;
      }
      else if(board[startRow-i][startCol+i] == oppColor)
      {
        foundWeakness[7] = 1;
        foundOppColor[7] = 1;
      }
      else if(board[startRow-i][startCol+i] == '*')
      {
        foundWeakness[7] = 1;
      }
    } 
    i++;
  }

  if(foundOppColor[0] == 1 && potentialOppMove[1] == 1 || foundOppColor[1] == 1 && potentialOppMove[0] == 1 || foundOppColor[2] == 1 && potentialOppMove[3] == 1 || foundOppColor[3] == 1 && potentialOppMove[2] == 1 || foundOppColor[4] == 1 && potentialOppMove[5] == 1 || foundOppColor[5] == 1 && potentialOppMove[4] == 1 || foundOppColor[6] == 1 && potentialOppMove[7] == 1 || foundOppColor[7] == 1 && potentialOppMove[6] == 1)
  {
    return -1;
  }

  if(foundWeakness[0] == 1 && foundWeakness[1] == 1 || foundWeakness[2] == 1 && foundWeakness[3] == 1 || foundWeakness[4] == 1 && foundWeakness[5] == 1 || foundWeakness[6] == 1 && foundWeakness[7] == 1)
  {
    return 0;
  }

  return 1;
}