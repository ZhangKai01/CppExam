/* 2014-11-24 */
/* 2014c++���п����ϻ��⣬��Ʋ�ʵ��һ������һ�ݼ����ļ��ĳ��� */
#include "analysis.h"
#include "calculate.h"

int main(int argc, char* argv[]) {
	char* filename_1 = analysis(argv[1]);
	char* filename_2 = calculate(filename_1);
}