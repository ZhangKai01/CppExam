/* 2015-01-08 */
/* 给出运行的结果，并说明存在的隐患 */
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