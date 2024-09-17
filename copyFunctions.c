#include "constants.h"

void copyBoard(char copyBoard[NUM_ROWS][NUM_COLS], char board[NUM_ROWS][NUM_COLS])
{
  for (int r = 0; r < NUM_ROWS; r++)
  {
    for (int c = 0; c < NUM_COLS; c++)
    {
      copyBoard[r][c] = board[r][c];
    }
  }
}

void copyArray(int *arr1, int *arr2, int length)
{
  for (int i = 0; i < length; i++)
  {
    arr1[i] = arr2[i];
  }
}