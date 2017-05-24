#ifndef   __GAME_H_
#define   __GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define mine_number 30
#define ROWS 10
#define CLOS 10

void init_mine ( char mine[ROWS+2][CLOS+2], int row ,int clo);
void display(char board[ROWS+2][CLOS+2],int row,int clo);
int set_mine(char mine[ROWS+2][CLOS+2], int x, int y);


#endif 