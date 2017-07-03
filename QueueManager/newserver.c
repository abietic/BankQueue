#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "newserversfunc.h"
#include "savecomment.h"

#define MAXLINE 1024




int main()
{
 char* servInetAddr = "127.0.0.1";
 int listenfd , connfd , socketfd;
 struct sockaddr_in sockaddr_get , sockaddr_send;
 char buff[MAXLINE] , sendline[MAXLINE] , recvline[MAXLINE];
 int n;
 Creatqueue();
 inited();
 while (1)
 {
   //printf("hallo\n" );
   memset(&sockaddr_get , 0 , sizeof(sockaddr_get));
   sockaddr_get.sin_family = AF_INET;
   sockaddr_get.sin_addr.s_addr = htonl(INADDR_ANY);
   sockaddr_get.sin_port = htons(10004);
   listenfd = socket(AF_INET , SOCK_STREAM , 0);

   bind(listenfd,(struct sockaddr *) &sockaddr_get,sizeof(sockaddr_get));
   listen(listenfd,1024);
   printf("");///////
   if((connfd = accept(listenfd,(struct sockaddr*)NULL,NULL))==-1)
   {
   printf("accpet socket error: %s errno :%d\n",strerror(errno),errno);
   continue;
   }
   n = recv(connfd,buff,MAXLINE,0);
   buff[n] = '\0';

   //printf("recv msg from client:%s",buff);

   close(connfd);
   close(listenfd);

   ChoseFunction(buff);
   printf("");//////
   /*printf("send message to server\n");

   fgets(sendline , 1024 , stdin);

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
   close(socketfd);*/
 }
}
