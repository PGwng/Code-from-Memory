/* ************************************************************************
> File Name:     不同路径.cpp
> Author:        wang
> Created Time:  Mon Dec  6 09:39:31 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

//深搜 转化为求二叉树叶子节点的个数
class Solution01{
private:
    int dfs(int i, int j, int m, int n){
        if(i > m || j > n) return 0;    //越界了
        if(i == m && j == n) return 1;  //找到一种方法，相当于找到了叶子节点
        //返回向下走一步+向右走一步的有效方法数
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);   
    }
public:
    int uniquePaths(int m, int n){
        return dfs(1, 1, m, n);
    }
};

//动态规划 时间复杂度O(m*n) 空间复杂度O(m*n)
class Solution02{
    public:
        int uniquePaths(int m, int n){
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++) dp[i][0] = 1;
            for(int j = 0; j < n; j++) dp[0][j] = 1;
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[m - 1][n - 1];
        }
};
//利用一个一维数组（可以理解为滚动数组）可以优化空间
//时间复杂度O(m*n) 空间复杂度O(n)
class Solution03{
public:
    int uniquePaths(int m, int n){
        vector<int> dp(n);
        for(int i = 0; i < n; i++) dp[i] = 1;
        for(int j =1; j < m; j++){
            for(int i = 1; i < n; i++){
                dp[i] += dp[i - 1];
            }
        }
        return dp[n -1];
    }
};

//数论法
class Solution04{
public:
    int uniquePaths(int m, int n){
        long long numerator = 1;    //分子
        int denominator = m - 1;    //分母
        int count = m - 1;
        int t = m + n - 2;
        while(count--){
            numerator *= (t--);
            while(denominator != 0 && numerator % denominator == 0){
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};
void test01(){
    Solution01 s1;
    Solution02 s2;
    Solution04 s4;
    cout << s2.uniquePaths(3, 7) << endl;
}
int main(){
    test01();
    return 0;
}

