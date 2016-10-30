// �����������е�N���������ҳ�����3������Ӻ�Ϊ0��������еĲ��ظ���3������Ҫ������Ľ����Ȼ����
// �ڵ����ڣ������˳���ԭ��һ�£�ÿ��֮���˳��͵�һ��������ԭ�����е�˳��һ�£������ͬ��������αȽϣ�
// INPUT :	5
//			-2 -1 0 1 2
// OUTPUT��	-2 0 2
//          -1 0 1(�޻���)
// INPUT :	5
//			2 2 0 -2 -4
// OUTPUT��	2 2 -4
//			2 0 -2(�޻���)

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
	bool asc = true;	// ����
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
