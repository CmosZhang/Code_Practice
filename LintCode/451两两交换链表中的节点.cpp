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


//451. 两两交换链表中的节点
//Time Limit Exceeded
//先找出链表的奇数项，组成一个新的链表
//找到偶数项，组成一个新的链表，
//然后在拼装成一个新的链表
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

//您的提交打败了 85.80% 的提交!
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
	ListNode *p = head;//与下面方法的区别
	while (p!= NULL && p->next != NULL)
	{
		//交换节点
		ListNode *temp = p->next;
		p->next = temp->next;
		temp->next = p;

		//更新节点
		p = temp;
		s->next = p; //如果不加这两行会出错，主要原因是因为改变了头结点
		s = s->next->next;
		p = p->next->next;
	}
	return dummy->next;
}
/*
//您的提交打败了 85.80% 的提交!
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
		//交换节点
		ListNode *temp = p->next->next;
		p->next->next = temp->next;
		temp->next = p->next;

		//更新节点
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