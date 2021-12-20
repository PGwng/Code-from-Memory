/* ************************************************************************
> File Name:     tcppoll.cpp
> Author:        wang
> Created Time:  Thu Dec 16 10:59:09 2021
> Description:   
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>

//  ulimit -n
#define MAXNFDS 1024

//初始化服务端的监听端口。
int initserver(int port);

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("using:./tcpselect port\nExample:./tcpselect 5005");
        return -1;
    }
    //初始化服务端用于监听的socket
    int listensock = initserver(atoi(argv[1]));
    printf("listensock=%d\n", listensock);

    if(listensock < 0){
        printf("initserver() failed.\n");
        return -1;
    }

    int maxfd;  //fds数组中需要监视的socket的最大值
    struct pollfd fds[MAXNFDS];//fds存放需要监视的socket。

    for(int i = 0; i < MAXNFDS; i++) fds[i].fd = -1;//初始化数组，把fd全部置为-1；因为poll传入的fd如果为负数的话就会忽略它。

    //把listensock添加到数组中。
    fds[listensock].fd = listensock;
    fds[listensock].events = POLLIN; //有数据可读事件，包括新客户端的连接、客户端socket有数据可读和客户端socket断开三种情况
    maxfd = listensock;

    while(1){
        int infds = poll(fds, maxfd + 1, -1);   //-1表示不使用超时
        printf("poll infds=%d\n", infds);

        //返回失败
        if(infds < 0){
            printf("poll() failed.\n");
            perror("poll():");
            break;
        }
        //超时
        if(infds = 0){
            printf("poll() timeout.\n");
            continue;
        }
        //检查有事件发生的socket，包括监听和与客户端连接的socket
        //这里是客户端的socket事件，每次都要遍历整个集合，
        //因为可能有多个socket事件
        for(int eventfd = 0; eventfd <= maxfd; eventfd++){
            if(fds[eventfd].fd < 0) continue;

            if((fds[eventfd].revents & POLLIN) == 0) continue;
            //如果fd有事件发生
            fds[eventfd].revents = 0;   //先清空标志位
            if(eventfd == listensock){
                //如果发生事件的是listensock,表示有新的客户端连上来
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                //这里的accept不会阻塞等待，因为服务器是接收到第三次握手信号
                //才进入这里，所以可以马上建立与客户端的连接，多进程/多线程
                //模型中是阻塞在accept等待第三次握手信号
                int clientsock = accept(listensock, (struct sockaddr*)&client, &len);
                if(clientsock < 0){
                    printf("accept() failed.\n"); continue;
                }
                printf("client(socket= %d) connected ok.\n", clientsock);
                if(clientsock > MAXNFDS){
                    printf("clientsock(%d) > MAXNFDS(%d)\n",clientsock, MAXNFDS);
                    close(clientsock);
                    continue;
                }
                //把新的socket加入数组
                fds[clientsock].fd = clientsock;
                fds[clientsock].events = POLLIN;
                fds[clientsock].revents = 0;
                //更新maxfd
                //if(maxfd < clientsock) maxfd = clientsock;
                maxfd = (maxfd < clientsock ? clientsock : maxfd);
                printf("maxfd=%d\n", maxfd);
                continue;
            }
            else{   //客户端有数据过来或客户端的socket连接被断开
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));

                //读取客户端的数据。
                ssize_t isize = read(eventfd, buffer, sizeof(buffer));

                //发生了错误或socket被对方关闭
                if(isize <= 0){
                    printf("client(eventfd=%d) disconnected.\n", eventfd);
                    close(eventfd);     //关闭客户端的socket。
                    fds[eventfd].fd = -1;

                    //重新计算maxfd的值，注意只有当eventfd=maxfd时才需要重新计算
                    if(eventfd == maxfd){
                        for(int i = maxfd; i > 0; i++){
                            if(fds[i].fd != -1){
                                maxfd = i;
                                break;//找到了最大的socket描述符，退出for循环
                            }
                        }
                        printf("maxfd=%d\n",maxfd);
                    }
                    continue;
                }
                printf("recv(eventfd=%d, size=%d):%s\n",eventfd, isize, buffer);
                //把收到的报文发回给客户端
                write(eventfd, buffer, strlen(buffer));
            }
        }
    }
    return 0;
}
//初始化服务端的监听端口
int initserver(int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        printf("socket() failed.\n"); return -1;
    }
    //Linux下 防止重新启用socket文件描述符延迟
    int opt = 1;
    unsigned int len = sizeof(opt);
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, len);
    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, len);

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if(bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("bind() failed.\n");
        close(sock);
        return -1;
    }
    if(listen(sock, 5) != 0){
        printf("listen() failed.\n");
        close(sock);
        return -1;
    }
    return sock;
}


