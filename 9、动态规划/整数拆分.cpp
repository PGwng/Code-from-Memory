/* ************************************************************************
> File Name:     整数拆分.cpp
> Author:        wang
> Created Time:  Tue Dec  7 15:16:47 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n){
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

void test01(){
    Solution s;
    cout << s.integerBreak(10) << endl;
}
int main(){
    test01();
    return 0;
}
