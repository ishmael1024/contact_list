#include "bsp/bsp_wait_enter.h"
#include <stdio.h>


void wait_enter()
{
    int ch;

    printf("please prsee 'enter' to return\n");
    while( (ch = getchar()) != '\n' && ch != EOF );
}