#include <stdio.h>
#include <stdlib.h>
#include "liberrmsg.h"
char HMSG[]="\
%s read text from file[or standart input] and replace 'backspace' with 'backspace' for new alignment.\n\
\n\
TextAlign_b2b file -f<N> -t<N>\n\
\n\
Example:\n\
Input from file\n\
    TextAlign_b2b -f2 -t4 infile > out.file\n\
Wangsheng\n\
wangsheng.cas@gmail.com\n\
";

int main(int argc, char *argv[])
{
	int  nfile = 0;
	FILE *fpin = NULL;
	char *str_infile = NULL;

	int   b1 = 0, b2 = 0;
	int   I_b1 = 0, I_b2 = 0;

	char c;
	int  nbackspace = 0;
	int  newline = 0;
	for(int i = 1; i < argc; ++i)
	{
		if( argv[i][0] == '-' )
		{
			switch(argv[i][1])
			{
				case 'f':
					sscanf(argv[i], "-f%d", &b1);
					I_b1  = 1;
					break;
				case 't':
					sscanf(argv[i], "-t%d", &b2);
					I_b2  = 1;
					break;
			}
		}
		else
		{
			str_infile = argv[i];
			++nfile;
		}
	}
	if( I_b1 !=  1 || I_b2 != 1 )
	{
		//perrmsg("",ERR_MORE_ARGS);
		fprintf(stderr, HMSG, argv[0]);
		exit(1);
	}
	nbackspace = b2/b1;
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
			if( c == ' ' && newline == 0 )
			{
				for(int j = 0; j < nbackspace; ++j)
					putchar(' ');
			}
			else if( c == '\n')
			{
				putchar('\n');
				newline = 0;
			}
			else
			{
				putchar(c);
				newline = 1;
			}
		}
	}
	return 0;
}