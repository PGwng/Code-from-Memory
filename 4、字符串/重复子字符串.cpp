/* ************************************************************************
> File Name:     重复子字符串.cpp
> Author:        wang
> Created Time:  Sun Oct 24 19:14:05 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//前缀表不减一
class Solution01{
public:
    void getNext(int* next, const string& s){
        next[0] = 0;
        int j = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){   //j指向前缀起始位置，i指向后缀起始位置
                j = next[j - 1];    //前后缀不相等，j回退
            }
            if(s[i] == s[j]){
                j++;        //如果前后缀相同，指针i和j同时移动一个单位，i++在for循环里
            }
            next[i] = j;    //j表示公共前后缀长度，此处将公共前后缀存入next数组
        }
    }
    bool repeatedSubstringPattern(string s){
        if(s.size() == 0){
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if(next[len - 1] != 0 && len % (len - (next[len - 1])) == 0){
            return true;
        }
        return false;
    }
};
//前缀表统一减一
class Solution02{
public:
    void getNext(int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j+1]){
                j = next[j];
            }
            if(s[i] == s[j+1]){
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s){
        if(s.size() == 0){
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if(next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0){
            return true;
        }
        return false;
    }
};

void test01(){
    string str = "abcabc";
    Solution01 s01;
    Solution02 s02;
    cout << s01.repeatedSubstringPattern(str) << endl;
    cout << s02.repeatedSubstringPattern(str) << endl;
}
int main(){
    test01();
    return 0;
}
