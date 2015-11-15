#include <stdio.h>
#include <stdlib.h>
#include "liberrmsg.h"
char HMSG[]="\
%s read text from file[or standart input] and replace 'tab' with 'backspace' for alignment.\n\
\n\
TextAlign_t2b file -t<N>\n\
\n\
Example:\n\
Input from file\n\
    TextAlign_t2b -t4 infile > out.file\n\
Wangsheng\n\
wangsheng.cas@gmail.com\n\
";

int main(int argc, char *argv[])
{
	int  nfile = 0;
	FILE *fpin = NULL;
	char *str_infile = NULL;
	char *str_format = NULL;
	int   I_formate = 0;

	char c;
	int  pos = 0;
	int  ntab = 4, nbackspace = 4;
	for(int i = 1; i < argc; ++i)
	{
		if( argv[i][0] == '-' )
		{
			switch(argv[i][1])
			{
				case 't':
					str_format = &(argv[i][2]);
					sscanf(str_format, "%d", &ntab);
					I_formate  = 1;
					break;
			}
		}
		else
		{
			str_infile = argv[i];
			++nfile;
		}
	}
	if( I_formate !=  1 )
	{
		//perrmsg("",ERR_MORE_ARGS);
		fprintf(stderr, HMSG, argv[0]);
		exit(1);
	}
	if(nfile == 0)
	{
		fpin = stdin;
	}
	else if(nfile == 1)
	{
		if( (fpin = fopen(str_infile, "r")) == NULL )
		{
			perrmsg(str_infile, ERR_OPEN_FILE);
			exit(1);
		}
	}
	else
	{
		perrmsg("One input file limited!", ERR_BAD_ARGS);
		exit(1);
	}

	for(;;)
	{
		if( ( c = fgetc(fpin) ) == EOF )
			break;
		else
		{
			if( c == '\t')
			{
				nbackspace = ntab - ( pos%ntab );
				for(int j = 0; j < nbackspace; ++j)
					putchar(' ');
			}
			else if( c == '\n')
			{
				putchar('\n');
				pos = 0;
			}
			else
			{
				putchar(c);
				++pos;
			}
		}
	}
	return 0;
}