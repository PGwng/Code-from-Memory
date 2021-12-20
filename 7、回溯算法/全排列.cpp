/* ************************************************************************
> File Name:     全排列.cpp
> Author:        wang
> Created Time:  Wed Dec  1 10:32:20 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){     //到达叶子节点 递归终止
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;   //path里已经使用过该元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();    //回溯撤销操作
            used[i] = false;    //回溯撤销操作
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

void test01(){
    Solution s;
    vector<vector<int>> result;
    vector<int> nums = { 1, 2, 3 };
    result = s.permute(nums);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[" << " ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "]" << " ";
    }
    cout << endl;
    cout << "]";
}
int main(){
    test01();
    return 0;
}
