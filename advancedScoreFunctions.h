#include "constants.h"

double advancedHueristicScore(char board[NUM_ROWS][NUM_COLS]);

double advancedPositionScore(char board[NUM_ROWS][NUM_COLS]);

double advancedMobilityScore(char board[NUM_ROWS][NUM_COLS]);

double advancedStabilityScore(char board[NUM_ROWS][NUM_COLS]);

double calcAdvancedScore(double whiteScore, double blackScore);