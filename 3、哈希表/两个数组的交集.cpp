/* ************************************************************************
> File Name:     两个数组的交集.cpp
> Author:        wang
> Created Time:  Tue Oct 19 10:05:00 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;  //存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());    //将nums1存入nums_set中
        for (int num : nums2){   //定义int类型的num，每次循环从nums2中取一个数据
            //查找nums2中的元素是否在nums_set中出现过
            if (nums_set.find(num) != nums_set.end()){  //find返回地址
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

void test01(){
    vector<int> nums1 = { 4, 9, 5 };
    vector<int> nums2 = { 9, 4, 9, 8, 4 };
    Solution s;
    vector<int> result_set;
    result_set = s.intersection(nums1, nums2);
    for (vector<int>::iterator it = result_set.begin(); it != result_set.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
