/* ************************************************************************
> File Name:     翻转字符串里的单词.cpp
> Author:        wang
> Created Time:  Wed Oct 20 21:42:28 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    //反转字符串s中左闭右闭的区间[start, end]
    void reverse(string& s, int start, int end){
        for (int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
    //移除冗余空格：使用双指针（快慢指针法），时间复杂度为O(n)的算法
    //其实就是快指针预读后面字符串的内容，把不要的字符过滤掉，再逐位赋给慢指针
    void removeExtraSpaces(string& s){
        int slowIndex = 0, fastIndex = 0;   //定义快慢指针
        //去掉字符串前面的空格
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' '){
            fastIndex++;
        }
        for(; fastIndex < s.size(); fastIndex++){
            //去掉字符串中间部分的冗余空格
            if(fastIndex - 1 > 0 
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            }
            else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' '){   //去掉字符串末尾的空格，因为for循环最后一次赋值后对slowIndex做了++操作,所以-1后才是最后一个字符的Index
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex); //size要比Index大1（Index是从0开始计数的）
        }
    }
    string reverseWords(string s){
        removeExtraSpaces(s);       //去掉冗余空格
        reverse(s, 0, s.size() - 1);    //将字符串全部反转
        int start = 0;  //反转的单词在字符串里的起始位置
        int end = 0;    //反转的单词在字符串里的终止位置
        bool entry = false;     //标记枚举字符串的过程中是否已经进入了单词区间
        for(int i = 0; i < s.size(); i++){  //开始反转单词
            if(!entry){
                start = i;  //确定单词起始位置
                entry = true;
            }
            //单词后面有空格的情况，空格就是分词符
            if(entry && s[i] == ' ' && s[i - 1] != ' '){
                end = i - 1;    //确定单词终止位置
                entry = false;  //结束单词区间
                reverse(s, start, end);
            }
            //最后一个结尾单词之后没有空格的情况
            if(entry && (i == (s.size() - 1)) && s[i] != ' '){
                end = i;    //确定单词终止位置
                entry = false;  //结束单词区间
                reverse(s, start, end);
            }
        }
        return s;
    }
};

void test01(){
    string str = " hello   world  ";
    Solution s;
    cout << s.reverseWords(str) << endl;
}
int main(){
    test01();
    return 0;
}
