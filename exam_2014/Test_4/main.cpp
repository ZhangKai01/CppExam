/* 2015-01-08 */
/* �������еĽ������˵�����ڵ����� */
#include<iostream>
using namespace std;

int f(int x) {
	if (x < 0) {
		x = -x;
	}

	if (x / 10 == 0) {
		return 1;
	}
	else {
		return 1 + f(x / 10);
	}
}

int main() {
	cout << f(-12345678) << endl;
}