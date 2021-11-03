/* ************************************************************************
// vim: et tw=100 ts=4 sw=4 cc=120
> File Name:     有效的字母异位词.cpp
> Author:        wang
> Created Time:  Thu Oct 14 15:13:46 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = { 0 };
        for (int i = 0; i < s.size(); i++){
            record[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++){
            record[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (record[i] != 0) return false;
        }
        return true;
    }
};

void test01(){
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool flag = solution.isAnagram(s, t);
    if (flag == true) cout << "有效的字母异位词" << endl;
    else cout << "不是字母异位词" << endl;
}
int main(){
    test01();
    return 0;
}
