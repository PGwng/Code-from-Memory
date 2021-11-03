/* ************************************************************************
> File Name:     三数之和（双指针法）.cpp
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
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //找出a+b+c = 0, a=nums[i],b=nums[left],c=nums[right]
        for (int i = 0; i < nums.size(); i++){
            //排序之后，如果第一个元素已经大于0，无论如何都不可能凑成三元组
            if(nums[i] > 0){
                return result;
            }
            //错误的去重方法,b可能会和a相等，会漏掉类似-1，-1，2这种情况
            /*
            if (nums[i] == nums[i+1]){
                continue;
            }
             */
            //正确去重方法
            if (i > 0 && nums[i] == nums[i-1]) {
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
                 if(nums[i] + nums[left] + nums[right] > 0) {
                     right--;
                 }
                 else if (nums[i] + nums[left] + nums[right]) {
                     left++;
                 }
                 else{
                     result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                     //去重逻辑应放在找到第一个三元组后
                     while(right > left && nums[right] == nums[right - 1]) right--;
                     while(right > left && nums[left] == nums[left + 1]) left++;

                     //找到答案时，双指针同时收缩
                     right--;
                     left++;
                 }
            }
        }
        return result;
    }
};

void test01(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    Solution s;
    result = s.threeSum(nums);
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
