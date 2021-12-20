/* ************************************************************************
> File Name:     two-dimension-dp-array-bag.cpp
> Author:        wang
> Created Time:  Tue Dec  7 21:06:32 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int two_dimension_bag(vector<int>& weight, vector<int>& value, int bagWeight){
        //定义dp数组
        vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
        //初始化
        for(int j = weight[0]; j <= bagWeight; j++){
            dp[0][j] = value[0];
        }
        //weight数组的大小就是物品的个数
        for(int i = 1; i < weight.size(); i++){     //遍历物品
            for(int j = 0; j <= bagWeight; j++){    //遍历背包容量
                if(j < weight[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
        //打印dp数组
        cout << "dp数组：" << endl;
        for(auto it = dp.begin(); it != dp.end(); it++){
            for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
                cout << *it_inner << " ";
            }
            cout << endl;
        }
        return dp[weight.size() - 1][bagWeight];
    }
};

void test01(){
    vector<int> weight = { 1, 3, 4};
    vector<int> value = { 15, 20, 30};
    int bagWeight = 4;
    Solution s;
    cout << s.two_dimension_bag(weight, value, bagWeight) << endl;
}
int main(){
    test01();
    return 0;
}
