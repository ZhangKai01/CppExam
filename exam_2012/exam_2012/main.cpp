/* 2012�ϻ������� */
/* 2014-11-05 10:56 PM */
#include "outmap.h"
#include "outshf.h"
#include "outred.h"

int main() {
	char* datafile = "data.txt";
	char* mapfile = outmap(datafile);
	char* shffile = outshf(mapfile);
	char* redfile = outred(shffile);
	/* д��ŷ���2��3�����Ժ���һ����( �s���t ) */
}