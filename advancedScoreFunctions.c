#include "moveFunctions.h"
#include "partialScoreFunctions.h"
// #include "constants.h"
#include "advancedScoreFunctions.h"

double advancedHueristicScore(char board[NUM_ROWS][NUM_COLS])
{
  double score = 0.0;
  double whiteTileScore = (double)calcScore(board, 'w');
  double blackTileScore = (double)calcScore(board, 'b');
  score += TILE_SCORE_WEIGHT * calcAdvancedScore(whiteTileScore, blackTileScore);
  score += POSITION_SCORE_WEIGHT * advancedPositionScore(board);
  score += MOBILITY_SCORE_WEIGHT * advancedMobilityScore(board);
  score += STABILITY_SCORE_WEIGHT * advancedStabilityScore(board);
  return score;
}

double advancedMobilityScore(char board[NUM_ROWS][NUM_COLS])
{
  double whiteScore = partialMobilityScore(board, 'w');
  double blackScore = partialMobilityScore(board, 'b');

  return calcAdvancedScore(whiteScore, blackScore);
}

double advancedStabilityScore(char board[NUM_ROWS][NUM_COLS])
{
  double whiteScore = (double)partialStabilityScore(board, 'w');
  double blackScore = (double)partialStabilityScore(board, 'b');

  return calcAdvancedScore(whiteScore, blackScore);
}

double advancedPositionScore(char board[NUM_ROWS][NUM_COLS])
{
  double whiteScore = (double)partialPositionScore(board, 'w');
  double blackScore = (double)partialPositionScore(board, 'b');

  return calcAdvancedScore(whiteScore, blackScore);
}

double calcAdvancedScore(double whiteScore, double blackScore)
{
  if (whiteScore + blackScore != 0)
  {
    return 100 * ((whiteScore - blackScore) / (whiteScore + blackScore));
  }
  else
  {
    return 0;
  }
}
