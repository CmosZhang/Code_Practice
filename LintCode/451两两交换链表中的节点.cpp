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


//451. �������������еĽڵ�
//Time Limit Exceeded
//���ҳ��������������һ���µ�����
//�ҵ�ż������һ���µ�����
//Ȼ����ƴװ��һ���µ�����
//ListNode * swapPairs(ListNode * head) 
//{
//	// write your code here
//	ListNode *p1 = head;
//	ListNode *p2 = head->next;
//	ListNode *odd = new ListNode(0);
//	ListNode *even = new ListNode(0);
//	ListNode *odd_pre = odd;
//	ListNode *even_pre = even;
//	while (p1->next)
//	{
//		odd_pre->next = p1;
//		even_pre->next = p2;
//
//		odd_pre = odd_pre->next;
//		even_pre = even_pre->next;
//
//		p1 = p1->next->next;
//		if (p1 == NULL)
//		{
//			break;
//		}
//		p2 = p1->next;
//	}
//	if (p1 == NULL)
//	{
//		odd_pre->next = even->next;
//	}
//	else if (p1->next == NULL)
//	{
//		odd_pre->next = p1;
//		odd_pre = odd_pre->next;
//		
//
//	}
//	even_pre->next = NULL;
//
//	//cout << "list is:" << endl;
//	//print(p1);
//	//cout << "list is:" << endl;
//	//print(p2);
//
//
//	ListNode *p = odd->next, *q = even->next;
//	ListNode *dummy = new ListNode(0);
//	ListNode *s = dummy;
//	while (p&&q)
//	{
//		s->next = q;
//		s = s->next;
//		q = q->next;
//
//		s->next = p;
//		s = s->next;
//		p = p->next;
//	}
//	if (p)
//		s->next = p;
//	if (q)
//		s->next = q;
//	return dummy->next;
//}

//�����ύ����� 85.80% ���ύ!
ListNode * swapPairs(ListNode * head)
{
	// write your code here
	if (head == NULL)
	{
		return head;
	}
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *s = dummy;
	ListNode *p = head;//�����淽��������
	while (p!= NULL && p->next != NULL)
	{
		//�����ڵ�
		ListNode *temp = p->next;
		p->next = temp->next;
		temp->next = p;

		//���½ڵ�
		p = temp;
		s->next = p; //������������л������Ҫԭ������Ϊ�ı���ͷ���
		s = s->next->next;
		p = p->next->next;
	}
	return dummy->next;
}
/*
//�����ύ����� 85.80% ���ύ!
ListNode * swapPairs(ListNode * head) 
{
	// write your code here
	if (head == NULL)
	{
		return head;
	}
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *p = dummy;
	while (p->next != NULL && p->next->next != NULL)
	{
		//�����ڵ�
		ListNode *temp = p->next->next;
		p->next->next = temp->next;
		temp->next = p->next;

		//���½ڵ�
		p->next = temp;
		p = p->next->next;
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
	a = swapPairs(a);
	cout << "list is:" << endl;
	print(a);
	system("pause");
	return 0;
}