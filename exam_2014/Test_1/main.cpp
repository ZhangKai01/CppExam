/* 2015-01-08 */
/* ָ��������﷨���󣬲�ָ��ԭ�� */
#include<iostream>
using namespace std;

class A {
	double value;
	const int N = 8;
protected:
	// static int count = 0; // ��̬��Ա��������ֱ�ӳ�ʼ��
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
		// cout << "current value is" << value << endl;	// �����Է��ʸ���˽�г�Ա����
	}

	void display(const A& a) {
		// cout << "N is" << a.N << endl;	// �����Է��ʸ���˽�г�Ա����
		// cout << "value is " << a.getV() << endl;	// ֻ�ܷ���const��������Ϊ����a��const��
	}
};

int main(int argc, char* argv[]) {
	// B b; // Bû�к��ʵĹ��캯��
	// b.show();
	// display(b); // ��Ҫָ��˭ȥ����
}