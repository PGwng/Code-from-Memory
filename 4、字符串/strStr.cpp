/* ************************************************************************
> File Name:     strStr.cpp
> Author:        wang
> Created Time:  Thu Oct 21 20:13:24 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//前缀表统一减一
class Solution01{
public:
    //构造前缀表next数组
    void getNext(int* next, const string& s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {     //i指向后缀的起始位置，j指向前缀的起始位置
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];    //一个一个字符向前回退，直到找到与后缀起始字符s[i]相同的字符
                                //或者回退到前缀起始位置 为止
            }
            if(s[i] == s[j + 1]) {  //找到相同的前后缀
                j++;
            }
            next[i] = j;    //将j（前缀长度）赋给next[i]
        }
    }
    //使用next数组来做匹配
    int strStr(string haystack, string needle){
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;     //因为next数组里记录的起始位置是-1，匹配时是从j+1开始比较的
        for(int i = 0; i < haystack.size(); i++){  //注意匹配文本串是从0开始的
            //j = -1时，若不匹配，直接进入下一轮for循环
            while(j >= 0 && haystack[i] != needle[j + 1]){//模式串中间或末尾出现不匹配，
                j = next[j];    //寻找不匹配字符前一段匹配的模式串子串，子串的后缀可能是下一段匹配字符串的前缀，因此从前后缀相等的下一个位置开始继续匹配，next[j]记录的便是模式串中继续匹配的位置
            }
            if(haystack[i] == needle[j + 1]){  //若匹配，则j和i同时向后移动一位
                j++;    //i的增加在for循环里
            }
            if (j == (needle.size() - 1)){      //若已匹配到模式串的最后一个字符说明已经匹配完成
                return (i - needle.size() + 1); //返回文本串中与模式串相同的子串的起始位置
            }
        }
        return -1;
    }
};

//前缀表不减一
class Solution02{
public:
    //构造前缀表next数组
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){   //前后缀不相等
                j = next[j - 1];            //向前回退
            }
            if(s[i] == s[j]){   //前后缀相等，i和j同时向后移动一位，i++在for循环里
                j++;            //j是数组的序，从0开始，++后才是这一段子串的最长公共前后缀的字符数量
            }
            next[i] = j;    //记录以i为终点的子串的最长公共前后缀
        }
    }
    //使用next数组来做匹配
    int strStr(string haystack, string needle){
        if(needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){   //模式串中间或末尾出现不匹配
                j = next[j - 1];    //寻找模式串中继续匹配的位置
            }
            if(haystack[i] == needle[j]){   //若匹配i，j同时向后移动一位
                j++;
            }
            if(j == needle.size()){ //若匹配到模式串中的最后一个字符说明已经匹配完成
                return (i - needle.size() + 1); //返回文本串中与模式串相同的子串的起始位置
            }                   
        }
        return -1;
    }
};
void test01(){
    string haystack = "aabaabaafa";
    string needle = "aabaaf";
    Solution01 s1;
    Solution02 s2;
    //cout << s1.strStr(haystack, needle) << endl;
    cout << s2.strStr(haystack, needle) << endl;
}
int main(){
    test01();
    return 0;
}
