/* ************************************************************************
> File Name:     一维01背包.cpp
> Author:        wang
> Created Time:  Thu Dec  9 11:05:00 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int one_dimension_bag(vector<int>& weight, vector<int>& value, int bagWeight){
        vector<int> dp(bagWeight + 1, 0);
        for(int i = 0; i < weight.size(); i++){             //遍历物品
            for(int j = bagWeight; j >= weight[i]; j--){    //遍历背包容量
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        return dp[bagWeight];
    }
};

void test01(){
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagWeight = 4;
    Solution s;
    cout << s.one_dimension_bag(weight, value, bagWeight) << endl;
}
int main(){
    test01();
    return 0;
}
