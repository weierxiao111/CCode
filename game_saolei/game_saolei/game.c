#include "game.h"

int get_random_num(int m, int n)
{
	return rand()%(n-m+1)+m;
}

void init_mine ( char mine[ROWS+2][CLOS+2], int row ,int clo)
{
	
	int count=mine_number;
	while(count)
	{
		int x=get_random_num(1,10);
		int y=get_random_num(1,10);
		if (mine[x][y]=='0')
		{
			mine[x][y]='1';
			count--;
		}
	}
}

void display(char board[ROWS+2][CLOS+2],int row,int clo)
{
	int i=0;
	int j=0;
	printf("    ");
	for (i=1;i<row-1;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i=1;i<row-3;i++)
	{
		printf("__ ");
	}
	printf("\n");

	for (i=1;i<row-1;i++)
	{
		  printf("%2d |",i);
          for (j=1;j<row-1;j++)
	{
       
         printf("%c ",board[i][j]);
	}
		  printf("\n");
	}
}

int set_mine(char mine[ROWS+2][CLOS+2], int x, int y)
{
	return ((mine[x-1][y-1]-'0')+
		    (mine[x-1][y]-'0')+
			(mine[x-1][y+1]-'0')+
			(mine[x][y-1]-'0')+
			(mine[x][y+1]-'0')+
			(mine[x+1][y-1]-'0')+
			(mine[x+1][y]-'0')+
			(mine[x+1][y+1]-'0'));
}