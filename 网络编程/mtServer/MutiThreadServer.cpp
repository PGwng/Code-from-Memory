/* ************************************************************************
> File Name:     MutiProcessServer.cpp
> Author:        wang
> Created Time:  Sun Dec 12 21:06:29 2021
> Description:   
 ************************************************************************/
//编译命令：g++ net_frame.cpp MutiThreadServer.cpp -o ../bin/MutiThreadServer -lpthread -g
#include "net_frame.h"
#include <stdlib.h>
#include <signal.h>
#include <vector>
#include <pthread.h>

using namespace std;  //类成员补全 需将命名空间暴露出来

vector<long> vpthid;    //存放线程id的容器
void* pthmain(void* arg);   //线程主函数
CTcpServer TcpServer;   //创建服务端对象

//程序退出时调用的函数（这里的退出是指Ctrl+C 中止和kill 命令杀死进程，）
void mainexit(int sig);     //信号2和信号15处理函数
void pthmainexit(void* arg);    //线程清理函数

int main(int argc, char* argv[]){

    // if(argc != 3){
    //     printf("Using:./MutiProcessServer port logfile\nExample:./mpserver 5005 /tmp/mpserver.log");
    //     return -1;
    // }

    //忽略全部信号。
    for(int i = 0; i <= 64; i++) signal(i, SIG_IGN);

    //设置信号，在shell状态下可以用"kill+进程号" 正常终止进程
    //但请不要用"kill -9 +进程号" 强行终止
    //捕获Ctrl+C的信号 和 kill + 进程号的信号
    signal(SIGINT, mainexit);
    signal(SIGTERM, mainexit);
    if(TcpServer.InitServer(5005) == false){    //初始化TcpServer的通信端口
        printf("TcpServer.InitServer(5005) failed.\n");
        return -1;  //FathEXIT(-1); //通过-1来调用FathEXIT 局部对象使用exit不会调用析构释放资源
    }

    while(1){
        if(TcpServer.Accept() == false){    //等待客户端连接
            printf("TcpServer.Accept() failed.\n");
            continue;
        }

        pthread_t pthid;
        if(pthread_create(&pthid, NULL, pthmain, (void*)(long)TcpServer.m_connfd) != 0){
            printf("pthread_create failed.\n");
            return -1;
        }
        vpthid.push_back(pthid);    //把线程id保存到vpthid容器中
    }      
    return 0;
}

//线程主函数
void* pthmain(void* arg){
    pthread_cleanup_push(pthmainexit, arg); //设置线程清理函数

    pthread_detach(pthread_self()); //分离线程

    pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, NULL);    //设置取消方式为立即取消

    int sockfd = (int)(long)arg;    //与客户端的socket连接

    int ibuflen = 0;
    char strrecvbuffer[1024], strsendbuffer[1024];  //存放数据的缓冲区

    while(1){
        memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
        memset(strsendbuffer, 0, sizeof(strsendbuffer));
        //这里不能用TcpServer结构体对象中的Read和Write,因为Read和Write中用的socket是
        //全局对象中的成员m_connfd,而线程中的socket是随线程创建清理而变化的，
        //TcpServer中的m_connfd随时可能变化，每连接上一个新的客户端就会变
        if(TcpRead(sockfd, strrecvbuffer, &ibuflen, 50) == false) break;//接收客户端的请求报文
        printf("接收：%s\n", strrecvbuffer);

        strcpy(strsendbuffer, strrecvbuffer);
        strcat(strsendbuffer, "ok");
        printf("发送：%s\n", strsendbuffer);
        if(TcpWrite(sockfd, strsendbuffer) == false) break; //向客户端回应报文
    }
    pthread_cleanup_pop(1); // 线程弹出函数
    pthread_exit(0);

}

//信号2和15的处理函数
void mainexit(int sig){
    printf("mainexit begin.\n");

    //关闭监听的socket
    TcpServer.CloseListen();

    //取消全部的线程
    for(int i = 0; i < vpthid.size(); i++){
        printf("cancel %ld\n", vpthid[i]);
        pthread_cancel(vpthid[i]);
    }
    printf("mainexit end.\n");
    exit(0);
}

//线程清理函数
void pthmainexit(void* arg){
    printf("pthmainexit begin.\n");

    //关闭与客户端通信的socket
    close((int)(long)arg);

    //从vpthid中删除本线程的id
    for(int i = 0; i < vpthid.size(); i++){
        if(vpthid[i] == pthread_self()){
            vpthid.erase(vpthid.begin() + i);
        }
    }
    printf("pthmainexit end.\n");

}
