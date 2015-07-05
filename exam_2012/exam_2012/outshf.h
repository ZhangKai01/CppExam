#include<iostream>
#include<fstream>
#include "const.h"
using namespace std;

void createMap(int map[][MAP_SIZE], char* year, char* tempera, int& num) {
	int i_year = atoi(year);
	int i_tempera = atoi(tempera);
	for (int i = 0; i < num; i++) {
		if (i_year == map[i][1]) { // �ж�����Ƿ��Ѿ�����
			map[i][map[i][0] + 2] = i_tempera;
			map[i][0]++;
			return;
		}
	}
	// ��ݲ�����
	map[num][1] = i_year;
	map[num][2] = i_tempera;
	map[num][0]++;
	num++;
}

char* outshf(char* mapfile) {
	ifstream ifile(mapfile);
	if (ifile.fail()) {
		cout << "��" << mapfile << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char* ofilename = "131250181.shf";
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "��" << ofilename << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	// map�ĵ�һ�д洢��һ���м����¶ȼ�¼
	// map�ĵڶ��д洢��ݣ������Ƕ�Ӧ�����ݵ��¶�
	int map[MAP_SIZE][MAP_SIZE] = { 0 }; // ���˷�
	int num = 0; // һ���м�����ݵļ�¼
	char year[YEAR_SIZE];
	char tempera[TEMPERA_SIZE];
	char buff[BUFF_SIZE];
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		if (ifile.eof()) { // �ļ��������лس��ͻ��һ�п���
			break;
		}
		if (ifile.eof()) {
			break;
		}
		for (unsigned int i = 0; i < strlen(buff); i++) {
			if (i < YEAR_SIZE - 1) { // ��ȡ���
				year[i] = buff[i];
			}
			else if (i > YEAR_SIZE - 1) { // ��ȡ�·�
				tempera[i - YEAR_SIZE] = buff[i];
			}
		}
		year[YEAR_SIZE - 1] = '\0';
		tempera[strlen(buff) - YEAR_SIZE] = '\0';
		createMap(map, year, tempera, num); // ������·ݼ��뵽map��
	}

	// ������ļ���
	for (int i = 0; i < num; i++) {
		ofile << map[i][1] << ",[";
		for (int j = 2; j < map[i][0] + 1; j++) {
			ofile << map[i][j] << ",";
		}
		ofile << map[i][map[i][0] + 1] << "]" << endl;
	}
	cout << "�����" << ofilename << "�ɹ���" << endl;
	return ofilename;
}
