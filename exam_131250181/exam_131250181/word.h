/* 2014-11-26 */
#include<iostream>
using namespace std;

struct Word {
	char* data;
	int num;
	Word* next;
	Word(char* data = nullptr, Word* next = nullptr) {
		this->data = data;
		this->next = next;
		num = 1;
	}

	/* �ж������Ƿ���ͬ */
	bool equals(char* data) {
		if (strcmp(this->data, data) == 0) {
			return true;
		}
		return false;
	}

	/* Ƶ�ʴ��ֵ���ǰ�ıȽϴ� */
	int compare(Word* word) {
		if (this->num != word->num) {
			return this->num - word->num;
		}
		return -strcmp(this->data, word->data);
	}

	Word* insertAfter(char* data) {
		next = new Word(data, next);
		return next;
	}

	void addNum() {
		num++;
	}
};