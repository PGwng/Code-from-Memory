#if 0
#include <iostream>
using namespace std;
#include <vector>

//暴力解法，遍历，不断寻找符合条件的子序列
class Solution01 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;		//最终结果
		int sum = 0;				//子序列数值之和
		int subLength = 0;			//子序列的长度
		for (int i = 0; i < nums.size(); i++) {		//设置子序列起点为i
			sum = 0;
			for (int j = i; j < nums.size(); j++) {	//设置子序列终止位置为j
				sum += nums[j];
				if (sum >= s) {		//一旦发现子序列和超过了s，更新result
					subLength = j - i + 1;	//	取子序列长度
					result = result < subLength ? result : subLength;
					break;	//因为我们是找符合条件最短的子序列，所以一旦符合条件就break
				}
			}
		}
		//如果result没有被赋值的话就返回0，说明没有符合条件的子序列
		return result == INT32_MAX ? 0 : result;
	}
};
//滑动窗口法	时间复杂度：$O(n)$ 空间复杂度：$O(1)$
class Solution02 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;		//最终结果
		int sum = 0;				//滑动窗口数值之和
		int i = 0;					//滑动窗口起始位置
		int subLength = 0;			//滑动窗口长度
		for (int j = 0; j < nums.size(); j++) {		
			sum += nums[j];
			//注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
			while (sum >= s) {
				subLength = j - i + 1;
				result = result < subLength ? result : subLength;
				sum -= nums[i++];	//这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
			}
		}
		//如果result没有被赋值的话就返回0，说明没有符合条件的子序列
		return result == INT32_MAX ? 0 : result;
	}
};



void test01() {
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int s = 7;
	int length = 0;
	Solution01 s1;
	Solution02 s2;
	length = s2.minSubArrayLen(s, nums);
	if (length == 0) cout << "没有符合条件的子序列" << endl;
	else {
		cout << "符合条件的子序列长度为" << length << endl;
	}

}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif