#include<iostream>
#include<fstream>
#include "const.h"
#include "list.h"
#include "calculate.h"
using namespace std;

/* 计算每个单词出现的频率并且进行排序 */
char* calculate(char* ifilename) {
	ifstream ifile(ifilename);
	if (ifile.fail()) {
		cout << "打开" << ifilename << "文件失败！" << endl;
		exit(0);
	}

	char* ofilename = OFILE_2;
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "打开" << ofilename << "文件失败！" << endl;
		exit(0);
	}

	List *list = new List();
	while (!ifile.eof()) {
		char* buff = new char[STR_LEN];
		ifile >> buff; // 读取一个单词
		if (!list->contains(buff)) {	// 如果包含num自动+1
			list->push(buff);
		}
	}
	list->sort();	// 排序
	// 写出到文件中
	Word* word = list->getHead()->next;
	while (word->next) {
		ofile << word->data << " " << word->num << endl;
		word = word->next;
	}
	ofile << word->data << " " << word->num; // 写最后一个单词，后面没有回车换行

	cout << "输出到" << ofilename << "成功！" << endl;
	return ofilename;
}