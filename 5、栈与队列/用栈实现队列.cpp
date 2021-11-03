/* ************************************************************************
> File Name:     用栈实现队列.cpp
> Author:        wang
> Created Time:  Sun Oct 24 21:44:03 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

class MyQueue{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue(){

    }
    //将一个元素放入队列底部
    void push(int x){
        stIn.push(x);
    }
    //从队列首部移除元素
    int pop(){
        //只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if(stOut.empty()){
            //从stIn导入数据直到stIn为空
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    //获取队列首部元素
    int peek(){
        int res = this->pop();  
        stOut.push(res);    //因为pop函数弹出了元素res，所以再添加回去
        return res;
    }
    bool empty(){
        return stIn.empty() && stOut.empty();
    }
};

void test01(){
    MyQueue m_queue;
    m_queue.push(1);
    m_queue.push(2);
    cout << m_queue.peek() << endl;
    m_queue.pop();
    m_queue.push(3);
    m_queue.push(4);
    cout << m_queue.peek() << endl;
    m_queue.pop();
    cout << m_queue.peek() << endl;
    m_queue.pop();
    cout << m_queue.peek() << endl;
    m_queue.pop();
    cout << "是否为空：" << m_queue.empty() << endl;
}
int main(){
    test01();
    return 0;
}
