/* ************************************************************************
> File Name:     左旋转字符串.cpp
> Author:        wang
> Created Time:  Thu Oct 21 09:19:01 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n){
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

void test01(){
    string str = "abcdefghi";
    Solution s;
    int n = 8;
    cout << s.reverseLeftWords(str, n) << endl;
}
int main(){
    test01();
    return 0;
}
