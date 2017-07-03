#ifndef NEWSERVERSFUNC__H
#define NEWSERVERSFUNC__H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "itoa.h"
#include "savecomment.h"

#define MAXLINE 1024
#define TotalWindows 16


////////////////////////////////////////////////////////////////////////////////
bool Windowsavailable[TotalWindows] = {0};//窗口为空时为false,窗口已经有客户时为true
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/*此处为排队队列的结点i及其具体操作*/
struct BankQueue
{
  int num;
  struct BankQueue* next;
};

struct BankQueue *head = NULL , *last = NULL;
//记录总人数及总vip数 , 总人数不会进行减法操作 , 而总vip数与nowpeople会,为0无vip.
int totalpeople = 0;
int totalvip = 0;

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
void push_back();
void push_top();
int pop();
int getlength();
void Inform(int i);
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
////////////////////////////////////////////////////////////////////////////////


void  GetNumber(const char* samp)
{
  samp += 3;
  if (atoi(samp) == 11)//判断是否是vip
  {
    push_top();
  }
  else
  {
    push_back();
  }

//向取票端发送序号
  char* servInetAddr = "127.0.0.1";
  int socketfd;
  struct sockaddr_in sockaddr_send;
  char  sendline[MAXLINE];
  //printf("send message to server\n");
  int remain = getlength() - 1;
  sprintf(sendline , "%d.%d" , totalpeople , remain);
  socketfd = socket(AF_INET , SOCK_STREAM , 0);
  memset(&sockaddr_send , 0 , sizeof(sockaddr_send));
  sockaddr_send.sin_family = AF_INET;
  sockaddr_send.sin_port = htons(10005);
  inet_pton(AF_INET , servInetAddr , &sockaddr_send.sin_addr);

  if ((connect(socketfd , (struct sockaddr*)&sockaddr_send , sizeof(sockaddr_send))) < 0 )
  {
    printf("connect error%s errno: %d\n",strerror(errno) , errno);
    exit(0);
  }

  if((send(socketfd,sendline,strlen(sendline),0)) < 0)
  {
  printf("send mes error: %s errno : %d",strerror(errno),errno);
  exit(0);
  }
  close(socketfd);

}

//得到评论并将其写入文件,同时更新可用窗口.
void GetComment(const char* samp)
{
  samp += 3;
  int winnum = atoi(samp);
  samp += 3;
  int rank = atoi(samp);
  Windowsavailable[winnum - 1] = false;
  modify(winnum , rank);
}

//对队列和窗口进行分配
void ArrangeQueue()
{
  if (isempty())
  return;
  for (int i = 0 ; i < TotalWindows ; i++)
  {
    if (!Windowsavailable[i])
    {
      Inform(i);
      if (pop())
      Windowsavailable[i] = true;
    }
  }
}

//得到从客户端发来的消息,由于使用了同一个接受端口,为了判断是哪里来的信息并进行相应处理使用该函数.
void ChoseFunction(const char* samp)
{
  int tar = atoi(samp);//读第一个整数,判断是来自取号端还是来自窗口端.
  switch (tar)
  {
    //为取票端时 **要返回序号和前方队列人数.
    case 10 : GetNumber(samp);break;
    //为窗口端时 **要将窗口激活,将评论写入文件,一个窗口对应一个文件,(可能用二进制读写会i比较好?)
    case 20 : GetComment(samp);break;
  }
  ArrangeQueue();
}
#endif
