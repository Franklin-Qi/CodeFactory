/*  Copyright (C++) 2018 * Ltd. All rights reserved.
*      Create date : 2018-08-29 07:57:40
*================================================*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#define MAXLINE 4096

int main()
{
    int listenfd,connfd;
    char ip[30]={0};
    socklen_t  clilen;
    struct sockaddr_in cliaddr,servaddr;
    listenfd=socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;

    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(8888);

    bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));  

    listen(listenfd,5);
    clilen=sizeof(cliaddr);

    connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
    connfd=accept(listenfd,(struct sockaddr *)NULL,NULL);
    getpeername(connfd,(struct sockaddr *)&cliaddr,&clilen);
    inet_ntop(AF_INET,&cliaddr.sin_addr,ip,sizeof(ip));
    printf("%s,%d",ip,ntohs(cliaddr.sin_port));
    getchar();
    getchar();
    close(listenfd);
    return 0;

}



