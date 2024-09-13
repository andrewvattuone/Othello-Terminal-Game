#include <stdlib.h>
#include "advancedScoreFunctions.h"
#include "moveFunctions.h"
#include "copyFunctions.h"

double* calcBestMove(char board[NUM_ROWS][NUM_COLS], int moveTracker, int movesAhead)
{
  double highestValue = -10000000;
  double lowestValue = 10000000;
  
  if(movesAhead == 0)
  {
    double* finalMove;
    finalMove = (double *)malloc(3*sizeof(double));
    finalMove[0] = 0;
    finalMove[1] = 0;
    finalMove[2] = advancedHueristicScore(board);
    return finalMove;
  }
  
  double * bestMove;
  bestMove = (double *)malloc(3*sizeof(double));
  bestMove[0] = 0;
  bestMove[1] = 0;
  bestMove[2] = 0;

  if(moveTracker % 2 == 0)
  {
    bestMove[2] = lowestValue;
  }
  else
  {
    bestMove[2] = highestValue;
  }

  char testBoard[NUM_ROWS][NUM_COLS];
  
  for(int r = 0; r < NUM_ROWS; r++)
  {
    for(int c = 0; c < NUM_COLS; c++)
    {
      double* oppBestMove = (double *)malloc(3*sizeof(double));
      copyBoard(testBoard, board);
      if(moveTracker%2 != 0 && makeMove(testBoard, 'w', r, c))
      {
        oppBestMove = calcBestMove(testBoard, moveTracker + 1, movesAhead - 1);
        if(oppBestMove[2] > highestValue)
        {
          highestValue = oppBestMove[2];
          bestMove[0] = r;
          bestMove[1] = c;
          bestMove[2] = highestValue;
        }
      }
      else if(moveTracker%2 == 0 && makeMove(testBoard, 'b', r, c))
      {
        oppBestMove = calcBestMove(testBoard, moveTracker + 1, movesAhead - 1);
        
        if(oppBestMove[2] < lowestValue)
        {
          lowestValue = oppBestMove[2];
          bestMove[0] = r;  
          bestMove[1] = c;
          bestMove[2] = lowestValue;
        }
      }
      
      free(oppBestMove);
    }
  }
  
  return bestMove;
}