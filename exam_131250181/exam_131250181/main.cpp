/* 2014-11-24 */
/* 2014c++期中考试上机题，设计并实现一个解析一份加密文件的程序 */
#include "analysis.h"
#include "calculate.h"

int main(int argc, char* argv[]) {
	char* filename_1 = analysis(argv[1]);
	char* filename_2 = calculate(filename_1);
}