#if 0
#include <iostream>
using namespace std;
#include <vector>

//nums升序排列
//区间的定义为左闭右闭
class Solution01 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;	//定义目标target在左闭右闭的区间里，[left, right]
		while (left <= right) {			// 当left == right，区间[left, right]依然有效，所以用 <=
			int middle = left + ((right - left) / 2);	//防止溢出，等同于(right - left) / 2
			if (nums[middle] > target) {
				right = middle - 1;		//target 在左区间，所以[left, middle - 1]
			}
			else if (nums[middle] < target) {
				left = middle + 1;		//target 在右区间，所以[middle + 1, right]
			}
			else {						//nums[middle] == target
				return middle;			//数组中找到目标值，直接返回下标
			}	
		}
		//未找到目标值
		return -1;
	}
};

//区间定义为左闭右开
class Solution02 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();		//定义目标target在左闭右开的区间里，[left, right)
		while (left < right)			//当left == right时，[left, right)是无效区间
		{
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle;			//target在左区间，所以[left, middle)
			}
			else if (nums[middle] < target) {
				left = middle + 1;		//target在右区间，所以[middle+1, right)
			}
			else {						//nums[middle] == target
				return middle;			//数组中找到目标值，直接返回下标
			}
		}
		//未找到目标值
		return -1;
	}


};

void test01() {
	vector<int> nums = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	int resultIndex;
	//Solution01 s1;
	Solution02 s2;
	resultIndex = s2.search(nums, target);
	if (resultIndex == -1) cout << target << "不存在nums中" << endl;
	else cout << target << "在nums中并且下标为" << resultIndex << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif