#include<fstream>
#include<iostream>
#include "const.h"
using namespace std;

char* outmap(char* datafile) {
	ifstream ifile(datafile);
	if (ifile.fail()) {
		cout << "��" << datafile << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char* ofilename = "131250181.map";
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "��" << ofilename << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	// char* year = (char*)malloc(sizeof(char)*10);
	// realloc(year, sizeof(char) * 100);
	char year[YEAR_SIZE];
	char tempera[TEMPERA_SIZE];
	char buff[BUFF_SIZE];
	while (!ifile.eof()) { // ��ȡһ��
		ifile.getline(buff, BUFF_SIZE);
		for (int i = 0; i < YEAR_SIZE - 1; i++) { // ��ȡ���
			year[i] = buff[i + 15];
		}
		year[YEAR_SIZE - 1] = '\0';
		for (int i = 0; i < TEMPERA_SIZE - 1; i++) { // ��ȡ�¶�
			tempera[i] = buff[i + 87];
		}
		tempera[TEMPERA_SIZE - 1] = '\0';
		double d_tempera = atoi(tempera);
		if (buff[92] == '0' || buff[92] == '1' || buff[92] == '4'
			|| buff[92] == '5' || buff[92] == '9') {
			if (d_tempera != 9999 && d_tempera != -9999) {
				ofile << year << "," << d_tempera << endl; // д����ݺ��¶�
			}
		}
	}

	cout << "�����" << ofilename << "�ɹ���" << endl;
	return ofilename;
}