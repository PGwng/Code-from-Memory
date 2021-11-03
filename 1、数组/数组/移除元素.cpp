#if 0
#include <iostream>
using namespace std;
#include <vector>

//�����ⷨ
class Solution01 {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) {		//������Ҫ�Ƴ���Ԫ�أ��ͽ���Ԫ�غ������������ǰ�ƶ�һλ
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];
				}
				i--;		//��Ϊi�Ժ��������ǰ�ƶ���һ��λ�ã�Ҫ�����ж�iλ�õ����Ƿ����val
							//--��++�������һ��ѭ���������ж�iλ��
				size--;
			}
		}
		return size;
	}
};
//˫ָ�뷨
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
	cout << "ɾ��Ԫ��" << val << "���nums��sizeΪ" << nums_size << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif
