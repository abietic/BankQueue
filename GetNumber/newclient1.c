  #include <stdio.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <unistd.h>
 #include <arpa/inet.h>
 #include "vip.h"
#include "tosend.h"
#include "toreceive.h"

 #define MAXLINE 1024
char buff[MAXLINE] , sendline[MAXLINE];
int main()
{
  int listenfd = initiateforreceive(10005);
  while (1)
  {
    int isvp = vip(sendline);
    tosend(sendline , 10004);
    if(toreceive(buff , listenfd) == 0)
    	continue;
    print(buff , isvp);
  }
  close(listenfd);
}
