#include "bsp/bsp_wait_enter.h"
#include <stdio.h>


void wait_enter()
{
    int ch;

    while(ch = getchar() != '\n' && ch != EOF);
}