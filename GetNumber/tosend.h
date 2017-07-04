#ifndef TOSEND__H
#define TOSEND__H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAXLINE 1024
int tosend(char sendline[] , int port)
{
  char* servInetAddr = "127.0.0.1";
  int socketfd;
  struct sockaddr_in sockaddr_send;
  socketfd = socket(AF_INET , SOCK_STREAM , 0);
  memset(&sockaddr_send , 0 , sizeof(sockaddr_send));
  sockaddr_send.sin_family = AF_INET;
  sockaddr_send.sin_port = htons(port);
  inet_pton(AF_INET , servInetAddr , &sockaddr_send.sin_addr);
  if ((connect(socketfd , (struct sockaddr*)&sockaddr_send , sizeof(sockaddr_send))) < 0 )
  {
    printf("connect error%s errno: %d\n",strerror(errno) , errno);
    return 0;
  }

  if((send(socketfd,sendline,strlen(sendline),0)) < 0)
  {
  printf("send mes error: %s errno : %d",strerror(errno),errno);
  return 0;
  }
  close(socketfd);
  return 1;
}
#endif
