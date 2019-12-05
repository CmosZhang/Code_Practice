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



//511. ���������������ڵ�
//�����ύ����� 95.80% ���ύ!
//���������ҵ�ֵv1�ĵ㣬�Ƿ����
//���ַ�����û�н�������������ڵ�ֻ�ǽ���ֵ
//������и����ƣ�v1��v2ǰ��
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

//�����ύ����� 100.00% ���ύ!
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
	//���ҵ��������ڵ�,pre1��v1��ǰ��ڵ㣬pre2��v2��ǰ��ڵ�
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
	//û�������ڵ�
	if (pre1 == NULL || pre2 == NULL) 
	{
		dummy->next =NULL;
		return head;
	}
	//�����ڵ㶼����
	if (pre1->next == pre2)//�����ڵ�����
	{
		ListNode *pNode = pre2->next;
		pre1->next = pNode;
		pre2->next = pNode->next;
		pNode->next = pre2;
	}
	else //�����ڵ㲻����
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