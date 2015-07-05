#include<fstream>
#include<iostream>
#include "const.h"
using namespace std;

char* outred(char* shffile) {
	ifstream ifile(shffile);
	if (ifile.fail()) {
		cout << "��" << shffile << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char* ofilename = "131250181.red";
	ofstream ofile(ofilename);
	if (ofile.fail()) {
		cout << "��" << ofilename << "�ļ�ʧ�ܣ�" << endl;
		exit(0);
	}

	char tempera[TEMPERA_SIZE];
	int i_tempera = 0; // ��¼����¶�
	int temIndex = 0;
	char buff[BUFF_SIZE];
	while (!ifile.eof()) {
		ifile.getline(buff, BUFF_SIZE);
		if (ifile.eof()) {
			break;
		}

		unsigned int index = 0;
		while (buff[index] != ',') {
			ofile << buff[index++]; // д�����
		}
		index += 2; // ����","��"["
		while (true) {
			while (buff[index] != ',' && buff[index] != ']') { // ��ȡһ���¶�
				tempera[temIndex++] = buff[index++];
			}
			tempera[temIndex] = '\0';
			temIndex = 0;
			int temp = atoi(tempera);
			i_tempera = (i_tempera > temp ? i_tempera : temp);
			if (buff[index] == ']') {
				break;  // ����"]"����������
			}
			else if(buff[index] == ',') {
				index++; // ����",", ����
			}
		}
		ofile << "," << i_tempera << endl; // д������¶�
		i_tempera = 0;
	}

	cout << "�����" << ofilename << "�ɹ���" << endl;
	return ofilename;
}