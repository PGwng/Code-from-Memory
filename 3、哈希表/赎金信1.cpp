/* ************************************************************************
> File Name:     赎金信1.cpp
> Author:        wang
> Created Time:  Tue Oct 19 20:23:41 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        for (int i = 0; i < magazine.length(); i++){
            for (int j = 0; j < ransomNote.length(); j++){
                //如果在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) {                
                    ransomNote.erase(ransomNote.begin() + j);   //删除ransom中和magazine[i]相同的字符
                    break;
                }
            }
        }
        //如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) return true;
        return false;       
    }
};

void test01(){
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    bool result;
    result = s.canConstruct(ransomNote, magazine);
    if (result == true) cout << "true" << endl;
    else cout << "false" << endl;
}
int main(){
    test01();
    return 0;
}
