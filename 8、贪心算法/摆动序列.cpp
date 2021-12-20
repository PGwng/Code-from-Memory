/* ************************************************************************
> File Name:     摆动序列.cpp
> Author:        wang
> Created Time:  Mon Nov 29 11:27:34 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

//贪心
class Solution01{
public:
    int wiggleMaxLength(vector<int>& nums){
        if(nums.size() <= 1) return nums.size();
        int curDiff = 0;    //当前一对差值
        int preDiff = 0;    //前一对差值
        int result = 1;     //记录峰值个数，默认序列最右边有一个峰值
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i + 1] - nums[i];
            //出现峰值
            if((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)){
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

void test01(){
    vector<int> nums = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    Solution01 s1;
    cout << s1.wiggleMaxLength(nums) << endl;
}
int main(){
    test01();
    return 0;
}
