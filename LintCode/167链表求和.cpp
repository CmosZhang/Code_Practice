#include<iostream>
#include<vector>
#include<string>
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

//167. 链表求和
//您的提交打败了 93.00% 的提交!
ListNode * addLists(ListNode * l1, ListNode * l2) 
{
	// write your code here
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	ListNode *dummy = new ListNode(0);
	ListNode *s = dummy;
	int carry = 0;
	while (l1 != NULL && l2 != NULL)
	{
		int temp = (l1->val + l2->val + carry) % 10;
		ListNode *newNode = new ListNode(temp);
		s->next = newNode;
		s = s->next;
		carry = (l1->val + l2->val + carry) / 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1 == NULL)
	{
		while (l2 != NULL)
		{
			int temp = (l2->val + carry) % 10;
			ListNode *newNode = new ListNode(temp);
			s->next = newNode;
			s = s->next;
			carry = (l2->val + carry) / 10;
			l2 = l2->next;
		}
	}
	if (l2 == NULL)
	{
		while (l1 != NULL)
		{
			int temp = (l1->val + carry) % 10;
			ListNode *newNode = new ListNode(temp);
			s->next = newNode;
			s = s->next;
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
		}
	}
	if (carry)
	{
		int temp = (carry) % 10;
		ListNode *newNode = new ListNode(temp);
		s->next = newNode;
		s = s->next;
	}
	s->next = NULL;
	return dummy->next;
}