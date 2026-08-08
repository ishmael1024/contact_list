#ifndef CONSOLE_IO_H_
#define CONSOLE_IO_H

#define success 0
#define error   -1
#define excess  -2

int readline(char *str, int size);
void wait_enter();

#endif

