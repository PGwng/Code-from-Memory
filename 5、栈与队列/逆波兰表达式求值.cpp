/* ************************************************************************
> File Name:     逆波兰表达式求值.cpp
> Author:        wang
> Created Time:  Tue Oct 26 10:47:45 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoi(tokens[i]));   //把string转成int
            }
        }
        int result = st.top();
        st.pop();               //把栈里的最后一个元素弹出
        return result;
    }
};

void test01(){
    Solution s;
    vector<string> tokens = { "4", "13", "5", "/", "+" };
    cout << s.evalRPN(tokens) << endl;
}
int main(){
    test01();
    return 0;
}
