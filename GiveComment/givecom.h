#ifndef givecom__h
#define givecom__h
#include<stdio.h>
#include<stdlib.h>
void give(char sendline[])
{
  int a,b,i;
  printf("请输入窗口号\n");
  scanf("%d",&b); //输入窗口号
  printf("请为该窗口评级:\n");
  scanf("%d",&a);
  sendline[0]='2';
  sendline[1]='0';
  sendline[2]='.';
  sendline[3]= '0' + b/10;
  sendline[4]=  '0' + b%10;
  sendline[5]='.';
  sendline[6]='0'+a/10;
  sendline[7]='0'+a%10;
  sendline[8]='\0';
}
#endif
