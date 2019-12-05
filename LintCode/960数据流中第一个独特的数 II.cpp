#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

//960. �������е�һ�����ص��� II
//�����ύ����� 1.50% ���ύ!
//˼·��
//����������ظ���������ӵĹ����У��������ɾ��
class listnode {
public:
	int val;
	int count;
	listnode *next;
	listnode(int val, int count) {
		this->val = val;
		this->count = count;
		this->next = NULL;
	}
};

class DataStream {
public:

	DataStream() {
		// do intialization if necessary
		head = new listnode(-1, 1);
	}

	/**
	 * @param num: next number in stream
	 * @return: nothing
	 */
	void add(int num) {
		// write your code here
		if (head == NULL) {
			head = new listnode(num, 1);
			head->next = NULL;
			return;
		}
		listnode *p = head;
		listnode *q = head->next;
		bool no_flag = true;
		while (p != NULL && q != NULL) {
			if (q->val == num) {
				q->count++;
				no_flag = false;
				break;
			}
			p = q;
			q = q->next;
		}
		if (no_flag) {
			q = new listnode(num, 1);
			p->next = q;
		}
	}

	/**
	 * @return: the first unique number in stream
	 */
	int firstUnique() {
		// write your code here
		while (head->next != NULL) {
			if (head->next->count == 1) {
				return head->next->val;
			}
			head = head->next;
		}
		return -1;
	}
private:
	listnode *head = NULL;
};

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;	
	}
};

class DataStream {
public:

	DataStream() {
		// do intialization if necessary
		head = new ListNode(-1);
	}

	/**
	 * @param num: next number in stream
	 * @return: nothing
	 */
	void add(int num) {
		// write your code here
		if (head == NULL) {
			head = new ListNode(num);
			head->next = NULL;
			return;
		}
		ListNode *p = head;
		ListNode *q = head->next;
		while (p != NULL && q != NULL) {
			if (q->val == num) {
				q = q->next;
				p->next = q;
				return;
			}
			p = q;
			q = q->next;
		}
		q = new ListNode(num);
		p->next = q;
	}

	/**
	 * @return: the first unique number in stream
	 */
	int firstUnique() {
		// write your code here
		if (head->next != NULL) {
			return head->next->val;
		}
		return -1;
	}
private:
	ListNode *head = NULL;
};

int main() {
	DataStream s;
	s.add(1);
	s.add(2);
	cout << s.firstUnique() << endl;
	s.add(1);
	s.add(1);
	s.add(2);
	s.add(3);
	cout << s.firstUnique() << endl;
	system("pause");
	return 1;
}