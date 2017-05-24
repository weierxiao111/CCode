#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "game.h"

#define mine_number 30
#define ROWS 10
#define CLOS 10

void game()
{
	char mine[ROWS+2][CLOS+2];
	char show[ROWS+2][CLOS+2];
	int count=0;
	srand ((unsigned)time(NULL));
	memset(mine,'0',(ROWS+2)*(CLOS+2)*1);
	memset(show,'*',(ROWS+2)*(CLOS+2)*1);
	init_mine(mine,ROWS+2,CLOS+2);
	display(show,ROWS+2,CLOS+2);
	while(1)
	{
		int x=0;
		int y=0;
	    printf("请输入坐标：");
		scanf("%d%d",&x,&y);
		if (((x>=1)&&(x<=10))&&((y>=1)&&(y<=10)))
		{
			if (mine[x][y]=='1')
			{
				printf("你被炸死了，bybe\n");
				display(mine,ROWS+2,CLOS+2);
				break;
			}
			else
			{
				int ret=set_mine(mine,x,y);
				show[x][y]='0'+ret;
				count ++;
				display(show,ROWS+2,CLOS+2);
			}
		}
		if(count==100-mine_number)
		{  
			printf("你已经扫完所有雷\n");
			break;
		}
	}
}

void neum( )
{
	printf("************      扫雷            ****************\n");
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
