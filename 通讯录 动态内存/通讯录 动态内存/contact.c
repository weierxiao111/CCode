#define _CRT_SECURE_NO_DEPRECATE 
#include  "contact.h"
void inti_con(pContact pcon)
{
	pcon->size=0;
	memset(pcon->data, 0 , sizeof(struct Inform)*MAX);
}

void add_con(pContact  pcon)
{
	if ((pcon->size)>=MAX)
	{
		printf("你的电话本已满，无法储存\n");
		return ;
	}
	
	printf("请输入姓名： \n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("请输入年龄：  \n");
	scanf("%d",&(pcon->data[pcon->size].age));
	printf("请输入性别：   \n");
	scanf("%s",&(pcon->data[pcon->size].sex));
	printf("请输入电话：   \n");
    scanf("%s",&(pcon->data[pcon->size].tel));
    printf("请输入地址：    \n");
	scanf("%s",&(pcon->data[pcon->size].addr));
	printf("保存成功\n");
	(pcon->size)++;
}

void det_con(pContact pcon )
{
	char ret[10];
	int sz = 0;
	int i=0;
	printf("选择你要删除人的姓名\n");
	scanf("%s",ret);
	for (i=0; i<pcon->size; i++)
	{
		if( strcmp(ret ,pcon->data[i].name) == 0)
		{
			sz = i;
			break;
		}
		else if (i== pcon->size )
		{
			printf("你输入的信息不存在\n");
		}
	}

	for (i=sz; i< pcon->size-1; i++)
	{
		pcon->data[i] = pcon->data[i+1];
	}

	(pcon->size)--;

	printf("删除成功\n");
    	
}

void show_con(pContact pcon )
{
   int i=0;
   printf("%5s%5s%5s%5s%10s\n","name", "age","sex","tel","addr" );
   for (i=0; i<pcon->size; i++)
   {
	   printf("%5s%5d%5s%5s%10s\n",pcon->data[i].name, pcon->data[i].age,
		   pcon->data[i].sex, pcon->data[i].tel, pcon->data[i].addr);
   }
}

void lookf_con(pContact pcon )
{
	char ret[10];
	int sz = 0;
	int i=0;
	printf("请输入你要查看人的姓名\n");
	scanf("%s",ret);
	for (i=0; i<pcon->size; i++)
	{            
		if( strcmp(ret ,pcon->data[i].name) == 0)
		{
			sz = i;
			break;
		}

		else if (i== pcon->size )
		{
			printf("你输入的信息不存在\n");
		}
	}

	printf("%5s%5s%5s%5s%10s\n","name", "age","sex","tel","addr" );
	printf("%5s%5d%5s%5s%10s\n",pcon->data[sz].name, pcon->data[sz].age,
		    pcon->data[sz].sex, pcon->data[sz].tel, pcon->data[sz].addr);

}

void alert_con(pContact pcon)
{
	char ret[10]={0};
	int sz = 0;
	int i=0;
	printf("请输入你要修改人的姓名\n");
	scanf("%s",ret);
	for (i=0; i<pcon->size; i++)
	{            
		if( strcmp(ret ,pcon->data[i].name) == 0)
		{
			sz = i;
			break;
		}

		else if (i== pcon->size )
		{
			printf("你输入的信息不存在\n");
		}
	}

	printf("请重新输入姓名： \n");
	scanf("%s", pcon->data[sz].name);
	printf("请重新输入年龄：  \n");
	scanf("%d",&(pcon->data[sz].age));
	printf("请重新输入性别：   \n");
	scanf("%s",&(pcon->data[sz].sex));
	printf("请重新输入电话：   \n");
    scanf("%s",&(pcon->data[sz].tel));
    printf("请重新输入地址：    \n");
	scanf("%s",&(pcon->data[sz].addr));
	printf("保存成功\n");

}

void empty_con(pContact pcon)
{
	
	char ch;
	printf("你确定要全部删除吗!\n");
	printf("确定删除：  Y  其他键返回 \n");
	scanf("%c",&ch);
	if ((ch=='y') || (ch=='Y'))
	{
	pcon->size=0;
	memset(pcon->data, 0 , sizeof(struct Inform)*MAX);
	printf("全部清空\n");
	}
	
}
