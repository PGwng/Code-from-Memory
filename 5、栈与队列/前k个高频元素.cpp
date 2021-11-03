/* ************************************************************************
> File Name:     前k个高频元素.cpp
> Author:        wang
> Created Time:  Tue Oct 26 16:24:05 2021
> Description:   
 ************************************************************************/
//时间复杂度：O(nlogk)
//空间复杂度：O(n)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    //升序队列 小顶堆
    class mycomparison{     //仿函数，类中定义一个operator()
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k){
        //统计元素出现频率
        unordered_map<int, int> map;    //map<nums[i],对应出现频率>
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        //对频率排序
        //定义一个小顶堆，大小为k
        //参数1表示要压入队列的元素，参数2表示队列中已存在的元素，参数3表示优先级
        //1:数据类型 2:容器类型（默认是vector，但不能传入list） 3:比较方式
        //当需要自定义数据类型时才需传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认时大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;//mycomparison回调函数
        //用固定大小为k的小顶堆，扫描所有频率的数值
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){     //如果堆的大小大于了k则队列弹出，保证队列大小一直为k
                pri_que.pop();
            }
        }
        //找出前k个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

void test01(){
    Solution s;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    vector<int> result(k);
    result = s.topKFrequent(nums, k);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
