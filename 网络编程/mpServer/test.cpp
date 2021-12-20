/* ************************************************************************
> File Name:     test.cpp
> Author:        wang
> Created Time:  Wed Dec 15 10:07:15 2021
> Description:   
 ************************************************************************/
#include "net_frame.h"
#include <iostream>

using namespace std;

struct person{
    int age;
    int num;
};
int main(){
    person p;
    p.age = 16909060;
    p.num = 84281096;
    p.age = htonl(p.age);
    p.num = htonl(p.num);
    char buffer[8];
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer, &p, sizeof(buffer));

    //memcpy(buffer, &(p.age), 4);
    //memcpy(buffer + 4, &(p.num), 4);
    for(int i = 0; i < 8; i++){
        printf("%x , 地址：%x\n", buffer[i], &(buffer[i]));
    }
    return 0;
}
