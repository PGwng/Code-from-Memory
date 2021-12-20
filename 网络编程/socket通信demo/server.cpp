/* ************************************************************************
> File Name:     server.cpp
> Author:        wang
> Created Time:  Thu Dec  9 15:59:05 2021
> Description:   
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char*argv[]){
    if(argc != 2){
        printf("using:./server port\nExample:./server 5005\n\n");
        return -1;
    }
    //第一步：创建服务端socket。
    int listenfd;
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket"); return -1;
    }
    //设置SO_REUSEADDR选项 //防止释放端口后短暂（2分钟）的TIME_WAIT状态
    int opt = 1;
    unsigned int len = sizeof(opt);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, len);

    //第二步：把服务端用于通信的地址和端口绑定到socket上。
    struct sockaddr_in servaddr;    //服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;  //协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   //任意ip地址
    //servaddr.sin_addr.s_addr = inet_addr("10.23.22.210"); //指定ip地址 
    //inet_addr方法只能解析ip地址 无法解析域名，用hostent结构体可解析二者
    servaddr.sin_port = htons(atoi(argv[1]));   //指定通信端口
    //端口范围一般从1024到65535 小于1024的端口要启用需系统权限
    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0){
        perror("bind");
        close(listenfd);
        return -1;
    }
    
    //第三步：把socket设置为监听模式
    if(listen(listenfd, 5) != 0){
        perror("listen");
        close(listenfd);
        return -1;
    }

    //第四步：接受客户端的连接
    int clientfd;       //客户端的socket
    int socklen = sizeof(struct sockaddr_in);   //struct sockaddr_in的大小
    struct sockaddr_in clientaddr;  //客户端的地址信息的数据结构
    clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)& socklen);
    printf("客户端(%s)已连接。\n", inet_ntoa(clientaddr.sin_addr));

    //第五步：与客户端通信，接收客户端发过来的报文后回复ok。
    char buffer[1024];
    while(1){
        int iret;
        memset(buffer, 0, sizeof(buffer));
        //接收客户端的请求报文
        if((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0){
            printf("iret = %d\n", iret); break;
        }
        printf("接收：%s\n", buffer);

        strcpy(buffer, "ok");
        if((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0){
            perror("send");
            break;
        }
        printf("发送：%s\n", buffer);
    }
    //第六步：关闭socket，释放资源。    
    //服务器有两个端口，listenfd用于监听，clientfd用于与客户端收发数据
    close(listenfd);
    close(clientfd);
    return 0;
}
