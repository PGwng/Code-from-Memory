#if 0
#include <iostream>
using namespace std;
#include <vector>

//�����ⷨ������������Ѱ�ҷ���������������
class Solution01 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;		//���ս��
		int sum = 0;				//��������ֵ֮��
		int subLength = 0;			//�����еĳ���
		for (int i = 0; i < nums.size(); i++) {		//�������������Ϊi
			sum = 0;
			for (int j = i; j < nums.size(); j++) {	//������������ֹλ��Ϊj
				sum += nums[j];
				if (sum >= s) {		//һ�����������кͳ�����s������result
					subLength = j - i + 1;	//	ȡ�����г���
					result = result < subLength ? result : subLength;
					break;	//��Ϊ�������ҷ���������̵������У�����һ������������break
				}
			}
		}
		//���resultû�б���ֵ�Ļ��ͷ���0��˵��û�з���������������
		return result == INT32_MAX ? 0 : result;
	}
};
//�������ڷ�	ʱ�临�Ӷȣ�$O(n)$ �ռ临�Ӷȣ�$O(1)$
class Solution02 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;		//���ս��
		int sum = 0;				//����������ֵ֮��
		int i = 0;					//����������ʼλ��
		int subLength = 0;			//�������ڳ���
		for (int j = 0; j < nums.size(); j++) {		
			sum += nums[j];
			//ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
			while (sum >= s) {
				subLength = j - i + 1;
				result = result < subLength ? result : subLength;
				sum -= nums[i++];	//�������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
			}
		}
		//���resultû�б���ֵ�Ļ��ͷ���0��˵��û�з���������������
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
	if (length == 0) cout << "û�з���������������" << endl;
	else {
		cout << "���������������г���Ϊ" << length << endl;
	}

}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif