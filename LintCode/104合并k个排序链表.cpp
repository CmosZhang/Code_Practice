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



//104. 合并k个排序链表
//您的提交打败了 9.00% 的提交!
ListNode *mergeLists(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	ListNode *head = NULL;
	if (p1->val < p2->val)
	{
		head = p1;
		head->next = mergeLists(p1->next,p2);
	}
	else
	{
		head = p2;
		head->next = mergeLists(p1, p2->next);
	}
	return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists) 
{
	// write your code here
	if (lists.empty())
	{
		return NULL;
	}
	int len = lists.size();
	ListNode *head = NULL;
	for (int i = 0; i < len; i++)
	{
		head = mergeLists(head,lists[i]);
	}
	return head;
}