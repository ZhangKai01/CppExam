/* 2014-11-24 */
#pragma once
#include "const.h"

/* ��ϺϷ��ĵ��� */
char* combine(char* part_1, char* part_2, char sign);

/* �жϷ��Ŵ��Ƿ�Ϸ������ԺϷ��ķ��Ŵ����н��� */
bool isLegal(char* word);

/* strs:��ֺ���ַ������� str:��Ҫ��ֵ��ַ��� n:�ָ��� */
/* ȥ�����Ϸ��ķ��Ŵ������ԺϷ����ַ������н��� */
void split(char strs[][STR_LEN], char* str, char n);

char* analysis(char* ifilename);