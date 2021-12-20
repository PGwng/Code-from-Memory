/* ************************************************************************
> File Name:     组合总和.cpp
> Author:        wang
> Created Time:  Tue Nov 23 19:17:12 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;         //存放结果集
    vector<int> path;                   //符合条件的结果

    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(path.size() == k){       //到达叶子节点->终止
            if(sum == targetSum) result.push_back(path);
            return;     //到达叶子节点但总和不满足要求
        }
        for(int i = startIndex; i <= 9; i++){
            sum += i;   //处理
            path.push_back(i);  //处理
            backtracking(targetSum, k, sum, i + 1);     //递归时缩小下一层的范围
            sum -= i;   //回溯
            path.pop_back();    //回溯
        }
    }
public:
    vector<vector<int>> combinationSum(int k, int n){
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return result;
    }
};
//剪枝
class Solution01 {
private:
    vector<vector<int>> result;         //存放结果集
    vector<int> path;                   //符合条件的结果

    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(sum > targetSum){        //剪枝 剪枝的地方一定实在递归终止的地方剪
            return;
        }
        if(path.size() == k){       //到达叶子节点->终止
            if(sum == targetSum) result.push_back(path);
            return;     //到达叶子节点但总和不满足要求
        }
        for(int i = startIndex; i <= 9 -(k - path.size()) + 1; i++){
            sum += i;   //处理
            path.push_back(i);  //处理
            backtracking(targetSum, k, sum, i + 1);     //递归时缩小下一层的范围
            sum -= i;   //回溯
            path.pop_back();    //回溯
        }
    }
public:
    vector<vector<int>> combinationSum(int k, int n){
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return result;
    }
};

void test01(){
    int k = 3, n = 6;
    Solution01 s1;
    vector<vector<int>> result;
    result = s1.combinationSum(k, n);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[ ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
int main(){
    test01();
    return 0;
}
