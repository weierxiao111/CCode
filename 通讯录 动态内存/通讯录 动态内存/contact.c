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
		printf("��ĵ绰���������޷�����\n");
		return ;
	}
	
	printf("������������ \n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("���������䣺  \n");
	scanf("%d",&(pcon->data[pcon->size].age));
	printf("�������Ա�   \n");
	scanf("%s",&(pcon->data[pcon->size].sex));
	printf("������绰��   \n");
    scanf("%s",&(pcon->data[pcon->size].tel));
    printf("�������ַ��    \n");
	scanf("%s",&(pcon->data[pcon->size].addr));
	printf("����ɹ�\n");
	(pcon->size)++;
}

void det_con(pContact pcon )
{
	char ret[10];
	int sz = 0;
	int i=0;
	printf("ѡ����Ҫɾ���˵�����\n");
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
			printf("���������Ϣ������\n");
		}
	}

	for (i=sz; i< pcon->size-1; i++)
	{
		pcon->data[i] = pcon->data[i+1];
	}

	(pcon->size)--;

	printf("ɾ���ɹ�\n");
    	
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
	printf("��������Ҫ�鿴�˵�����\n");
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
			printf("���������Ϣ������\n");
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
	printf("��������Ҫ�޸��˵�����\n");
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
			printf("���������Ϣ������\n");
		}
	}

	printf("���������������� \n");
	scanf("%s", pcon->data[sz].name);
	printf("�������������䣺  \n");
	scanf("%d",&(pcon->data[sz].age));
	printf("�����������Ա�   \n");
	scanf("%s",&(pcon->data[sz].sex));
	printf("����������绰��   \n");
    scanf("%s",&(pcon->data[sz].tel));
    printf("�����������ַ��    \n");
	scanf("%s",&(pcon->data[sz].addr));
	printf("����ɹ�\n");

}

void empty_con(pContact pcon)
{
	
	char ch;
	printf("��ȷ��Ҫȫ��ɾ����!\n");
	printf("ȷ��ɾ����  Y  ���������� \n");
	scanf("%c",&ch);
	if ((ch=='y') || (ch=='Y'))
	{
	pcon->size=0;
	memset(pcon->data, 0 , sizeof(struct Inform)*MAX);
	printf("ȫ�����\n");
	}
	
}
