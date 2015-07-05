/* 2015-01-08 */
/* 给出运行的结果，并说明存在的隐患 */
#include<iostream>
using namespace std;

class CBase {
public:
	CBase() {
		cout << "CBase Created!" << endl;
	}

	virtual void fun() {
		cout << "In CBase!" << endl;
	}

	void print() {
		cout << "*****" << endl;
	}

	~CBase() {
		cout << "CBase Destroyed!" << endl;
	}
};

class CSon : public CBase {
public:
	CSon() {
		cout << "CSon Created!" << endl;
	}

	virtual void fun() {
		cout << "In CSon!" << endl;
	}

	void print() {
		cout << "-----" << endl;
	}

	~CSon() {
		cout << "CSon Destroyed!" << endl;
	}
};

int main() {
	CBase *pm[2];
	pm[0] = new CBase();
	pm[1] = new CSon();

	for (CBase *cb : pm) {
		cb->fun();
		cb->print();
		delete cb;
	}
}
/* 输出：
CBase Created!
CBase Created!
CSon Created!
In CBase!
*****
CBase Destroyed!
In CSon!
*****
CBase Destroyed!
隐患：父类的析构函数没有声明为virtual */
