#include<fstream>
#include<iostream>
#include "const.h"
using namespace std;

char* outred(char* shffile) {
	ifstream ifile(shffile);
	if (ifile.fail()) {
		cout << "打开" << shffile << "文件失败！" << endl;
		exit(0);
	}

	char* ofilename = "131250181.red";
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "打开" << ofilename << "文件失败！" << endl;
		exit(0);
	}

	char tempera[TEMPERA_SIZE];
	int i_tempera = 0; // 记录最大温度
	int temIndex = 0;
	char buff[BUFF_SIZE];
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		if (ifile.eof()) {
			break;
		}

		unsigned int index = 0;
		while (buff[index] != ',') {
			ofile << buff[index++]; // 写入年份
		}
		index += 2; // 跳过","和"["
		while (true) {
			while (buff[index] != ',' && buff[index] != ']') { // 读取一个温度
				tempera[temIndex++] = buff[index++];
			}
			tempera[temIndex] = '\0';
			temIndex = 0;
			int temp = atoi(tempera);
			i_tempera = (i_tempera > temp ? i_tempera : temp);
			if (buff[index] == ']') {
				break;  // 遇到"]"结束，跳出
			}
			else if(buff[index] == ',') {
				index++; // 遇到",", 跳过
			}
		}
		ofile << "," << i_tempera << endl; // 写入最大温度
		i_tempera = 0;
	}

	cout << "输出到" << ofilename << "成功！" << endl;
	return ofilename;
}