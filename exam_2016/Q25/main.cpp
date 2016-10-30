// 给定有序排列的N个整数，找出其中3个数相加和为0，输出所有的不重复的3个数，要求输出的结果依然有序。
// 在单行内，输出的顺序和原来一致，每行之间的顺序和第一个数字在原数列中的顺序一致（如果相同则向后依次比较）
// INPUT :	5
//			-2 -1 0 1 2
// OUTPUT：	-2 0 2
//          -1 0 1(无换行)
// INPUT :	5
//			2 2 0 -2 -4
// OUTPUT：	2 2 -4
//			2 0 -2(无换行)

#include <iostream>
#include <vector>

using namespace std;

void findResultIsZero(vector<int> arr, bool asc) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		int m = i + 1;
		int n = size - 1;
		while (m < n) {
			int sum = arr[m] + arr[n];
			if (sum + arr[i]  > 0) {
				asc ? n-- : m++;
			}
			else if (sum + arr[i] < 0) {
				asc ? m++ : n--;
			}
			else {
				cout << arr[i] << " " << arr[m] << " " << arr[n] << endl;
				m++;
				n--;
			}
		}
	}

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

	findResultIsZero(arr, asc);
	int a;
	cin >> a;
}
