/* ************************************************************************
> File Name:     两数之和.cpp
> Author:        wang
> Created Time:  Tue Oct 19 15:13:08 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//这里是由数组中元素的值查找对应的下标，map是由key查找value，map.find(key)返回迭代器
//因此用key保存数组元素的值，用value保存对应元素的下标。
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map <int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);     //自动推导变量类型
            //unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if (iter != map.end()){                     //如果在哈希表中找到了
                return { iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return { };
    }
};

void test01(){
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    Solution s;
    vector<int> index_result = s.twoSum(nums, target);
    for(vector<int>::iterator it = index_result.begin(); it != index_result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}
int main(){
    test01();
    return 0;
}
