#ifndef vip__h
#define vip__h
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int vip(char sendline[])
{
	int b;
	printf("是否为vip(是vip请按1 , 不是请按2)\n");
    scanf("%d",&b);
    if(b == 1)
	{
		sprintf(sendline , "10.11.00\0");
		return 1;      //是vip
	}
	else if(b == 2)
	{
		sprintf(sendline , "10.00.00\0");
		return 2;     //不是vip
	}
}

void print(const char buff[] , int isvp)
{
	int num = atoi(buff);
	char str[100];
	sprintf(str , "%d\0" , num);
	int len = strlen(str);
	buff += (len + 1);
	int remain = atoi(buff);
if(isvp == 1)
   printf("客户您的号码为A%d,前方约有%d人,请耐心等待\n" , num , totalvip - 1);
else if(isvp == 2)
  printf("客户您的号码为B%d,前方约有%d人,请耐心等待\n" , num , remain);
}
#endif
