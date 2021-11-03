#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));	//����һ����ά����
		int start_x = 0, start_y = 0;	//����ÿѭ��һ��Ȧ����ʼλ��
		int loop = n / 2;	//ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1��ֻ��ѭ��һȦ
		int mid = n / 2;	//�����м��λ�ã����磺nΪ3���м�λ�þ���(1, 1),nΪ5���м�λ�þ���(2, 2)
		int count = 1;		//������������ÿһ���ո�ֵ
		int offset = 1;		//ÿһȦѭ������Ҫ����ÿһ���߱����ĳ���
		int i, j;
		while (loop--) {
			i = start_x;
			j = start_y;

			//���濪ʼ���ĸ�for����ģ��ת��һȦ
			//ģ��������� ������(����ҿ�)
			for (j = start_y; j < start_y + n - offset; j++) {
				res[i][j] = count++;
			}
			//ģ��������� ���ϵ��£�����ҿ���
			for (i = start_x; i < start_x + n - offset; i++) {
				res[i][j] = count++;
			}
			//ģ��������� ���ҵ�������ҿ���
			for (; j > start_y; j--) {
				res[i][j] = count++;
			}
			//ģ��������� ���µ��ϣ�����ҿ���
			for (; i > start_x; i--) {
				res[i][j] = count++;
			}
			//�ڶ�Ȧ��ʼʱ����ʼλ��Ҫ���Լ�1�������һȦ��ʼλ��ʱ��0��0�����ڶ�Ȧ��ʼλ���ǣ�1��1��
			start_x++;
			start_y++;

			//offset����ÿһȦ��ÿһ���߱����ĳ���
			offset += 2;

		}
		//���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}

};

void test01() {
	int n = 6;
	Solution s;
	vector<vector<int>> res(n, vector<int>(n, 0));
	res = s.generateMatrix(n);
	cout << "�����������£�" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << res[i][j] << " ";			//�������
			//cout << res[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
