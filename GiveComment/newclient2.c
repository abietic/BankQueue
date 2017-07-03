 #include <stdio.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <unistd.h>
 #include <arpa/inet.h>
 #include "givecom.h"

 #define MAXLINE 1024
int main()
{
  char* servInetAddr = "127.0.0.1";
  int listenfd , connfd , socketfd;
  struct sockaddr_in sockaddr_get , sockaddr_send;
  char buff[MAXLINE] , sendline[MAXLINE] , recvline[MAXLINE];
  int n;

  while (1)
  {
/**************************************************************
*
*
*在此处编写代码完成对X好窗口的评价,分为1~5星,写在sendline里."20.xx.xx"第一个xx为窗口号第二个为评级.
*
*
**************************************************************/
    //printf("Had sent commont to server\n");

    give(sendline);

    socketfd = socket(AF_INET , SOCK_STREAM , 0);
    memset(&sockaddr_send , 0 , sizeof(sockaddr_send));
    sockaddr_send.sin_family = AF_INET;
    sockaddr_send.sin_port = htons(10004);
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
}
