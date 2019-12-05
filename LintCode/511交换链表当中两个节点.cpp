#include<iostream>
#include<vector>
#include<string>
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



//511. 交换链表当中两个节点
//您的提交打败了 95.80% 的提交!
//在链表中找到值v1的点，是否存在
//这种方法并没有交换链表的两个节点只是交换值
//这个题有个限制，v1在v2前面
bool findNode(ListNode *head, int v1)
{
	if (head == NULL)
	{
		return false;
	}
	while (head != NULL)
	{
		if (head->val != v1)
		{
			head = head->next;
		}
		else
		{
			return true;
		}
	}
	return false;

}
/*
ListNode * swapNodes(ListNode * head, int v1, int v2) 
{
	// write your code here
	if (head == NULL)
	{
		return NULL;
	}
	bool flag1 = findNode(head, v1);
	bool flag2 = findNode(head, v2);
	if (flag1 == false || flag2 == false)
	{
		return head;
	}
	while (head != NULL)
	{
		if (head->val == v1)
		{
			head->val = v2;
			head = head->next;
		}
		else if (head->val == v2)
		{
			head->val = v1;
			head = head->next;
		}
		else
		{
			head = head->next;
		}
	}
	return head;
}
*/

//您的提交打败了 100.00% 的提交!
ListNode * swapNodes(ListNode * head, int v1, int v2)
{
	// write your code here
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *pre = dummy;
	ListNode *pre1 = NULL, *pre2 = NULL;
	ListNode *p = head;
	//先找到这两个节点,pre1是v1的前向节点，pre2是v2的前向节点
	while (p != NULL)
	{
		if (p->val == v1 || p->val == v2)
		{
			if (pre1 == NULL)
			{
				pre1 = pre;
			}
			else if (pre2 == NULL)
			{
				pre2 = pre;
				break;
			}
		}
		pre = p;
		p = p->next;
	}
	//没有两个节点
	if (pre1 == NULL || pre2 == NULL) 
	{
		dummy->next =NULL;
		return head;
	}
	//两个节点都存在
	if (pre1->next == pre2)//两个节点相邻
	{
		ListNode *pNode = pre2->next;
		pre1->next = pNode;
		pre2->next = pNode->next;
		pNode->next = pre2;
	}
	else //两个节点不相邻
	{
		ListNode *pNode1 = pre1->next, *pNode2 = pre2->next;
		ListNode *pNext1 = pNode1->next, *pNext2 = pNode2->next;
		pre1->next = pNode2;
		pNode2->next = pNext1;
		pNode1->next = pNext2;
		pre2->next = pNode1;
	}
	return dummy->next;
}