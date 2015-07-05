#include "const.h"
#include "analysis.h"
#include<iostream>
#include<fstream>
using namespace std;

char* analysis(char* ifilename) {
	ifstream ifile(ifilename);
	if (ifile.fail()) {
		cout << "打开" << ifilename << "文件失败！" << endl;
		exit(0);
	}

	char* ofilename = OFILE_1;
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "打开" << ofilename << "文件失败！" << endl;
		exit(0);
	}

	char buff[BUFF_SIZE] = { '\0' };
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		
		if (strlen(buff) == 0) {	// 读到空行，直接写入
			ofile << endl;
			continue;
		}
		char strs[STR_NUM][STR_LEN] = { '\0' };	// 拆分后的字符串数组
		split(strs, buff, ' ');

		for (unsigned int i = 0; strs[i][0] != '\0'; i++) {
			if (strs[i + 1][0] == '\0') {	// 处理一行的最后一个单词，后面不输出空格
				if (ifile.eof()) {	// 是否最后一行
					ofile << strs[i];	// 最后一行不输出回车
				}
				else {
					ofile << strs[i] << endl;
				}
				break;
			}
			ofile << strs[i] << " ";
		}
	}
	cout << "输出到" << ofilename << "成功！" << endl;
	return ofilename;
}

/* strs:拆分后的字符串数组 str:需要拆分的字符串 n:分隔符 */
/* 去除不合法的符号串，并对合法的字符串进行解析 */
void split(char strs[][STR_LEN], char* str, char n) {
	int strs_index = 0;				// 字符串数组的下标
	char substr[STR_LEN] = { '\0' };// 临时的一个子串
	int sub_index = 0;				// 子串数组的下标
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] != n) {	// 未遇到n
			substr[sub_index++] = str[i];
			if (i == strlen(str) - 1) {	// 一行结尾
				substr[sub_index] = '\0';	// 末尾加上 '\0'
				if (isLegal(substr)) {
					strcpy_s(strs[strs_index++], STR_LEN, substr);	// 加入到字符串数组中
				}
			}
		}
		else {	// 遇到n
			substr[sub_index] = '\0';	// 末尾加上 '\0'
			if (strlen(substr) == 0) {	// 连续遇到多个空格
				continue; // 跳过
			}
			if (isLegal(substr)) {
				strcpy_s(strs[strs_index++], STR_LEN, substr);	// 加入到字符串数组中
			}
			sub_index = 0;	// 清空substr 计算下一个字串【实际上是将index设置为0，这样可以覆盖掉以前存在的字符】
		}
	}
}

/* 判断符号串是否合法，并对合法的符号串进行解析 */
bool isLegal(char* word) {
	char sign = '\0';
	char part_1[STR_LEN] = { '\0' };
	char part_2[STR_LEN] = { '\0' };
	int idx = 0;
	for (unsigned int i = 0; i < strlen(word); i++) {
		if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
			if (word[i] == '+' || word[i] == '-' || word[i] == '*') {	// 遇到变化符
				sign = word[i];
				idx = 0;
			}
			else {
				return false;	// 不合法单词
			}
		}
		else {
			if (sign == '\0') { // 未遇到变化符
				part_1[idx++] = word[i];
			}
			else {
				part_2[idx++] = word[i];
			}
		}
	}
	strcpy_s(word, STR_LEN, combine(part_1, part_2, sign));
	return true;
}

/* 组合合法的单词 */
char* combine(char* part_1, char* part_2, char sign) {
	switch (sign) {
	case '+':
		strcat_s(part_1, STR_LEN, part_2);
		break;
	case '*':
		strcat_s(part_1, STR_LEN, "s");
		strcat_s(part_1, STR_LEN, part_2);
		break;
	case '-':
		for (unsigned int i = 0; i < strlen(part_1); i++) {
			for (unsigned int j = 0; j < strlen(part_2); j++) {
				if (part_1[i] == part_2[j]) { // 去除part_1中和part_2重复的字母
					int temp_i = i;
					while (part_1[temp_i] != '\0') {
						part_1[temp_i] = part_1[temp_i + 1];
						temp_i++;
					}
					i--;
				}
			}
		}
		break;
	}
	for (unsigned int i = 0; i < strlen(part_1); i++) { // 全部转化为小写
		if (part_1[i] >= 'A' && part_1[i] <= 'Z') {
			part_1[i] += 'a' - 'A';
		}
	}
	return part_1;
}