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
	printf("������\n");
	computer_move(chess,ROWS,CLOS);
	show_chess(chess,ROWS,CLOS);
	 ret = check_win(chess,ROWS,CLOS);
	if(ret!=' ')
		break;
	}
	if(ret=='X')
	{
		printf("��ϲ��սʤ����\n");
	}
	if(ret=='Y')
	{
		printf("you   lose\n");
	}
	if(ret=='q')
	{
		printf("����ƽ��\n");
	}
}
void neum( )
{
	printf("************      ������           ****************\n");
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
	printf("��ѡ��");
	scanf("%d",&key);
    switch(key)
	{
	case 0:
		break;
	case 1:
		game();
		break;
	default:
		printf("�����������ѡ��\n");
		break;
	}
	}while(key);

	return 0;
}
