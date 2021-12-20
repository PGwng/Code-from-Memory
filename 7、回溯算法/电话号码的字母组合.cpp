/* ************************************************************************
> File Name:     电话号码的字母组合.cpp
> Author:        wang
> Created Time:  Wed Nov 24 10:15:34 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
private:
    const string letterMap[10] = {
        " ",    //0
        " ",    //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz", //9
    };
public:
    vector<string> result;
    string s;
    //digits:输入的电话号码数字字符串  index：指向数字字符串中的当前遍历到的位置
    void backtracking(const string& digits, int index){
        if(index == digits.size()){     //到达叶子节点
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';    //将index指向的数字转为int
        string letters = letterMap[digit];  //取数字对应的字符集
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);            //处理
            //递归，注意index+1，下一层递归处理下一个数字对应的字符集
            backtracking(digits, index + 1);    
            s.pop_back();                       //回溯

        }
    }
    vector<string> letterCombinations(string digits){
        s.clear();
        result.clear();
        if(digits.size() == 0){
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

void test01(){
    Solution s;
    vector<string> result;
    string digits = "234";
    result = s.letterCombinations(digits);
    for(vector<string>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
