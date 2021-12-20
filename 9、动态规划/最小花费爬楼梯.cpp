/* ************************************************************************
> File Name:     最小花费爬楼梯.cpp
> Author:        wang
> Created Time:  Mon Nov 29 21:21:28 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minCostClimbStairs(vector<int>& cost){
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        //注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最小值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

void test01(){
    vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    cout << s.minCostClimbStairs(cost) << endl;
}
int main(){
    test01();
    return 0;
}
