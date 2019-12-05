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

//102. ��������
//�����ύ����� 90.60% ���ύ!
bool hasCycle(ListNode * head)
{
	// write your code here
	if (head == NULL)
	{
		return false;
	}
	ListNode *pAhead = head->next;
	if (pAhead == NULL)
	{
		return false;
	}
	ListNode *pBhead = pAhead->next;
	while (pAhead != NULL && pBhead != NULL)
	{
		if (pAhead == pBhead)
		{
			return true;
		}
		pAhead = pAhead->next;
		pBhead = pBhead->next;
		if (pBhead != NULL)
		{
			pBhead = pBhead->next;
		}
	}
	return false;
}