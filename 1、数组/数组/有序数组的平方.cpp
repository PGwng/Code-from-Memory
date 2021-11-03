#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//暴力排序，每个数平方之后，再排序,时间复杂度是 O(n + nlogn)
class Solution01 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			A[i] *= A[i];
		}
		sort(A.begin(), A.end());	//快速排序
		return A;
	}
};
//双指针法
class Solution02 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) {	// 注意这里要i <= j，因为最后要处理两个元素
			if (A[i] * A[i] < A[j] * A[j]) {
				result[k--] = A[j] * A[j];
				j--;
			}
			else {
				result[k--] = A[i] * A[i];
				i++;
			}
		}
		return result;
	}
};

void test01() {
	vector<int> nums = { -7, -3, 2, 3, 11 };
	Solution01 s1;
	Solution02 s2;
	vector<int> result(nums.size(), 0);
	result = s2.sortedSquares(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif