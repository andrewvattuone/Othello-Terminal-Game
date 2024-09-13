#include "constants.h"

int partialPositionScore(char board[NUM_ROWS][NUM_COLS], char color);

int partialMobilityScore(char board[NUM_ROWS][NUM_COLS], char color);

int partialStabilityScore(char board[NUM_ROWS][NUM_COLS], char color);

int tileStability(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol);