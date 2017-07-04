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
  #include "tosend.h"
 #define MAXLINE 1024
  
int main()
{
  while (1)
  {
char sendline[MAXLINE];
    give(sendline);
    tosend(sendline , 10004);
  }
}
