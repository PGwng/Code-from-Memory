/* ************************************************************************
> File Name:     反转字符串Ⅱ.cpp
> Author:        wang
> Created Time:  Wed Oct 20 15:23:30 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//使用库函数reverse版本
class Solution01{
public:
    string reverseStr(string s, int k){
        for(int i = 0; i < s.size(); i += (2 * k)){
            //每隔2k个字符的前k个字符进行反转
            //剩余字符小于2k 但大于或等于k个，反转前k个       
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            //如果剩余字符少于k个，则将剩余字符全部反转
            //reverse(s.begin() + i, s.begin() + s.size());
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
//自己实现reverse
class Solution02{
public:
    void reverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k){
        for(int i = 0; i < s.size(); i += (2 * k)){
            if(i + k < s.size()){
                reverse(s, i, i + k - 1);
                continue;
            }
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};
     
void test01(){
    string str = "helloworld";
    int k = 2;
    Solution01 s1;
    Solution02 s2;
    //cout << s1.reverseStr(str, k) << endl;
    cout << s2.reverseStr(str, k) << endl;
}
int main(){
    test01();
    return 0;
}
