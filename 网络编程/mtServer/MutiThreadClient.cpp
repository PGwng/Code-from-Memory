/* ************************************************************************
> File Name:     MutiProcessClient.cpp
> Author:        wang
> Created Time:  Sun Dec 12 21:19:54 2021
> Description:   
 ************************************************************************/
#include "net_frame.h"

int main(int argc, char* argv[]){
    CTcpClient TcpClient;   //创建客户端对象

    if(TcpClient.ConnectToServer("127.0.0.1", 5005) == false){//向客户端发起连接请求
        printf("TcpClient.ConnectToServer(\"127.0.0.1\", 5005) failed.\n");
        return -1;
    }

    char strbuffer[1024];   //存放数据的缓冲区

    for(int i = 0; i < 30; i++){
        memset(strbuffer, 0, sizeof(strbuffer));
        snprintf(strbuffer, 50, "这是第%d个报文，编号%03d。", i + 1, i + 1);
        printf("发送：%s\n", strbuffer);
        if(TcpClient.Write(strbuffer) == false) break;  //向服务端发送请求报文

        memset(strbuffer, 0, sizeof(strbuffer));
        if(TcpClient.Read(strbuffer, 20) == false) break;   //接收服务器的回应报文
        printf("接收：%s\n", strbuffer);

        sleep(1);
    }
    //程序直接退出，析构函数会释放资源
}
