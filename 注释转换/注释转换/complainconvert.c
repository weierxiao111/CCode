#include "complainconvert.h"

static enum State state = NULL_STATE;

void  DoConvertWork(FILE* pfint , FILE* pfout)
{
    while ( state != END_STATE) 
	{
		switch (state)
		{
		case  NULL_STATE:
			DoNullWork(pfint, pfout);
			break;
		case  C_STATE:
			DoCWork(pfint, pfout);
			break;
		case  CPP_STATE:
			DoCppWork(pfint, pfout);
			break;
		default:
			break;
		}
	}
}

void DoCWork(FILE *pfint, FILE *pfout)
{
    char first = 0;
    char second = 0;
    char third = 0;
    first = fgetc(pfint);
    switch (first)
    {
    case'*':
        second = fgetc(pfint);
        switch (second)
        {
        case'/':
            third = fgetc(pfint);
            if (third != '\n')
                fputc('\n',  pfout);
            if (third == '/')
            {
                ungetc(third, pfint);
                state = NULL_STATE;
                break;
            }
            fputc(third,  pfout);
            state = NULL_STATE;
            break;
        case'*':
            third = fgetc(pfint);
            fputc(first,  pfout);
            if (third == '/')
            {
                state = NULL_STATE;
                fputc('\n',  pfout);
                break;
            }
            ungetc(second,  pfint);
            ungetc(third, pfint);
            break;
        default:
            fputc(first, pfout);
            fputc(second,  pfout);
            break;

        }
        break;

    case'\n':
        fputc(first,  pfout);
        fputc('/',  pfout);
        fputc('/', pfout);
        break;
    case EOF:
        state = END_STATE;
        break;
    default:

        fputc(first,  pfout);
        break;

    }

}

void DoNullWork(FILE* pfint,FILE* pfout)
{
	int first =0;
	int second =0;
	first = fgetc(pfint);
	switch (first)
	{
	case '/':
		second = fgetc(pfint);
		if (second == '*')
		{
			fputc('/',pfout);
			fputc('/',pfout);
			state = C_STATE;
		}
		else if(second == '/')
		{
			fputc('/',pfout);
			fputc('/',pfout);
			state = CPP_STATE;
		}
		else
		{
			fputc(first,pfout);
			fputc(second,pfout);
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first,pfout);
		break;
	}
}

void DoCppWork(FILE *pfint, FILE *pfout)
{
    char first = 0;
    first = fgetc(pfint);
    switch (first)
    {
    case '\n':
        fputc(first,pfint);
        state = NULL_STATE;
        break;
    case EOF:
        state = END_STATE;
        break;
    default:
        fputc(first, pfint);
        break;
    }
}
