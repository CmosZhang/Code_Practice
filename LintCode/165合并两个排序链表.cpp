#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode
{
	public:
		int val;
		ListNode *next;
		ListNode(int val)
		{
			this->val = val;
			this->next = NULL;	
		}
};

//165. 合并两个排序链表
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) 
{
	// write your code here
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode *p = NULL;
	if (l1->val <= l2->val)
	{
		p = l1;
		p->next = mergeTwoLists(l1->next,l2);
	}
	else
	{
		p = l2;
		p->next = mergeTwoLists(l1, l2->next);
	}
	return p;
}