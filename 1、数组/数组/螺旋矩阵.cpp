#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));	//定义一个二维数组
		int start_x = 0, start_y = 0;	//定义每循环一个圈的起始位置
		int loop = n / 2;	//每个圈循环几次，例如n为奇数3，那么loop = 1，只是循环一圈
		int mid = n / 2;	//矩阵中间的位置，例如：n为3，中间位置就是(1, 1),n为5，中间位置就是(2, 2)
		int count = 1;		//用来给矩阵中每一个空格赋值
		int offset = 1;		//每一圈循环，需要控制每一条边遍历的长度
		int i, j;
		while (loop--) {
			i = start_x;
			j = start_y;

			//下面开始的四个for就是模拟转了一圈
			//模拟填充上行 从左到右(左闭右开)
			for (j = start_y; j < start_y + n - offset; j++) {
				res[i][j] = count++;
			}
			//模拟填充右列 从上到下（左闭右开）
			for (i = start_x; i < start_x + n - offset; i++) {
				res[i][j] = count++;
			}
			//模拟填充下行 从右到左（左闭右开）
			for (; j > start_y; j--) {
				res[i][j] = count++;
			}
			//模拟填充左列 从下到上（左闭右开）
			for (; i > start_x; i--) {
				res[i][j] = count++;
			}
			//第二圈开始时，起始位置要各自加1，例如第一圈起始位置时（0，0），第二圈起始位置是（1，1）
			start_x++;
			start_y++;

			//offset控制每一圈里每一条边遍历的长度
			offset += 2;

		}
		//如果n为奇数的话，需要单独给矩阵最中间的位置赋值
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
	cout << "螺旋矩阵如下：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << res[i][j] << " ";			//输出对齐
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
