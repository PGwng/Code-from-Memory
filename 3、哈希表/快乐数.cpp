/* ************************************************************************
> File Name:     快乐数.cpp
> Author:        wang
> Created Time:  Tue Oct 19 10:51:34 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    //取各位上的数字的平方和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if (sum == 1) return true;

            //如果这个sum曾经出现过，说明已经陷入了无限循环，立刻return false
            if (set.find(sum) != set.end()){
                return false;
            }
            else {
                set.insert(sum);
            }
            //更新n
            n = sum;
        }
    }
};
void test01(){
    int n = 19;
    Solution s;
    bool result = s.isHappy(n);
    if (result == true) cout << n << "是快乐数" << endl;
    else cout << n << "不是快乐数" << endl;
}
int main(){
    test01();
    return 0;
}
