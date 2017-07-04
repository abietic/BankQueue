#ifndef NEWSERVERSFUNC__H
#define NEWSERVERSFUNC__H

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
#include "bankqueue.h"

#define MAXLINE 1024
#define TotalWindows 16

////////////////////////////////////////////////////////////////////////////////
bool Windowsavailable[TotalWindows] = {0};//窗口为空时为false,窗口已经有客户时为true
////////////////////////////////////////////////////////////////////////////////

//添加排队人数并返回号码
void  GetNumber(const char* samp);

//得到评论并将其写入文件,同时更新可用窗口.
void GetComment(const char* samp);

//对队列和窗口进行分配
void ArrangeQueue();

//==============================================================================
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
//==============================================================================

void  GetNumber(const char* samp)
{
  char sendline[MAXLINE];
  samp += 3;
  if (atoi(samp) == 11)//判断是否是vip
  {
    push_top();
    sprintf(sendline , "%d.%d" , totalpeople , totalvip - 1);
  }
  else
  {
    push_back();
    int remain = getlength() - 1;
    sprintf(sendline , "%d.%d" , totalpeople , remain);
  }
//向取票端发送序号
 tosend(sendline , 10005);
}

void GetComment(const char* samp)
{
  samp += 3;
  int winnum = atoi(samp);
  samp += 3;
  int rank = atoi(samp);
  Windowsavailable[winnum - 1] = false;
  modify(winnum , rank);
}

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
#endif
