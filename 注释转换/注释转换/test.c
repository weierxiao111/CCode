#include <stdio.h>
#include <stdlib.h>
#include "complainconvert.h"



int main()
{
	FILE* pRead = fopen(filename1, "r");
	FILE* pWrite = fopen(filename2, "w");
	if (pRead == NULL)
	{
		printf("read is fail!!!\n");
		exit(1);
	}
	if (pWrite == NULL)
	{
		printf("write is fail!!!\n");
		exit(1);
	}
	DoConvertWork(pRead, pWrite);

	fclose (pRead);
	fclose (pWrite);
	return 0;
}