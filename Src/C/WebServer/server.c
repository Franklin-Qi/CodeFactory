/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-30 07:23:35
 *================================================*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXBUFFSIZE 1024
int main(int argc, char *argv[])
{
    int fd, new_fd, numbytes;
    struct sockaddr_in server_addr, client_addr;//服务器绑定的地址, 客户端地址

    char buff[MAXBUFFSIZE];
    socklen_t struct_len;//防止警告

    bzero(&(server_addr.sin_zero), 8);/* sin_zero 初始值应该使用函数 bzero() 来全部置零。*/
    server_addr.sin_family = AF_INET;/* Internet地址族 */
    server_addr.sin_port = htons(8000);/*端口号，将主机字节顺序转换为网络字节顺序*/
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);/* IP地址 */

    struct_len = sizeof(struct sockaddr_in);

    /*创立套接字，使用TCP协议*/
    fd = socket(AF_INET, SOCK_STREAM, 0);//初始化socket
    if(fd == -1) {
        perror("socket"); //检查是否正常初始化socket
        return 1;
    }

    /*将地址和套节字绑定*/
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1);
    printf("Bind Success!\n");

    /*开始监听连接请求*/
    //while(listen(fd, 10) == -1);
    if(listen(fd, 5) == -1)        //监听
    {
        perror("listen");
        return 1;
    }
    printf("监听中....\n");
    printf("等待客户端连接。。。。\n\n");


    /*
    struct sockaddr_in listendAddr, connectedAddr, peerAddr;//分别表示连接的本地地址，连接的对端地址
    listendAddrLen = sizeof(listendAddr);
    getsockname(fd, (struct sockaddr *)&listendAddr, &listendAddrLen);//获取监听的地址和端口
    printf("listen address = %s:%d\n", inet_ntoa(listendAddr.sin_addr), ntohs(listendAddr.sin_port));
    */

    /*接受连接请求，从此函数中返回后就可以开始通信了*/

    new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
    printf("成功接收到一个客户端：%s\n", inet_ntoa(client_addr.sin_addr));

    /*
    int listendAddrLen, connectedAddrLen, peerLen;
    char ipAddr[INET_ADDRSTRLEN];//保存点分十进制的地址

    connectedAddrLen = sizeof(connectedAddr);
    getsockname(new_fd, (struct sockaddr *)&connectedAddr, &connectedAddrLen);//获取connfd表示的连接上的本地地址
    printf("connected server address = %s:%d\n", inet_ntoa(connectedAddr.sin_addr), ntohs(connectedAddr.sin_port));
    getpeername(new_fd, (struct sockaddr *)&peerAddr, &peerLen); //获取connfd表示的连接上的对端地址
    printf("connected peer address = %s:%d\n", inet_ntop(AF_INET, &peerAddr.sin_addr, ipAddr, sizeof(ipAddr)), ntohs(peerAddr.sin_port));
    */



    /*使用send函数将转换后的字符串发送给客户端，不设置任何特殊的标志*/
    printf("发送信息到客户端\n");
    numbytes = send(new_fd,"Welcome to my server\n",21,0); 

    /*调用recv函数读取客户端传来的信息，不设置任何特殊的标志*/
    while((numbytes = recv(new_fd, buff, MAXBUFFSIZE, 0)) > 0)
    {
        buff[numbytes] = '\0';
        printf("%s\n",buff);
        if(send(new_fd,buff,numbytes,0)<0)  
        {  
            perror("write");  
            return 1;  
        }  
    }
    close(new_fd);
    close(fd);
    return 0;
}
