#ifndef CONT__H_
#define CONT__H_

#include <stdio.h>
#include <string.h>

#define  MAX   1000


enum OP
{
	EXIT,
	ADD,
	DET,
	LOOKF,
	ALERT,
	SHOW,
	EMPTY


};

typedef struct Inform
{
	char name[10];
	int age;
	char sex[5];
	char tel[12];
	char addr[20];
}Inform;

typedef struct Contact
{
    Inform   data[MAX];
	int size;
}Contact,  *pContact;



void inti_con(pContact pcon );
void add_con(pContact pcon );
void det_con(pContact pcon );
void show_con(pContact pcon );
void lookf_con(pContact pcon );
void alert_con(pContact pcon);
void empty_con(pContact pcon);



#endif //CONT__H_