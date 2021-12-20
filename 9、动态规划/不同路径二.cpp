/* ************************************************************************
> File Name:     不同路径二.cpp
> Author:        wang
> Created Time:  Tue Dec  7 11:06:18 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePathWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) continue;   //遇到障碍格子则跳过执行 该处dp值为0
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

void test01(){
    vector<vector<int>> obstacleGrid = {
        { 0, 0, 0, 0, 0},
        { 0, 1, 0, 1, 0},
        { 0, 0, 0, 0, 0}
    };
    Solution s;
    cout << s.uniquePathWithObstacles(obstacleGrid) << endl;
}
int main(){
    test01();
    return 0;
}
