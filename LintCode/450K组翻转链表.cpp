#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};

ListNode *print(ListNode *head)
{
	ListNode *p;
	p = head;
	if (head != NULL)
	{
		do
		{
			cout << p->val << ",";
			p = p->next;
		} while (p != NULL);
	}
	cout << endl;
	return 0;
}


//450. K�鷭ת����
//������ֳ�K�ݣ�Ȼ����Է�ת����󽫷�ת��������������
//������Ȳ���K,����Ҫ��ת��

//��ȡ������
int getListLength(ListNode *head)
{
	if (head == NULL)
	{
		return 0;
	}
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

//��ת����
ListNode *reverse(ListNode *head)
{
	ListNode *dummy = NULL;
	while (head != NULL)
	{
		ListNode *temp = head->next;
		head->next = dummy;
		dummy = head;
		head = temp;
	}
	return dummy;
}

//�����ύ����� 87.00% ���ύ!
ListNode * reverseKGroup(ListNode * head, int k)
{
	// write your code here
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	int len = getListLength(head);
	if (len < k)
	{
		return head;
	}

	int seg = len / k;//�����ֳܷɼ�������

	ListNode *p = head;
	ListNode *dummy = new ListNode(0);
	ListNode *pNode = dummy;

	while (seg)
	{
		for (int i = 1; i < k; i++)
		{
			head = head->next;
		}
		ListNode *nextHead = head->next;
		head->next = NULL;
		ListNode *temp = reverse(p);
		pNode->next = temp;
		pNode = p;//p�ڷ�ת֮���Ѿ�����ĩβ��
		p = nextHead;
		head = p;
		seg--;
	}
	pNode->next = head;
	return dummy->next;
}

/*
//���������
//�����ύ����� 98.60% ���ύ!
ListNode * reverseKGroup(ListNode * head, int k)
{
	// write your code here
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	ListNode *p = head;
	ListNode *dummy = new ListNode(0);
	ListNode *pNode = dummy;

	while (head != NULL)
	{
		int listSize = 0;
		while (listSize < k - 1 && head != NULL)
		{
			listSize++;
			head = head->next;
		}
		if (head != NULL)
		{
			ListNode *nextHead = head->next;
			head->next = NULL;
			ListNode *temp = reverse(p);
			pNode->next = temp;
			pNode = p;//p�ڷ�ת֮���Ѿ�����ĩβ��
			p = nextHead;
			head = p;
		}
		else
		{
			pNode->next = p;
		}
	}
	return dummy->next;
}
*/


int main()
{
	ListNode *a = (ListNode*)malloc(sizeof(ListNode));
	ListNode *r = (ListNode*)malloc(sizeof(ListNode));
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	a->val = 0;
	a->next = NULL;
	for (int i = 6; i >= 1; i--)
	{
		ListNode* t = (ListNode*)malloc(sizeof(ListNode));
		t->val = i;
		t->next = a->next;
		a->next = t;
		//free(t);
	}
	cout << "list is:" << endl;
	print(a);
	//ListNode *p1;
	//ListNode *p2;
	int k = 3;
	a = reverseKGroup(a,k);
	cout << "list is:" << endl;
	print(a);
	system("pause");
	return 0;
}