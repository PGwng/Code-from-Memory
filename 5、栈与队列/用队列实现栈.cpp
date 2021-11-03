/* ************************************************************************
> File Name:     用队列实现栈.cpp
> Author:        wang
> Created Time:  Mon Oct 25 22:10:41 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

class MyStack{
public:
    queue<int> que;
    MyStack(){

    }
    //入栈
    void push(int x){
        que.push(x);
    }
    //出栈
    int pop(){
        int size = que.size();
        size--;
        while(size--){              //将队列头部元素（除了最后一个元素）重新添加到队列尾部
            que.push(que.front());
            que.pop();              //弹出队列头部元素（除了最后一个元素）
        }
        int result = que.front();   //此时弹出的元素顺序就是栈的顺序
        que.pop();
        return result;
    }
    //获取栈顶元素
    int top(){
        return que.back();
    }
    bool empty(){
        return que.empty();
    }
};
void test01(){
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.pop() << endl;
    st.push(3);
    st.push(4);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;
}
int main(){
    test01();
    return 0;
}
