#include "const.h"
#include "analysis.h"
#include<iostream>
#include<fstream>
using namespace std;

char* analysis(char* ifilename) {
	ifstream ifile(ifilename);
	if (ifile.fail()) {
		cout << "��" << ifilename << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char* ofilename = OFILE_1;
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "��" << ofilename << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char buff[BUFF_SIZE] = { '\0' };
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		
		if (strlen(buff) == 0) {	// �������У�ֱ��д��
			ofile << endl;
			continue;
		}
		char strs[STR_NUM][STR_LEN] = { '\0' };	// ��ֺ���ַ�������
		split(strs, buff, ' ');

		for (unsigned int i = 0; strs[i][0] != '\0'; i++) {
			if (strs[i + 1][0] == '\0') {	// ����һ�е����һ�����ʣ����治����ո�
				if (ifile.eof()) {	// �Ƿ����һ��
					ofile << strs[i];	// ���һ�в�����س�
				}
				else {
					ofile << strs[i] << endl;
				}
				break;
			}
			ofile << strs[i] << " ";
		}
	}
	cout << "�����" << ofilename << "�ɹ���" << endl;
	return ofilename;
}

/* strs:��ֺ���ַ������� str:��Ҫ��ֵ��ַ��� n:�ָ��� */
/* ȥ�����Ϸ��ķ��Ŵ������ԺϷ����ַ������н��� */
void split(char strs[][STR_LEN], char* str, char n) {
	int strs_index = 0;				// �ַ���������±�
	char substr[STR_LEN] = { '\0' };// ��ʱ��һ���Ӵ�
	int sub_index = 0;				// �Ӵ�������±�
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] != n) {	// δ����n
			substr[sub_index++] = str[i];
			if (i == strlen(str) - 1) {	// һ�н�β
				substr[sub_index] = '\0';	// ĩβ���� '\0'
				if (isLegal(substr)) {
					strcpy_s(strs[strs_index++], STR_LEN, substr);	// ���뵽�ַ���������
				}
			}
		}
		else {	// ����n
			substr[sub_index] = '\0';	// ĩβ���� '\0'
			if (strlen(substr) == 0) {	// ������������ո�
				continue; // ����
			}
			if (isLegal(substr)) {
				strcpy_s(strs[strs_index++], STR_LEN, substr);	// ���뵽�ַ���������
			}
			sub_index = 0;	// ���substr ������һ���ִ���ʵ�����ǽ�index����Ϊ0���������Ը��ǵ���ǰ���ڵ��ַ���
		}
	}
}

/* �жϷ��Ŵ��Ƿ�Ϸ������ԺϷ��ķ��Ŵ����н��� */
bool isLegal(char* word) {
	char sign = '\0';
	char part_1[STR_LEN] = { '\0' };
	char part_2[STR_LEN] = { '\0' };
	int idx = 0;
	for (unsigned int i = 0; i < strlen(word); i++) {
		if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
			if (word[i] == '+' || word[i] == '-' || word[i] == '*') {	// �����仯��
				sign = word[i];
				idx = 0;
			}
			else {
				return false;	// ���Ϸ�����
			}
		}
		else {
			if (sign == '\0') { // δ�����仯��
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

/* ��ϺϷ��ĵ��� */
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
				if (part_1[i] == part_2[j]) { // ȥ��part_1�к�part_2�ظ�����ĸ
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
	for (unsigned int i = 0; i < strlen(part_1); i++) { // ȫ��ת��ΪСд
		if (part_1[i] >= 'A' && part_1[i] <= 'Z') {
			part_1[i] += 'a' - 'A';
		}
	}
	return part_1;
}