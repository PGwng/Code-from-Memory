/* ************************************************************************
> File Name:     有效的括号.cpp
> Author:        wang
> Created Time:  Tue Oct 26 09:23:46 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(')');
            else if(s[i] == '[') st.push(']');
            else if(s[i] == '{') st.push('}');
            //第三种情况：遍历字符串匹配过程中，栈已经为空，没有匹配的字符了，说明右括号多余
            else if(st.empty() && (s[i] == ')' | s[i] == ']' | s[i] == '}')) return false;
            //第二种情况：遍历字符串匹配过程中，发现栈里没有要匹配的字符，说明括号类型不匹配
            else if(s[i] == ')' | s[i] == ']' | s[i] == '}') {
                if(s[i] != st.top())    return false;
                else st.pop();      //st.top()和s[i]相等，括号匹配，弹出栈顶元素
            }
        }
        //第一种情况：遍历完成，栈不为空，左括号多余
        return st.empty();
    }
};

void test01(){
    string str = "()[]{}abc([def]g)hi";
    Solution s;
    cout << s.isValid(str) << endl;
}
int main(){
    test01();
    return 0;
}
