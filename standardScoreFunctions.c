#include "moveFunctions.h"
#include "partialScoreFunctions.h"
#include "standardScoreFunctions.h"
#include "constants.h"

int calcHueristicScore(char board[NUM_ROWS][NUM_COLS])
{
  int score = 0;
  score += TILE_SCORE_WEIGHT*(calcScore(board, 'w') - calcScore(board, 'b'));
  score += POSITION_SCORE_WEIGHT*calcPositionScore(board);
  score += MOBILITY_SCORE_WEIGHT*calcMobilityScore(board);
  score += STABILITY_SCORE_WEIGHT*calcStabilityScore(board);
  return score;
}

int calcMobilityScore(char board[NUM_ROWS][NUM_COLS])
{
  return partialMobilityScore(board, 'w') - partialMobilityScore(board, 'b');
}

int calcStabilityScore(char board[NUM_ROWS][NUM_COLS])
{
  return partialStabilityScore(board, 'w') - partialStabilityScore(board, 'b');
}

int calcPositionScore(char board[NUM_ROWS][NUM_COLS])
{
  return partialPositionScore(board, 'w') - partialPositionScore(board, 'b');
}

int calcCornerScore(char board[NUM_ROWS][NUM_COLS])
{
  int whiteScore = 0;
  int blackScore = 0;
  if(board[0][0] == 'w')
  {
    whiteScore += 1;
  }
  else if(board[0][0] == 'b')
  {
    blackScore += 1;
  }

  if(board[0][7] == 'w')
  {
    whiteScore += 1;
  }
  else if(board[0][7] == 'b')
  {
    blackScore += 1;
  }

  if(board[7][0] == 'w')
  {
    whiteScore += 1;
  }
  else if(board[7][0] == 'b')
  {
    blackScore += 1;
  }

  if(board[7][7] == 'w')
  {
    whiteScore += 1;
  }
  else if(board[7][7] == 'b')
  {
    blackScore += 1;
  }

  return whiteScore - blackScore;
}

