/* 2015-01-08 */
/* 指出下面的语法错误，并指出原因 */
#include<iostream>
using namespace std;

class A {
	double value;
	const int N = 8;
protected:
	// static int count = 0; // 静态成员变量不能直接初始化
	static int count;
public:
	A(double d) {
		count++;
		value = d;
	}

	double getV() {
		return value;
	}

	~A() {
		count--;
	}
};

int A::count = 0;

class B : public A {
public:

	static void show() {
		cout << "We have " << count << "objects" << endl;
		// cout << "current value is" << value << endl;	// 不可以访问父类私有成员变量
	}

	void display(const A& a) {
		// cout << "N is" << a.N << endl;	// 不可以访问父类私有成员变量
		// cout << "value is " << a.getV() << endl;	// 只能访问const方法，因为参数a是const的
	}
};

int main(int argc, char* argv[]) {
	// B b; // B没有合适的构造函数
	// b.show();
	// display(b); // 需要指定谁去访问
}