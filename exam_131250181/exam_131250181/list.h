/* 2014-11-26 */
#include "word.h"
#include "iostream"
using namespace std;

class List {
private:
	Word *head;
public:

	/* 初始化空的头节点 */
	List()	 {
		head = new Word();
	}
	
	/* 获得头节点地址 */
	Word* getHead() {
		return head;
	}

	/* 计算链表的长度 */
	int size() {
		Word* n = head->next;
		int count = 0;
		while (n) {
			n = n->next;
			count++;
		}
		return count;
	}

	/* 搜索第i个元素的地址 */
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

	/* 在最后面插入word */
	bool push(char* word) {
		Word* current = locate(size());
		if (!current) {
			return false; // 插入不成功
		}
		Word* newWord = current->insertAfter(word);
		return true;
	}

	/* 是否已经包含这个元素 */
	bool contains(char* word) {
		Word* n = head->next;
		while (n) {
			if (n->equals(word)) {
				n->addNum();	// 数量+1
				return true;
			}
			n = n->next;
		}
		return false;
	}

	/* 按频率降序排列，相同频率的按照字典序排列 */
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

	/* 交换两个word的值 */
	void swap(Word* word_1, Word* word_2) {
		char* temp_data = word_1->data;
		int temp_num = word_1->num;
		word_1->data = word_2->data;
		word_1->num = word_2->num;
		word_2->data = temp_data;
		word_2->num = temp_num;
	}

	/* 输出链表中的值 */
	void print() {
		Word* p = head;
		while (p->next) {
			p = p->next;
			cout << p->data << " " << p->num;
		}
		cout << endl;
	}
	
};
