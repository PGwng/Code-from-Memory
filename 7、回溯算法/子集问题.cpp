/* ************************************************************************
> File Name:     子集问题.cpp
> Author:        wang
> Created Time:  Sun Nov 28 15:42:04 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        result.push_back(path); //收集子集，要放在终止条件的上面，否则会漏掉自己
        if(startIndex >= nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();        //回溯
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

void test01(){
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> result;
    result = s.subsets(nums);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[ ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "]";
    }
    cout << endl;
    cout << "]" << endl;
}
int main(){
    test01();
    return 0;
}
