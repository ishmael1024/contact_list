#include "console/console_io.h"
#include <stdio.h>
#include <string.h>


int readline(char *str, int size)
{
	size_t str_len;
	int ch;

	if( fgets(str, size, stdin) == NULL )
		return error;

	str_len = strlen(str);
		if( str[str_len-1] == '\n' )
		{
			str[str_len-1] = '\0';
			return success;
		}	
		else
		{
			while( (ch = getchar()) != '\n'&& ch !=EOF );
			return excess;
		}
}


void wait_enter()
{
	int ch;

	printf("please prsee 'enter' to return\n");
	while( (ch = getchar()) != '\n' && ch != EOF );
}