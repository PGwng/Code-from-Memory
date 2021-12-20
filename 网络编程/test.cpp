/* ************************************************************************
> File Name:     test.cpp
> Author:        wang
> Created Time:  Mon Dec 13 21:23:00 2021
> Description:   
 ************************************************************************/
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){

    pid_t pid = fork();
    if(pid > 0){
        cout <<pid << endl;
        while(1);
    }else{
        cout <<pid << endl;
    }
    return 1;
}

