/* ************************************************************************
> File Name:     分发饼干.cpp
> Author:        wang
> Created Time:  Mon Nov 29 09:45:54 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//时间复杂度O(nlogn)
//空间复杂度O(1)
class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;   //饼干数组的下标
        int result = 0;
        for(int i = g.size() - 1; i >= 0; i--){
            if(index >= 0 && s[index] >= g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
};

class Solution01{
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(index < g.size() && g[index] <= s[i]){
                index++;
            }
        }
        return index;
    }
};

void test01(){
    vector<int> g = { 1, 2 };
    vector<int> s = { 1, 2, 3 };
    Solution sol;
    Solution01 sol01;
    int result;
    result = sol.findContentChildren(g, s);
    cout << result << endl;
    cout << sol01.findContentChildren(g, s) << endl;
}
int main(){
    test01();
    return 0;
}
