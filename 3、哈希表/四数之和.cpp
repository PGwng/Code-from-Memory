/* ************************************************************************
> File Name:     四数之和.cpp
> Author:        wang
> Created Time:  Wed Oct 20 10:16:48 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            if(k > 0 && nums[k] == nums[k-1]){
                continue;
            }        
            for (int i = k + 1; i < nums.size(); i++){
                //正确去重方法
                if (i > k + 1 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while(right > left){
                    //去重复逻辑如果放在这里，在0，0，0，0……的情况下可能直接导致right<=left了，从而忽略了0，0，0这种组合。
                    /*
                     while (right > left && nums[right] == nums[right-1]) right--;
                     while (right > left && nums[left] == nums[left+1]) left++;
                    */
                    if(nums[k] + nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    }
                    else if (nums[k] + nums[i] + nums[left] + nums[right]) {
                        left++;
                    }
                    else{
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        //去重逻辑应放在找到第一个四元组后
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        while(right > left && nums[left] == nums[left + 1]) left++;

                        //找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

void test01(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result;
    Solution s;
    int target = 0;
    result = s.threeSum(nums,target);
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
