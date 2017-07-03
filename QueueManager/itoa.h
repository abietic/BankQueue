#ifndef ITOA__H
#define ITOA__H
#include <stdlib.h>
#include <stdio.h>
void itoa(int num , char* tar)
{
sprintf(tar , "%d\0" , num);
}
#endif
