/* ************************************************************************
> File Name:     删除字符串中所有相邻重复项.cpp
> Author:        wang
> Created Time:  Tue Oct 26 10:20:29 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
public:
    string removeDuplicates(string s){
        stack<char> st;
        for(char c : s){
            if(st.empty() || c != st.top()){
                st.push(c);
            }
            else{
                st.pop();   //c与st.top()相等时，弹出栈顶元素
            }
        }
        //取出栈中去重后的字符串并反转
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

void test01(){
    string str = "abbcddeffg";
    Solution s;
    cout << s.removeDuplicates(str) << endl;
}
int main(){
    test01();
    return 0;
}
