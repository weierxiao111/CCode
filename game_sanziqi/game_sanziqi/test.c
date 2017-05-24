#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "game.h"

#define ROWS  3
#define CLOS  3

void game ()
{
	char chess[ROWS][CLOS];
	char ret;
	srand((unsigned)time(NULL));
	memset(chess,' ',ROWS*CLOS*sizeof(char));
    show_chess(chess,ROWS,CLOS);
	while(1)
	{
	player_move(chess,ROWS,CLOS);
	show_chess(chess,ROWS,CLOS);
	ret = check_win(chess,ROWS,CLOS);
	if(ret!=' ')
		break;
	printf("电脑下\n");
	computer_move(chess,ROWS,CLOS);
	show_chess(chess,ROWS,CLOS);
	 ret = check_win(chess,ROWS,CLOS);
	if(ret!=' ')
		break;
	}
	if(ret=='X')
	{
		printf("恭喜你战胜电脑\n");
	}
	if(ret=='Y')
	{
		printf("you   lose\n");
	}
	if(ret=='q')
	{
		printf("你获得平局\n");
	}
}
void neum( )
{
	printf("************      三子棋           ****************\n");
	printf("************   play :   case 1    ****************\n");
	printf("************   exit :   case 0    ****************\n");
	printf("************   &&&&&&&&&&&&&&&&   ****************\n");
}

int main()
{
	int key=0;
	do 
	{
    neum();
	printf("请选择：");
	scanf("%d",&key);
    switch(key)
	{
	case 0:
		break;
	case 1:
		game();
		break;
	default:
		printf("输入错误，重新选择\n");
		break;
	}
	}while(key);

	return 0;
}
