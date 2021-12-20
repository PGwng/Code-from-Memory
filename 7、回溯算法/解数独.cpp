/* ************************************************************************
> File Name:     解数独.cpp
> Author:        wang
> Created Time:  Fri Dec  3 16:03:53 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){  //遍历行
            for(int j = 0; j < board[0].size(); j++){   //遍历列
                if(board[i][j] != '.') continue;
                for(char k = '1'; k <= '9'; k++){    //(i,j)这个位置放k是否合适
                    if(isValid(i, j, k, board)){
                        board[i][j] = k;    //放置k
                        if(backtracking(board)) return true;
                        board[i][j] = '.';  //回溯 撤销k
                    }
                }
                return false;       //9个数试完都不行，就返回false;
            }
        }
        return true;    //遍历完没有返回false,说明找到了合适的位置
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board){
        //判断行里是否重复
        for(int i = 0; i < 9; i++){
            if(board[row][i] == val){
                return false;
            }
        }
        //判断列里是否重复
        for(int j = 0; j < 9; j++){
            if(board[j][col] == val){
                return false;
            }
        }
        //判断9方格里是否重复
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board){
        cout << backtracking(board);
    }
};

void test01(){
    Solution s;
    vector<vector<char>> board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    s.solveSudoku(board);
}
int main(){
    test01();
    return 0;
}
