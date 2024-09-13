#include <stdio.h>
#include <stdlib.h>
#include "moveFunctions.h"
#include "partialScoreFunctions.h"
#include "standardScoreFunctions.h"
#include "constants.h"
#include "testFunctions.h"

void assert(int expected, int result, char * testName)
{
  char * passOrFail = "FAILED";
  if(expected == result)
  {
    passOrFail = "PASSED";
  }

  printf("%s %s expected: %d result: %d\n", passOrFail, testName, expected, result);
}

void testCalcMobilityScore()
{
   char board[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', 'b', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  
  int result = calcMobilityScore(board);
  int expected = 0;
  
  assert(expected, result, "testCalcMobilityScore");

  char board2[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'w', 'w', 'w', '*', '*'},
                                    {'*', '*', '*', 'w', 'b', 'w', '*', '*'},
                                    {'*', '*', '*', 'w', 'w', 'w', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  
  result = calcMobilityScore(board2);
  expected = -8;
  
  assert(expected, result, "mobilityTest2");

  char board3[NUM_ROWS][NUM_COLS] = {{'*', 'w', 'w', 'w', 'w', 'w', 'w', '*'},
                                    {'*', 'b', 'b', 'b', 'b', 'b', 'b', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  
  result = calcMobilityScore(board3);
  expected = 8;
  assert(expected, result, "mobilityTest3");

  char board4[NUM_ROWS][NUM_COLS] = {{'b', 'w', 'w', 'w', 'w', 'w', 'w', 'b'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  
  result = calcMobilityScore(board4);
  expected = 0;
  assert(expected, result, "mobilityTest4");
}

void testCornerScore()
{
  char board[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  
  int result = calcCornerScore(board);
  int expected = 0;
  assert(expected, result, "cornerTest1");

  char board2[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', 'w'}};
  
  result = calcCornerScore(board2);
  expected = 2;
  assert(expected, result, "cornerTest2"); 

  char board3[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', 'b'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', 'w'}};
  
  result = calcCornerScore(board3);
  expected = 1;
  assert(expected, result, "cornerTest3"); 

  char board4[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', 'b'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', 'b', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', 'w'}};
  
  result = calcCornerScore(board4);
  expected = 1;
  assert(expected, result, "cornerTest4");
}

void testTileStability()
{
  char board[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  int result = tileStability(board, 'w', 2, 2);
  int expected = 0;
  assert(expected, result, "tileStabilityTest1");

  char board2[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board2, 'w', 0, 0);
  expected = 0;
  assert(expected, result, "tileStabilityTest2");

  char board3[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board3, 'w', 0, 0);
  expected = 1;
  assert(expected, result, "tileStabilityTest3");

  char board4[NUM_ROWS][NUM_COLS] = {{'b', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board4, 'w', 0, 0);
  expected = 0;
  assert(expected, result, "tileStabilityTest4");

  char board5[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board5, 'w', 2, 0);
  expected = 1;
  assert(expected, result, "tileStabilityTest5");

  char board6[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', 'b', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board6, 'w', 2, 0);
  expected = 1;
  assert(expected, result, "tileStabilityTest6");

  char board7[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'w', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board7, 'w', 3, 3);
  expected = 0;
  assert(expected, result, "tileStabilityTest7");

  char board8[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'w', 'b', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board8, 'w', 3, 3);
  expected = -1;
  assert(expected, result, "tileStabilityTest8");

  char board9[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'b', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', 'w', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board9, 'w', 3, 4);
  expected = -1;
  assert(expected, result, "tileStabilityTest9");

  char board10[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', 'w', '*', '*', '*'},
                                      {'*', '*', '*', 'b', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board10, 'w', 3, 4);
  expected = -1;
  assert(expected, result, "tileStabilityTest10");

  char board11[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', 'b', 'w', '*', '*', '*'},
                                      {'*', '*', '*', 'b', 'b', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board11, 'w', 3, 4);
  expected = -1;
  assert(expected, result, "tileStabilityTest11");

   char board12[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                       {'*', '*', '*', '*', '*', '*', '*', '*'},
                                       {'*', '*', '*', 'b', 'b', 'b', '*', '*'},
                                       {'*', '*', '*', 'b', 'w', 'b', '*', '*'},
                                       {'*', '*', '*', 'b', 'b', 'b', '*', '*'},
                                       {'*', '*', '*', '*', '*', '*', '*', '*'},
                                       {'*', '*', '*', '*', '*', '*', '*', '*'},
                                       {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board12, 'w', 3, 4);
  expected = 0;
  assert(expected, result, "tileStabilityTest12");

  char board13[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', 'w', '*', '*', '*'},
                                      {'*', '*', '*', 'b', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board13, 'b', 4, 3);
  expected = -1;
  assert(expected, result, "tileStabilityTest13");

  char board14[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'b', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board14, 'w', 2, 0);
  expected = 1;
  assert(expected, result, "tileStabilityTest14");

   char board15[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                       {'b', '*', '*', '*', '*', '*', '*', '*'},
                                       {'w', '*', '*', '*', '*', '*', '*', '*'},
                                       {'b', '*', '*', '*', '*', '*', '*', '*'},
                                       {'w', '*', '*', '*', '*', '*', '*', '*'},
                                       {'w', '*', '*', '*', '*', '*', '*', '*'},
                                       {'w', '*', '*', '*', '*', '*', '*', '*'},
                                       {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board15, 'w', 2, 0);
  expected = 1;
  assert(expected, result, "tileStabilityTest15");

  char board16[NUM_ROWS][NUM_COLS] = {{'w', 'b', 'w', 'b', 'w', 'w', 'w', 'w'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = tileStability(board16, 'w', 0, 2);
  expected = 1;
  assert(expected, result, "tileStabilityTest16");
}

void testStabilityScore()
{
  char board[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', 'w', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  int result = calcStabilityScore(board);
  int expected = 0;
  assert(expected, result, "stabilityScoreTest1");

  char board2[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', 'w', '*', '*', 'b', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', 'w', '*', '*', '*', '*'},
                                    {'*', 'w', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', 'b', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board2);
  expected = 0;
  assert(expected, result, "stabilityScoreTest2");

  char board3[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', 'w'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', 'w'}};
  result = calcStabilityScore(board3);
  expected = 4;
  assert(expected, result, "stabilityScoreTest3");

  char board4[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', 'b'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'*', '*', '*', '*', '*', '*', '*', '*'},
                                    {'b', '*', '*', '*', '*', '*', '*', 'b'}};
  result = calcStabilityScore(board4);
  expected = -2;
  assert(expected, result, "stabilityScoreTest4");

  char board5[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board5);
  expected = 8;
  assert(expected, result, "stabilityScoreTest5");

  char board6[NUM_ROWS][NUM_COLS] = {{'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'b', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'b', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'},
                                    {'b', '*', '*', '*', '*', '*', '*', '*'},
                                    {'w', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board6);
  expected = 2;
  assert(expected, result, "stabilityScoreTest6");

  char board7[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', 'w', '*', '*', '*'},
                                     {'*', '*', 'w', 'b', '*', '*', '*', '*'},
                                     {'*', '*', 'w', 'b', 'w', '*', '*', '*'},
                                     {'*', '*', 'b', 'b', 'b', '*', '*', '*'},
                                     {'*', '*', 'w', 'b', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board7);
  expected = 0;
  assert(expected, result, "stabilityScoreTest7");

  char board8[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', 'b', '*', '*', '*', '*'},
                                     {'*', '*', 'w', 'b', 'w', '*', '*', '*'},
                                     {'*', '*', 'b', 'b', 'b', '*', '*', '*'},
                                     {'*', '*', 'w', 'b', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board8);
  expected = 1;
  assert(expected, result, "stabilityScoreTest8");

  char board9[NUM_ROWS][NUM_COLS] = {{'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', 'b', '*', '*', '*', '*'},
                                     {'*', '*', 'w', '*', 'w', '*', '*', '*'},
                                     {'*', '*', 'b', '*', '*', '*', '*', '*'},
                                     {'*', '*', 'w', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'},
                                     {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board9);
  expected = -2;
  assert(expected, result, "stabilityScoreTest9");

  char board10[NUM_ROWS][NUM_COLS] = {{'w', 'w', 'b', 'w', 'w', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board10);
  expected = 0;
  assert(expected, result, "stabilityScoreTest10");

  char board11[NUM_ROWS][NUM_COLS] = {{'w', 'w', 'w', 'w', 'w', '*', '*', '*'},
                                      {'w', 'w', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'w', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board11);
  expected = 9;
  assert(expected, result, "stabilityScoreTest11");

  char board12[NUM_ROWS][NUM_COLS] = {{'w', 'w', '*', '*', '*', '*', '*', '*'},
                                      {'w', 'w', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'},
                                      {'*', '*', '*', '*', '*', '*', '*', '*'}};
  result = calcStabilityScore(board12);
  expected = 3;
  assert(expected, result, "stabilityScoreTest12");
}

void testAll()
{
  testCalcMobilityScore();
  printf("\n");
  testCornerScore(); 
  printf("\n");
  testTileStability();
  printf("\n");
  testStabilityScore();
}