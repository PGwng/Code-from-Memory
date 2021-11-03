/* ************************************************************************
> File Name:     赎金信2.cpp
> Author:        wang
> Created Time:  Tue Oct 19 20:42:45 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        int record[26] = { 0 };
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            //遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            //如果小于零，说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j] - 'a'] < 0) return false;
        }
        return true;
    }
};

void test01(){
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    bool result;
    result = s.canConstruct(ransomNote, magazine);
    if (result) cout << "true" << endl;
    else cout << "false" << endl;
}
int main(){
    test01();
    return 0;
}
