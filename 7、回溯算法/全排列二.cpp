/* ************************************************************************
> File Name:     全排列二.cpp
> Author:        wang
> Created Time:  Wed Dec  1 16:26:39 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        //到达叶子节点 说明找到了一组(递归终止条件)
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            //used[i - 1] == true, 说明同一树支nums[i - 1]使用过
            //used[i - 1] == false, 说明同一树层nums[i - 1]使用过
            //同一树层中nums[i - 1]使用过，则直接跳过
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();    //回溯撤销操作
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());     //排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

void test01(){
    Solution s;
    vector<vector<int>> result;
    vector<int> nums = { 1, 1, 2 };
    result = s.permuteUnique(nums);
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
