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



//380. 两个链表的交叉
//您的提交打败了 23.60% 的提交!
int getListLength(ListNode *head)
{
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}
//ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
//{
//	// write your code here
	//if (headA == NULL || headB == NULL)
	//{
	//	return NULL;
	//}
	////得到链表的长度
	//int Alen = getListLength(headA);
	//int Blen = getListLength(headB);
	//int lenDif = Alen - Blen;


	//ListNode *listlong = headA;
	//ListNode *listshort = headB;

	//if (Alen - Blen < 0)
	//{
	//	listlong = headB;
	//	listshort = headA;
	//	lenDif = Blen - Alen;
	//}

	////先在长链表上走几步，在同时遍历
	//for (int i = 0; i < lenDif; i++)
	//{
	//	listlong = listlong->next;
	//}

	////找相同
	//while (listlong != NULL && listshort != NULL && listlong != listshort)
	//{
	//	listlong = listlong->next;
	//	listshort = listshort->next;
	//}

	//ListNode *same = listlong;
	//return same;
//}

//方法二
//利用栈
//您的提交打败了 19.80% 的提交!
ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
{
	// write your code here
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	stack<ListNode*> A;
	while (headA != NULL)
	{
		A.push(headA);
		headA = headA->next;
	}
	stack<ListNode*> B;
	while (headB != NULL)
	{
		B.push(headB);
		headB = headB->next;
	}
	ListNode *topA = NULL;
	ListNode *topB = NULL;
	while (!A.empty() && !B.empty())
	{
		topA = A.top();
		topB = B.top();
		if (topA != topB)
		{
			break;
		}
		A.pop();
		B.pop();
	}
	ListNode *FirstCommon = NULL;
	if (A.empty())
	{
		FirstCommon = topA;
	}
	else
	{
		if (B.empty())
		{
			FirstCommon = topB;
		}
		else
		{
			FirstCommon = topA->next;
		}
	}
	return FirstCommon;
}