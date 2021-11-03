/* ************************************************************************
> File Name:     三数之和（哈希）.cpp
> Author:        wang
> Created Time:  Tue Oct 19 21:02:46 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //找出a + b + c = 0
        //a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++){
            //排序之后，如果第一个元素已经大于0，那么不可能凑成三元组
            if(nums[i] > 0) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue;    //元素a去重
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++){
                if (j > i + 2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]){ //b去重  
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if(set.find(c) != set.end()){
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);   //三元组c去重
                }
                else{
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

void test01(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for (auto it = result.begin(); it != result.end(); it++){
        for (auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << endl;
    }
}
int main(){
    test01();
    return 0;
}
