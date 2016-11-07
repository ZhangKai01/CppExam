// DATE:	2016-10-30
// 给定有序排列的N个整数，找出其中3个数相加和为0，输出所有的不重复的3个数，要求输出的结果依然有序。
// 在单行内，输出的顺序和原来一致，每行之间的顺序和第一个数字在原数列中的顺序一致（如果相同则向后依次比较）
// INPUT :	5
//			-2 -1 0 1 2
// OUTPUT:	-2 0 2
//          -1 0 1(无换行)
// INPUT :	5
//			2 2 0 -2 -4
// OUTPUT:	2 2 -4
//			2 0 -2(无换行)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findThreeNumber(vector<int> arr, bool asc) {
	int size = arr.size();
	vector<vector<int>> result;	// 保存结果
	for (int i = 0; i < size; i++) {	// 保证"第一个数"在数组中
		int m = i + 1;
		int n = size - 1;
		while (m < n) {
			int sum = arr[m] + arr[n];	// 另外两个数的和
			if (sum + arr[i]  > 0) {
				asc ? n-- : m++;	// 升序和降序的操作不一样
			}
			else if (sum + arr[i] < 0) {
				asc ? m++ : n--;
			}
			else {	// 找到三数和为0
				vector<int> v(3);
				v[0] = arr[i];
				v[1] = arr[m];
				v[2] = arr[n];
				result.push_back(v);

				// "第二个数"和"第三个数"分别判断其下个数是否重复
				do {
					m++;
				} while (m < n && arr[m - 1] == arr[m]);

				do {
					n--;
				} while (m < n && arr[n + 1] == arr[n]);
			}
		}

		// 外层循环"第一个数"，如果下一个"第一个数"相同，则为重复数据
		while (i < size - 2 && arr[i + 1] == arr[i]) {
			i++;
		}
	}
	return result;
}

int main() {
	bool asc = true;	// 升序
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i > 0 && arr[i] < arr[i - 1]) {
			asc = false;
		}
	}

	vector<vector<int>> result = findThreeNumber(arr, asc);
	for each (vector<int> v in result) {
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
	system("pause");
}
