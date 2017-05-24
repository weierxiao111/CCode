#ifndef __GAME_H
#define __GAME_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ROWS  3
#define CLOS  3
void show_chess(char chess[ROWS][CLOS],int row, int clo);
void player_move (char chess[ROWS][CLOS], int row,  int clo);
void computer_move (char chess[ROWS][CLOS], int row,  int clo);
char check_win(char chess[ROWS][CLOS], int row,  int clo);
int is_full(char chess[ROWS][CLOS], int row,  int clo);

#endif 