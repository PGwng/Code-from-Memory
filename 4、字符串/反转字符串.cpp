/* ************************************************************************
> File Name:     反转字符串.cpp
> Author:        wang
> Created Time:  Wed Oct 20 15:14:07 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s){
        for(int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
void test01(){
    vector<char> str = {'h','e','l','l','o'};
    Solution s;
    s.reverseString(str);
    for(auto it = str.begin(); it != str.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
