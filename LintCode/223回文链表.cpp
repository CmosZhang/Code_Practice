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

//223. ��������
//�����ύ����� 100.00% ���ύ!
ListNode *reverseList(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *pNode = head;
	ListNode *pPre = NULL;
	ListNode *pNewhead = NULL;
	while (pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		if (pNext == NULL)
		{
			pNewhead = pNode;
		}
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return pNewhead;
}

bool isPalindrome(ListNode * head)
{
	// write your code here
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	//p1����ǰ�벿��
	//p2����ת��ĺ�벿�֡�
	ListNode *pNode1 = head;
	ListNode *pNode2 = head->next;
	while (pNode2 &&pNode2->next)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next->next;
	}
	ListNode *p2 = pNode1->next;
	pNode1->next = NULL;
	ListNode *p1 = head;
	p2 = reverseList(p2);

	while (p2&&p1)
	{
		if (p1->val != p2->val)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}