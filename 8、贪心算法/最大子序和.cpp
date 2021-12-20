/* ************************************************************************
> File Name:     最大子序和.cpp
> Author:        wang
> Created Time:  Mon Nov 29 16:24:26 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > result){ //取区间累计的最大值
                result = count;
            }
            if(count <= 0) count = 0;   //相当于重置最大子序的起始位置
        }
        return result;
    }
};

void test01(){
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution s;
    cout << s.maxSubArray(nums);
}
int main(){
    test01();
    return 0;
}
