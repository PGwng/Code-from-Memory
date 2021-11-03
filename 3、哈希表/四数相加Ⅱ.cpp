/* ************************************************************************
> File Name:     四数相加Ⅱ.cpp
> Author:        wang
> Created Time:  Tue Oct 19 16:15:50 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        unordered_map<int, int> umap;   //key: a+b的数值，value: a+b数值出现的次数
        //遍历数组A、B,统计两个数组元素之和，以及和出现的次数，存放到umap中
        for (int a : A)
        {
            for (int b : B){
                umap[a+b]++;    //操作符[]可以通过key找到对应的value值，可做插入、修改等操作
            }
        }
        int count = 0;  //用于统计a+b+c+d出现的次数
        //遍历数组C、D，如果找到0-（c+d）在umap中出现的话，就把umap中key对应的value也就是出现次数统计出来
        for (int c : C) {
            for (int d : D) {
                if(umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

void test01(){
    vector<int> A = { 1, 2 };
    vector<int> B = { -2, -1 };
    vector<int> C = { -1, 2 };
    vector<int> D = { 0, 2 };
    
    Solution s;
    cout << s.fourSumCount(A, B, C, D) << endl;
}
int main(){
    test01();
    return 0;
}
