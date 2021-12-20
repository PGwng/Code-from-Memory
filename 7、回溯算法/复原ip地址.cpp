/* ************************************************************************
> File Name:     复原ip地址.cpp
> Author:        wang
> Created Time:  Sat Nov 27 20:35:37 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
private:
    vector<string> result;  //记录结果
    //startIndex:搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum){
        if(pointNum == 3){  //逗点数量为3时，分隔结束
            //判断第四段子字符串是否合法，如果合法就放进result中
            if(isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){  //判断[startIndex, i]这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.');   //在i的后面插入一个逗点
                pointNum++;
                //插入逗点后 剩余子串的起始位置为i+2
                backtracking(s, i + 2, pointNum);   
                pointNum--;                     //回溯
                s.erase(s.begin() + i + 1);     //回溯，删掉逗点
            }
        }
    }
    //判断字符串s在左闭右闭的区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){    //0开头的数字不合法
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){   //遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255){      //如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s){
        result.clear();
        if(s.size() > 12) return result;
        backtracking(s, 0 , 0);
        return result;
    }
};

void test01(){
    Solution s;
    string ip = "1921681137";
    vector<string> result;
    result = s.restoreIpAddresses(ip);
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << endl;
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
