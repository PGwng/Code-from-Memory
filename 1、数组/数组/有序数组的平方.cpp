#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//��������ÿ����ƽ��֮��������,ʱ�临�Ӷ��� O(n + nlogn)
class Solution01 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			A[i] *= A[i];
		}
		sort(A.begin(), A.end());	//��������
		return A;
	}
};
//˫ָ�뷨
class Solution02 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) {	// ע������Ҫi <= j����Ϊ���Ҫ��������Ԫ��
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