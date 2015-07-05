/* 2015-01-08 */
/* 给出运行的结果，并说明存在的隐患 */
#include<iostream>
using namespace std;

class A {
public:
	A(char c) {
		cout << "class A: " << c << endl;
	}
};

class B : virtual public A {
public:
	B(char c_1, char c_2) : A(c_1) {
		cout << "class B: " << c_2 << endl;
	}
};

class C : virtual public A {
public:
	C(char c_1, char c_2) : A(c_1) {
		cout << "class C: " << c_2 << endl;
	}
};

class D : public B, public C {
public:
	D(char c_1, char c_2, char c_3, char c_4) : B(c_1, c_2), C(c_1, c_3), A(c_1) {
		cout << "class D: " << c_4 << endl;
	}
};

int main() {
	D d('A', 'B', 'C', 'D');
	return 0;
}

/* 输出：
class A: A
class B: B
class C: C
class D: D */