#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

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


//173. 链表插入排序
//您的提交打败了 99.40% 的提交!
ListNode * insertionSortList(ListNode * head)
{
	// write your code here
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *newhead = new ListNode(0);
	ListNode *pNode = head;
	while (pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		ListNode *temp = newhead;
		while (temp->next != NULL && temp->next->val < pNode->val)
		{
			temp = temp->next;
		}
		pNode->next = temp->next;
		temp->next = pNode;
		pNode = pNext;
	}
	return newhead->next;
}