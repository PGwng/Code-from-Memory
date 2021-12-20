/* ************************************************************************
> File Name:     重新安排行程.cpp
> Author:        wang
> Created Time:  Thu Dec  2 10:50:22 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class Solution{
private:
    //unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result){
        if(result.size() == ticketNum + 1){ //需要到达的机场数=机票数+1
            return true;                    //result的size达到总机场数即为找到行程 退出递归
        }
        for(pair<const string, int>& target : targets[result[result.size() - 1]]){//层遍历
            if(target.second > 0){  //判断到达该机场的机票是否使用过
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        targets.clear();
        vector<string> result;
        for(const vector<string>& vec : tickets){
            targets[vec[0]][vec[1]]++;    //记录映射关系
        }
        result.push_back("JFK");    //起始机场
        backtracking(tickets.size(), result);   //传入机票数量
        return result;
    }
};


void test01(){
    vector<vector<string>> tickets = {
        { "JFK", "KUL" }, { "JFK", "NRT" }, { "NRT", "JFK" }
    };
    Solution s;
    vector<string> result;
    result = s.findItinerary(tickets);
    cout << "[ ";
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << "]";
}
int main()
{
    test01();
    return 0;
}
