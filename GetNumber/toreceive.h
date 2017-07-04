#ifndef TORECEIVE__H
#define TORECEIVE__H
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
//
int initiateforreceive(int port)
{
  char* servInetAddr = "127.0.0.1";
  int listenfd;
  struct sockaddr_in sockaddr_get;
  memset(&sockaddr_get , 0 , sizeof(sockaddr_get));
  sockaddr_get.sin_family = AF_INET;
  sockaddr_get.sin_addr.s_addr = htonl(INADDR_ANY);
  sockaddr_get.sin_port = htons(port);
  listenfd = socket(AF_INET , SOCK_STREAM , 0);
  bind(listenfd,(struct sockaddr *) &sockaddr_get,sizeof(sockaddr_get));
  listen(listenfd,1024);
  return listenfd;
}
int toreceive(char buff[] , int listenfd)
{
  int connfd;
  if((connfd = accept(listenfd,(struct sockaddr*)NULL,NULL))==-1)
  {
  printf("accpet socket error: %s errno :%d\n",strerror(errno),errno);
  return 0;
  }
  int n;
  n = recv(connfd,buff,MAXLINE,0);
  buff[n] = '\0';
  close(connfd);
  return 1;
}
#endif
