#include "constants.h"

void flipTiles(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol, int endRow, int endCol);

int checkTiles(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol, int isMove);

int makeMove(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol);

int checkMove(char board[NUM_ROWS][NUM_COLS], char color, int startRow, int startCol);

int hasPossibleMove(char board[NUM_ROWS][NUM_COLS], char color);

int calcScore(char board[NUM_ROWS][NUM_COLS], char color);

int calcWeightedScoreDiff(char board[NUM_ROWS][NUM_COLS]);