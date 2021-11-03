#if 0
#include <iostream>
using namespace std;
#include <vector>

//暴力解法
class Solution01 {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) {		//发现需要移除的元素，就将该元素后的数组整体向前移动一位
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];
				}
				i--;		//因为i以后的数都向前移动了一个位置，要重新判断i位置的数是否等于val
							//--再++后进入下一轮循环以重新判断i位置
				size--;
			}
		}
		return size;
	}
};
//双指针法
class Solution02 {
public:
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (val != nums[fastIndex]) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		return slowIndex;
	}
};


void test01() {
	vector<int> nums = { 0, 1, 2, 3, 3, 0, 4, 2 };
	int val = 2;
	int nums_size;
	Solution01 s1;
	Solution02 s2;
	nums_size = s2.removeElement(nums, val);
	cout << "删除元素" << val << "后的nums的size为" << nums_size << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif
