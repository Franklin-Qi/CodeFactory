/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-30 07:24:06
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFFSIZE 1024
/* 利用socket的TCP client
 * 此程序会连线TCP server，并将键盘输入的字符串传送给server。
 */

int main(int argc,char *argv[])
{
    int sockfd,numbytes;
    char buf[MAXBUFFSIZE];
    struct sockaddr_in their_addr;
    printf("break!");

    /* 创立套接字，使用TCP协议 */
    while((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1);
    printf("创建socket套接字\n");

    /* 填写sockaddr_in结构*/
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(8000);
    their_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bzero(&(their_addr.sin_zero), 8);
    
    /* 客户端进行连接服务器端 */
    printf("尝试连接到服务器端...\n");
    if(connect(sockfd,(struct sockaddr*)&their_addr,sizeof(struct sockaddr) ) < 0) {
        perror("Connect to server failed !");
        return 1;
    }
    printf("成功连接到服务器端!\n");



    /*
    struct sockaddr_in clientAddr;//客户端地址
    int clientAddrLen = sizeof(clientAddr);
    char ipAddress[INET_ADDRSTRLEN];//保存点分十进制的ip地址

    getsockname(sockfd, (struct sockaddr*)&clientAddr, &clientAddrLen);//获取sockfd表示的连接上的本地地址
    printf("client:client address = %s:%d\n", inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress)), ntohs(clientAddr.sin_port));
    */


    /* 接收由server端传来的信息*/
    printf("开始接收服务器端传输的数据：\n");
    numbytes = recv(sockfd, buf, MAXBUFFSIZE,0);
    buf[numbytes]='\0';  
    printf("%s\n",buf);

    while(1)
    {
        /*
        printf("Please enter something:");
        scanf("%s",buf);
        */
        bzero(buf,sizeof(buf));
        /* 从标准输入设备取得字符串*/
        read(STDIN_FILENO,buf,sizeof(buf));

        /* 发送数据 */
        numbytes = send(sockfd, buf, strlen(buf), 0);

        /* 接收数据 */
        numbytes=recv(sockfd,buf,MAXBUFFSIZE,0);  
        buf[numbytes]='\0'; 
        printf("received:%s\n",buf);  

        if(numbytes == 0) break;
    }

    close(sockfd);
    return 0;
}
