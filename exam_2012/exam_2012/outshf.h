#include<iostream>
#include<fstream>
#include "const.h"
using namespace std;

void createMap(int map[][MAP_SIZE], char* year, char* tempera, int& num) {
	int i_year = atoi(year);
	int i_tempera = atoi(tempera);
	for (int i = 0; i < num; i++) {
		if (i_year == map[i][1]) { // 判断年份是否已经存在
			map[i][map[i][0] + 2] = i_tempera;
			map[i][0]++;
			return;
		}
	}
	// 年份不存在
	map[num][1] = i_year;
	map[num][2] = i_tempera;
	map[num][0]++;
	num++;
}

char* outshf(char* mapfile) {
	ifstream ifile(mapfile);
	if (ifile.fail()) {
		cout << "打开" << mapfile << "文件失败！" << endl;
		exit(0);
	}

	char* ofilename = "131250181.shf";
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "打开" << ofilename << "文件失败！" << endl;
		exit(0);
	}

	// map的第一列存储这一行有几个温度记录
	// map的第二列存储年份，后面是对应这个年份的温度
	int map[MAP_SIZE][MAP_SIZE] = { 0 }; // 好浪费
	int num = 0; // 一共有几个年份的记录
	char year[YEAR_SIZE];
	char tempera[TEMPERA_SIZE];
	char buff[BUFF_SIZE];
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		if (ifile.eof()) { // 文件最后如果有回车就会读一行空行
			break;
		}
		if (ifile.eof()) {
			break;
		}
		for (unsigned int i = 0; i < strlen(buff); i++) {
			if (i < YEAR_SIZE - 1) { // 读取年份
				year[i] = buff[i];
			}
			else if (i > YEAR_SIZE - 1) { // 读取月份
				tempera[i - YEAR_SIZE] = buff[i];
			}
		}
		year[YEAR_SIZE - 1] = '\0';
		tempera[strlen(buff) - YEAR_SIZE] = '\0';
		createMap(map, year, tempera, num); // 将年份月份加入到map中
	}

	// 输出到文件中
	for (int i = 0; i < num; i++) {
		ofile << map[i][1] << ",[";
		for (int j = 2; j < map[i][0] + 1; j++) {
			ofile << map[i][j] << ",";
		}
		ofile << map[i][map[i][0] + 1] << "]" << endl;
	}
	cout << "输出到" << ofilename << "成功！" << endl;
	return ofilename;
}
