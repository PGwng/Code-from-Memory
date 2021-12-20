/* ************************************************************************
> File Name:     爬楼梯.cpp
> Author:        wang
> Created Time:  Mon Nov 29 20:39:18 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

//时间复杂度O(n)
//空间复杂度O(n)
class Solution01{
public:
    int climbStairs(int n){
        if(n <= 1) return n;    //因为下面直接对dp[2]操作了，防止空指针
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//时间复杂度O(n)
//空间复杂度O(1)
class Solution02{
public:
    int climbStairs(int n){
        if(n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }  
};

void test01(){
    Solution01 s1;
    Solution02 s2;
    int n = 5;
    cout << s1.climbStairs(n) << " " << s2.climbStairs(n) << endl;
}
int main(){
    test01();
    return 0;
}
