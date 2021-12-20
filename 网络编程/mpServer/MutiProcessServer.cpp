/* ************************************************************************
> File Name:     MutiProcessServer.cpp
> Author:        wang
> Created Time:  Sun Dec 12 21:06:29 2021
> Description:   
 ************************************************************************/
#include "net_frame.h"
#include <stdlib.h>
#include <signal.h>

using namespace std;  //类成员补全 需将命名空间暴露出来

CTcpServer TcpServer;   //创建服务端对象

//子进程结束时调用的处理函数
void restoreChild(int sig){
    /*----处理僵尸进程方法2：wait()----*/

    /*----处理僵尸进程方法3：waitpid()----*/
    
}
//程序退出时调用的函数（这里的退出是指Ctrl+C 中止和kill 命令杀死进程，）
void FathEXIT(int sig);     //父进程退出函数
void ChildEXIT(int sig);    //子进程退出函数 不是正常退出是的处理回收

int main(int argc, char* argv[]){

    // if(argc != 3){
    //     printf("Using:./MutiProcessServer port logfile\nExample:./mpserver 5005 /tmp/mpserver.log");
    //     return -1;
    // }

    //signal(SIGCHLD, SIG_IGN);   //屏蔽子进程退出的信号，避免产生僵尸进程
                                //子进程结束后，不再给父进程发信号，内核会回收
    //signal(SIGCHLD, restoreChild);    //通过捕获子进程结束信号，在handler中进行回收
    //忽略全部信号，因为SIGCHLD信号也被忽略，所以僵尸进程可以得到处理
    for(int i = 0; i <= 64; i++) signal(i, SIG_IGN);

    //设置信号，在shell状态下可以用"kill+进程号" 正常终止进程
    //但请不要用"kill -9 +进程号" 强行终止
    //捕获Ctrl+C的信号 和 kill + 进程号的信号
    signal(SIGINT, FathEXIT);
    signal(SIGTERM, FathEXIT);
    if(TcpServer.InitServer(5005) == false){    //初始化TcpServer的通信端口
        printf("TcpServer.InitServer(5005) failed.\n");
        return -1;  //FathEXIT(-1); //通过-1来调用FathEXIT
    }

    while(1){
        if(TcpServer.Accept() == false){    //等待客户端连接
            printf("TcpServer.Accept() failed.\n");
            continue;
        }
      
        if (fork() > 0) {
        TcpServer.CloseClient();    //父进程不需要通信，关闭与客户端通信的socket
        continue;   //fork大于0是父进程 continue让父进程继续去accept
        }
        //以下是子进程，负责与客户端通信
        
        //子进程需要重新设置退出信号，因为子进程的
        //回收与父进程不同，需要不同的处理函数
        signal(SIGINT, ChildEXIT);
        signal(SIGTERM, ChildEXIT);

        TcpServer.CloseListen();    //子进程不需要监听，关闭监听的socket，节省资源
        printf("客户端(%s)已连接。\n", TcpServer.GetIP());

        char strbuffer[1024];  //存放数据的缓冲区

        while(1){
            memset(strbuffer, 0, sizeof(strbuffer));
            if(TcpServer.Read(strbuffer, 10) == false) break;  //接收客户端发过来的报文
            printf("接收：%s\n", strbuffer);

            strcat(strbuffer, "ok");    //在客户端报文后加上"ok"
            printf("发送：%s\n", strbuffer);
            if(TcpServer.Write(strbuffer) == false) break;  //向客户端回应报文
        }

        printf("客户端已断开。\n"); //程序直接退出，析构函数会释放资源

        exit(0);    //子进程运行完退出  //ChildEXIT(-1);    //通过-1调用ChildEXIT
    }
}
//父进程退出时调用的函数 (不一定由信号引起调用)
void FathEXIT(int sig){
    //因为是不可靠信号 防止短时间内重复被该信号打断
    if(sig > 0){    //可以通过FathEXIT(-1); 调用父进程退出函数，替代return -1 exit(0)等
        signal(sig, SIG_IGN);
        signal(SIGINT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
        printf("catching the signal(%d).\n", sig);
    }
    kill(0, 15);    //通知其他子进程退出
    printf("父进程退出。\n");

    //编写善后代码（释放资源、提交或回滚事务）
    TcpServer.CloseListen();

    exit(0);
}
//子进程退出时调用的函数
void ChildEXIT(int sig){
    if(sig > 0){
        signal(sig, SIG_IGN);
        signal(SIGINT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
    }
    printf("子进程退出。\n");

    //编写善后代码（释放资源、提交或回滚事务）
    TcpServer.CloseClient();

    exit(0);
}
