// DATE:	2016-10-30
// �����������е�N���������ҳ�����3������Ӻ�Ϊ0��������еĲ��ظ���3������Ҫ������Ľ����Ȼ����
// �ڵ����ڣ������˳���ԭ��һ�£�ÿ��֮���˳��͵�һ��������ԭ�����е�˳��һ�£������ͬ��������αȽϣ�
// INPUT :	5
//			-2 -1 0 1 2
// OUTPUT:	-2 0 2
//          -1 0 1(�޻���)
// INPUT :	5
//			2 2 0 -2 -4
// OUTPUT:	2 2 -4
//			2 0 -2(�޻���)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findResultIsZero(vector<int> arr, bool asc) {
	int size = arr.size();
	vector<vector<int>> result;
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
				vector<int> v(3);
				v[0] = arr[i];
				v[1] = arr[m];
				v[2] = arr[n];
				result.push_back(v);
				do {
					m++;
				} while (m < n && arr[m - 1] == arr[m]);
				do {
					n--;
				} while (m < n && arr[n + 1] == arr[n]);
			}
		}
		while (i < size - 2 && arr[i + 1] == arr[i]) {
			i++;
		}
	}
	return result;
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

	vector<vector<int>> result = findResultIsZero(arr, asc);
	for each (vector<int> v in result) {
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
	int a;
	cin >> a;
}
