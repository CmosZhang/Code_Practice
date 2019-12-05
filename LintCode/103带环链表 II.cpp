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

//103 带环链表II
//您的提交打败了 90.60% 的提交!
ListNode *hasCycle(ListNode * head)
{
	// write your code here
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *pAhead = head->next;
	if (pAhead == NULL)
	{
		return NULL;
	}
	ListNode *pBhead = pAhead->next;
	while (pAhead != NULL && pBhead != NULL)
	{
		if (pAhead == pBhead)
		{
			return pBhead;
		}
		pAhead = pAhead->next;
		pBhead = pBhead->next;
		if (pBhead != NULL)
		{
			pBhead = pBhead->next;
		}
	}
	return NULL;
}

ListNode * detectCycle(ListNode * head) 
{
	ListNode *p = hasCycle(head);
	if (p == NULL)
	{
		return NULL;
	}
	int cycleNum = 1;
	ListNode *pNode1;
	while (pNode1->next != p)
	{
		cycleNum++;
		pNode1 = pNode1->next;
	}

	pNode1 = head;
	for (int i = 0; i < cycleNum; i++)
	{
		pNode1 = pNode1->next;
	}

	ListNode *pNode2 = head;
	while (pNode2 != pNode1)
	{
		pNode2 = pNode2->next;
		pNode1 = pNode1->next;
	}
	return pNode1;
}