#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

void printBorder()
{
    printf("  +");
    for (int i = 0; i < NUM_COLS * 2 + 1; i++)
    {
        printf("-");
    }

    printf("+\n");
}

void displayBoard(char board[NUM_ROWS][NUM_COLS])
{

    printf("    ");
    for (int i = 0; i < NUM_COLS; i++)
    {
        printf("%d ", i + 1);
    }

    printf("\n");
    printBorder();

    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            if (c == 0)
            {
                printf("%d | ", r + 1);
            }
            printf("%c ", board[r][c]);
            if (c == NUM_COLS - 1)
            {
                printf("|");
            }
        }
        printf("\n");
    }
    printBorder();
}