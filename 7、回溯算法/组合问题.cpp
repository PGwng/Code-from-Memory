/* ************************************************************************
> File Name:     组合问题.cpp
> Author:        wang
> Created Time:  Tue Nov 23 15:24:09 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> result;     //存放符合条件的结果的集合
    vector<int> path;       //用来存放符合条件的结果
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){           //到达叶子节点
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; i++){
            path.push_back(i);  //处理节点
            backtracking(n, k, i + 1);
            path.pop_back();        //回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k){
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};

void test01(){
    Solution s;
    int n = 4, k = 2;
    vector<vector<int>> result;
    result = s.combine(n, k);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[" << " ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "]" << " ";
    }
    cout << endl;
    cout << "]" << endl;
}
int main(){
    test01();
    return 0;
}
