/* ************************************************************************
> File Name:     子集二.cpp
> Author:        wang
> Created Time:  Tue Nov 30 09:48:24 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//使用used数组去重
class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used){
        result.push_back(path);
        if(startIndex >= nums.size()){  //到达叶子节点 （递归终止条件）
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;        //回溯
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());     //去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
};
//使用set去重
class Solution01{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        result.push_back(path);
        if(startIndex >= nums.size()){      //到达叶子节点
            return;
        }
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if(uset.find(nums[i]) != uset.end()){   
                //如果在uset中找到了num[i]，说明该数字在当前树层已经使用过
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();        //回溯
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};

void test01(){
    Solution s;
    Solution01 s1;
    vector<int> nums = { 2, 1, 2, 2 };
    vector<vector<int>> result;
    result = s1.subsetsWithDup(nums);
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
