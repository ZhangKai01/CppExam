/* 2014-11-26 */
#include "word.h"
#include "iostream"
using namespace std;

class List {
private:
	Word *head;
public:

	/* ��ʼ���յ�ͷ�ڵ� */
	List()	 {
		head = new Word();
	}
	
	/* ���ͷ�ڵ��ַ */
	Word* getHead() {
		return head;
	}

	/* ��������ĳ��� */
	int size() {
		Word* n = head->next;
		int count = 0;
		while (n) {
			n = n->next;
			count++;
		}
		return count;
	}

	/* ������i��Ԫ�صĵ�ַ */
	Word* locate(int i) {
		if (i < 0)
			return NULL;
		Word* current = head;
		int k = 0;
		while (current && k < i) {
			current = current->next;
			k++;
		}
		return current;
	}

	/* ����������word */
	bool push(char* word) {
		Word* current = locate(size());
		if (!current) {
			return false; // ���벻�ɹ�
		}
		Word* newWord = current->insertAfter(word);
		return true;
	}

	/* �Ƿ��Ѿ��������Ԫ�� */
	bool contains(char* word) {
		Word* n = head->next;
		while (n) {
			if (n->equals(word)) {
				n->addNum();	// ����+1
				return true;
			}
			n = n->next;
		}
		return false;
	}

	/* ��Ƶ�ʽ������У���ͬƵ�ʵİ����ֵ������� */
	void sort() {
		Word* n = head->next;
		while (n) {
			Word* max = n;
			Word* temp = max->next;
			while (temp) {
				if (max->compare(temp) < 0) {
					max = temp;
				}
				temp = temp->next;
			}
			swap(max, n);
			n = n->next;
		}
	}

	/* ��������word��ֵ */
	void swap(Word* word_1, Word* word_2) {
		char* temp_data = word_1->data;
		int temp_num = word_1->num;
		word_1->data = word_2->data;
		word_1->num = word_2->num;
		word_2->data = temp_data;
		word_2->num = temp_num;
	}

	/* ��������е�ֵ */
	void print() {
		Word* p = head;
		while (p->next) {
			p = p->next;
			cout << p->data << " " << p->num;
		}
		cout << endl;
	}
	
};
