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
#include "toreceive.h"

#define MAXLINE 1024




int main()
{

char buff[MAXLINE];
 Creatqueue();
 inited();
 int listenfd = initiateforreceive(10004);
 while (1)
 {
   if (toreceive(buff , listenfd) == 0)
   continue;
   ChoseFunction(buff);
 }
 close(listenfd);
}
