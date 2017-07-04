#ifndef BANKQUEUE__H
#define BANKQUEUE__H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "toreceive.h"
#include "itoa.h"
#include "savecomment.h"
#include <stdbool.h>
#include "tosend.h"
#define MAXLINE 1024
#define TotalWindows 16
////////////////////////////////////////////////////////////////////////////////

//本排队队列为双端队列普通客户尾插,vip客户头插.有哨兵节点

//记录总人数及总vip数 , 总人数不会进行减法操作 , 而总vip数与nowpeople会,为0无vip.
int totalpeople = 0;
int totalvip = 0;

/*此处为排队队列的结点i及其具体操作*/
struct BankQueue
{
  int num;
  struct BankQueue* next;
};

struct BankQueue *head = NULL , *last = NULL;

void Creatqueue();//初始化队列
int isempty();//判断队列是否为空
void push_back();//尾插
void push_top();//头插
int pop();//头结点弹出
int getlength();//得到队列长度
void Inform(int i);//对客户进行通知
////////////////////////////////////////////////////////////////////////////////

int getlength()
{
  if (head == last)
  return 0;
  int i;
  struct BankQueue *temp , *prev;
  for (i = 1 , temp = head -> next
      ; temp -> next != NULL
      ; temp = temp -> next , i++);
  return i;
}

void Inform(int i)
{
  i++;
  if (isempty())
  return;
  if (totalvip)
  printf("请A%d号客户到%d号窗口办理.\n",head -> next -> num , i);
  else
  printf("请B%d号客户到%d号窗口办理.\n",head -> next -> num , i);
}

int pop()
{
  if (isempty())
  return 0;
  struct BankQueue *temp = head -> next;
  head -> next = temp ->next;
  if (temp == last)
  last = head;
  free(temp);
  if (totalvip)
  {
    totalvip--;
  }
  return 1;
}

void push_back()
{
  last -> next = (struct BankQueue*)malloc(sizeof(struct BankQueue));
  last = last -> next;
  last -> num = ++totalpeople;
  last -> next = NULL;
}

void push_top()
{
  struct BankQueue *temp = head;
  if (totalvip)
  {
    for (int i = 0 ; i < totalvip ; i++ , temp = temp -> next);
  }
  struct BankQueue *tempn = temp -> next;
  temp -> next = (struct BankQueue*)malloc(sizeof(struct BankQueue));
  if (temp == last)
  {
    last = temp -> next;
  }
  temp = temp -> next;
  temp -> next = tempn;
  temp -> num = ++totalpeople;
  totalvip++;
}

void Creatqueue()
{
  if (!head)
  head = (struct BankQueue*)malloc(sizeof(struct BankQueue));
  last = head;
}

int isempty()
{
  if (head == last)
  return 1;
  return 0;
}
////////////////////////////////////////////////////////////////////////////////

#endif
