#define _CRT_SECURE_NO_DEPRECATE 
#include  <stdio.h>
#include  <string.h>
#include  "contact.h"


void meum()
{
	printf("******************************************\n");
	printf("******************************************\n");
	printf("************   1.  ADD       *************\n");
	printf("************   2.  DET       *************\n");
	printf("************   3.  LOOKF     *************\n");
	printf("************   4.  ALERT     *************\n");
	printf("************   5.  SHOW      *************\n");
	printf("************   6.  EMPTY     *************\n");
	printf("************   0.  EXIT      *************\n");
	printf("******************************************\n");
}

int main()
{
	int input =0;
	Contact my_contact ;
	inti_con (&my_contact );
	do 
	{
		meum();
		printf("请选择： \n");
		scanf("%d",&input);
		if((input>=0) && (input<=6))
		{
		switch(input)
		{
		case  ADD: 
			add_con(&my_contact);
			break;
		case  DET:
			det_con(&my_contact);
			break;
		case  SHOW:
			show_con(&my_contact);
			break;
		case LOOKF:
			lookf_con(&my_contact);
			break;
	    case ALERT:
			alert_con(&my_contact);
			break;
		case EMPTY:
			empty_con(&my_contact);
			break;
		default:
			break;
		}
		}
		else
		{
			printf("选择错误，请重新选择\n");
		}

	}while(input);
	return 0;
}
