#include "constants.h"

int calcHueristicScore(char board[NUM_ROWS][NUM_COLS]);

int calcCornerScore(char board[NUM_ROWS][NUM_COLS]);

int calcPositionScore(char board[NUM_ROWS][NUM_COLS]);

int calcMobilityScore(char board[NUM_ROWS][NUM_COLS]);

int calcStabilityScore(char board[NUM_ROWS][NUM_COLS]);
