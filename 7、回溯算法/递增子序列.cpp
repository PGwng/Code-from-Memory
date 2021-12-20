/* ************************************************************************
> File Name:     递增子序列.cpp
> Author:        wang
> Created Time:  Tue Nov 30 16:10:21 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//使用set去重
class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){        //因为要求子序列大小至少为2
            result.push_back(path);
        }
        if(startIndex > nums.size()){   //到达叶子节点，递归终止
            return;
        }
        unordered_set<int> uset;     //使用set对当前数层进行去重
        for(int i = startIndex; i < nums.size(); i++){
            //下一个数非递增 或者 下一个数与本层已使用过的元素相同
            if((!path.empty() && nums[i] < path.back()) || \
                uset.find(nums[i]) != uset.end()){
                continue;
            }
            uset.insert(nums[i]);   //记录这个元素在本层使用过了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums){
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
//使用数组去重
class Solution01{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            result.push_back(path); 
        }
        if(startIndex >= nums.size()){
            return;
        }
        //这里使用数组来去重，题目给定数值范围是[-100，100]
        int used[201] = { 0 };
        for(int i = startIndex; i < nums.size(); i++){
            //如果非递增 或者 要添加的数字在当前树层已经使用过
            if((!path.empty() && nums[i] < path.back()) || \
                    used[nums[i] + 100] == 1){
                continue;
            }
            used[nums[i] + 100] = 1;    //记录这个元素在本层使用过了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums){
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

void test01(){
    Solution s;
    Solution01 s1;
    vector<int> nums = { 4, 7, 6, 7 };
    vector<vector<int>> result;
    result = s1.findSubsequences(nums);
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
