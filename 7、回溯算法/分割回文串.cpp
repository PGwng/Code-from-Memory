/* ************************************************************************
> File Name:     分割回文串.cpp
> Author:        wang
> Created Time:  Wed Nov 24 21:42:58 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<string>> result;
    vector<string> path;    //存放已经回文的子串
    //双指针法判断子串是否回文
    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    void backtracking(const string& s, int startIndex){
        //如果起始位置已经大于s的大小，说明已经找到了一组分割方案
        if(startIndex >= s.size()){    //到达叶子节点
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(s, startIndex, i)){ //是回文子串
                // 获取[startIndex, i]在s中的子串 substr中参数1表示截取起始位置，参数2表示截取长度
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else{   //不是回文
                continue;
            }
            backtracking(s, i + 1); //对剩余子串进行分割
            path.pop_back();    //回溯过程，弹出本次已填在path中的子串
        }
    }
public:
    vector<vector<string>> partition(string s){
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

void test01(){
    Solution s;
    vector<vector<string>> result;
    string str = "aab";
    result = s.partition(str);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[" << " ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "]" << " ";
    }
    cout << endl;
    cout << "]";
}
int main(){
    test01();
    return 0;
}
