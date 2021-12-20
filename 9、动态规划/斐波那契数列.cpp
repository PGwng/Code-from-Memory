/* ************************************************************************
> File Name:     斐波那契数列.cpp
> Author:        wang
> Created Time:  Mon Nov 29 19:42:20 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int fib(int N){
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= N; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

class Solution01{
public:
    int fib(int N){
        if(N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= N; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

void test01(){
    Solution s;
    Solution01 s1;
    cout << s.fib(10) << " " << s1.fib(10) << endl;
}
int main(){
    test01();
    return 0;
}
