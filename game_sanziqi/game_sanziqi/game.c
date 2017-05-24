#include "game.h"
void show_chess(char chess[ROWS][CLOS],int row, int clo)
{
	int i=0;
	for(i=0;i<3;i++)
	{
	printf("%c |%c |%c \n",chess[i][0],chess[i][1],chess[i][2]);
	if(i==2)  break;
	printf("__|__|__\n");
	}
}

void player_move (char chess[ROWS][CLOS], int row,  int clo)
{
	int x=0;
	int y=0;
	printf("请输入你要下的位置：");
	while(1)
	{
	    scanf("%d%d",&x,&y);
	    if(((x>=1)&&(x<=3))&&((y>=1)&&(y<=3)))
	     {
	            x--;
	            y--;
				if((chess[x][y]==' '))
				{
	            chess[x][y]='X';
	            break;
				}
				else 
	            {
		           printf("输入错误，请重新输入:");
	            }
		
	      }
	     else 
	      {
		  printf("输入错误，请重新输入:");
	      }
	}
}

void computer_move(char chess[ROWS][CLOS], int row,  int clo)
{
	while(1)
	{
	int x=rand()%3;
	int y=rand()%3;
	if (chess[x][y]==' ')
	{
	chess[x][y]='Y';
	break;
	}
	}
}

char check_win(char chess[ROWS][CLOS], int row,  int clo)
{
	int i=0;
	for(i=0;i<row;i++)
	{
	if((chess[i][0]==chess[i][1])&&
	   (chess[i][1]==chess[i][2])&&
	   (chess[i][0]!=' '))
	   return chess[i][0];
	}

	for(i=0;i<clo;i++)
	{
	if((chess[0][i]==chess[1][i])&&
	   (chess[1][i]==chess[2][i])&&
	   (chess[0][i]!=' '))
	   return chess[0][i];
	}

	if((chess[0][0]==chess[1][1])&&
	   (chess[1][1]==chess[2][2])&&
	   (chess[0][0]!=' '))
	   return chess[0][0];

    if((chess[0][2]==chess[1][1])&&
	   (chess[1][1]==chess[2][0])&&
	   (chess[0][2]!=' '))
	   return chess[0][2];

	if (is_full(chess, ROWS, CLOS))  return 'q';

	else return ' ';

}

int is_full(char chess[ROWS][CLOS], int row,  int clo)
{
    int i=0;
	int j=0;
	for (i=0;i<row;i++)
	{
		for (j=0;j<clo;j++)
		{
			if(chess[i][j]==' ')
				return 0;

		}
	}
	return 1;
}