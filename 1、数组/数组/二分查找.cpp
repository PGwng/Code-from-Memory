#if 0
#include <iostream>
using namespace std;
#include <vector>

//nums��������
//����Ķ���Ϊ����ұ�
class Solution01 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;	//����Ŀ��target������ұյ������[left, right]
		while (left <= right) {			// ��left == right������[left, right]��Ȼ��Ч�������� <=
			int middle = left + ((right - left) / 2);	//��ֹ�������ͬ��(right - left) / 2
			if (nums[middle] > target) {
				right = middle - 1;		//target �������䣬����[left, middle - 1]
			}
			else if (nums[middle] < target) {
				left = middle + 1;		//target �������䣬����[middle + 1, right]
			}
			else {						//nums[middle] == target
				return middle;			//�������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}	
		}
		//δ�ҵ�Ŀ��ֵ
		return -1;
	}
};

//���䶨��Ϊ����ҿ�
class Solution02 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();		//����Ŀ��target������ҿ��������[left, right)
		while (left < right)			//��left == rightʱ��[left, right)����Ч����
		{
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle;			//target�������䣬����[left, middle)
			}
			else if (nums[middle] < target) {
				left = middle + 1;		//target�������䣬����[middle+1, right)
			}
			else {						//nums[middle] == target
				return middle;			//�������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		//δ�ҵ�Ŀ��ֵ
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
	if (resultIndex == -1) cout << target << "������nums��" << endl;
	else cout << target << "��nums�в����±�Ϊ" << resultIndex << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif