#include <stdio.h>
#include <stdlib.h>
#include "liberrmsg.h"
char HMSG[]="\
%s read text from file and convert them into real ASCII char.\n\
\n\
TextRealChar [file1] [file2] ...\n\
\n\
Wangsheng\n\
wangsheng.cas@gmail.com\n\
";

int realChar(FILE *fpin);
int main(int argc, char *argv[])
{
	FILE *fpin = NULL;
	if( argc == 1 )
	{
		printf( HMSG, argv[0] );
		return 0;
	}
	else
	{
		for(int i = 1; i < argc; ++i)
		{
			if(argc > 2)
			{
				printf("\n---%03d---%s---\n", i, argv[i]);
			}
			if( (fpin = fopen(argv[i], "r")) == NULL )
			{
				perrmsg(argv[i], ERR_OPEN_FILE);
				exit(1);
			}
			realChar(fpin);
			fclose(fpin);
		}
	}

	return 0;
}



int realChar(FILE *fpin)
{
	char c;
	for(;;)
	{
		if( ( c = fgetc(fpin) ) == EOF )
			break;
		else
		{
			if( c >= 32 && c <= 127 )
				putchar(c);
			else
			{
				printf("\\X%02X",c);
			}
			if( c == '\n')
				putchar('\n');
		}
	}
	return 0;
}