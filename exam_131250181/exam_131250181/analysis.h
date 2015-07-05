/* 2014-11-24 */
#pragma once
#include "const.h"

/* 组合合法的单词 */
char* combine(char* part_1, char* part_2, char sign);

/* 判断符号串是否合法，并对合法的符号串进行解析 */
bool isLegal(char* word);

/* strs:拆分后的字符串数组 str:需要拆分的字符串 n:分隔符 */
/* 去除不合法的符号串，并对合法的字符串进行解析 */
void split(char strs[][STR_LEN], char* str, char n);

char* analysis(char* ifilename);