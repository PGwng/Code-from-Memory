/* ************************************************************************
> File Name:     滑动窗口最大值.cpp
> Author:        wang
> Created Time:  Tue Oct 26 15:39:44 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution{
private:
    class MyQueue{      //单调队列（从大到小）
    public:
        deque<int> que; //使用deque来实现单调队列
        //每次弹出的时候，比较当前要弹出的数值是否等于队列出口（前端）元素的数值，如果相等则弹出
        //同时pop之前盘对队列当前是否为空
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        //如果push的数值大于入口元素的值，就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的值
        //这样就保持了队列里的数值是单调从大到小的了
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        //查询当前队列里的最大值，直接返回队列前端元素（front）即可
        int front(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());      //result记录前k个元素中的最大值
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i - k]);   //滑动窗口移除最前面的元素
            que.push(nums[i]);      //滑动窗口加入最后面的元素
            result.push_back(que.front());  //记录对应的最大值
        }
        return result;
    }
};

void test01(){
    Solution s;
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
