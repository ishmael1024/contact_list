#include "bsp/bsp_readline.h"
#include <stdio.h>
#include <string.h>


int readline(char *str, int size)
{
    size_t str_len;
    int ch;

    if( fgets(str, size, stdin) == NULL )
        return -1;

    str_len = strlen(str);
        if( str[str_len-1] == '\n' )
                str[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );

    return 0;
    
}