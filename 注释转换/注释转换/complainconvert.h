#ifndef  __COMPLAIN_CONERT_H_
#define  __COMPLAIN_CONERT_H_

#include <stdio.h>
#include <stdlib.h>
#define filename1    "input.c"
#define filename2    "ouput.c"

static enum State
{
	NULL_STATE ,
	C_STATE,
	CPP_STATE,
	END_STATE
};

void  DoConvertWork(FILE* pint , FILE* pout);
void  DoCWork(FILE* pint , FILE* pout);
void DoCppWork(FILE *pfint, FILE *pfout);
void  DoNullWork(FILE* pint , FILE* pout);

#endif  // __COMPLAIN_CONERT_H_
