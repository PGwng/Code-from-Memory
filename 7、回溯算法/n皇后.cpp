/* ************************************************************************
> File Name:     n皇后.cpp
> Author:        wang
> Created Time:  Fri Dec  3 10:40:29 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
private:
    vector<vector<string>> result;
    //n:棋盘大小  row:当前递归到第几行  chessboard:记录棋盘,棋盘一行就是一个字符串
    void backtracking(int n, int row, vector<string>& chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(row, col, chessboard, n)){   //验证合法就可以放
                chessboard[row][col] = 'Q'; //防止皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; //回溯 撤销皇后
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard, int n){
        //检查列
        for(int i = 0; i < row; i++){   //只检查当前行上方的列元素
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
        //检查左上角
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        //检查右上角
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n){
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

void test01(){
    Solution s;
    vector<vector<string>> result;
    result = s.solveNQueens(4);
    cout << "[" << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "[ ";
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << "] ";
    }
    cout << endl;
    cout << "]";
}
int main(){
    test01();
    return 0;
}
