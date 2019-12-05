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

ListNode *print(ListNode *head)
{
	ListNode *p;
	p = head;
	if (head != NULL)
	{
		do
		{
			cout << p->val << ",";
			p = p->next;
		} while (p != NULL);
	}
	cout << endl;
	return 0;
}


//99. 重排链表
//您的提交打败了 85.80% 的提交!
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



//找中间节点。翻转后半部分的节点。
void reorderList(ListNode * head)
{
	if (head == NULL)
	{
		return;
	}
	//p1代表前半部分
	//p2代表翻转后的后半部分。
	//ListNode *pNode1 = head;
	//ListNode *pNode2 = head->next;
	//while (pNode2 &&pNode2->next)
	//{
	//	pNode1 = pNode1->next;
	//	pNode2 = pNode2->next->next;
	//}
	//ListNode *p2 = pNode1->next;
	//pNode1->next = NULL;
	//ListNode *p1 = head;
	//p2 = reverseList(p2);

	//cout << "list is:" << endl;
	//print(p1);
	//cout << "list is:" << endl;
	//print(p2);
	ListNode *p1 = head;
	ListNode *p2 = head->next;
	ListNode *odd = new ListNode(0);
	ListNode *even = new ListNode(0);
	ListNode *odd_pre = odd;
	ListNode *even_pre = even;
	while (p1->next)
	{
		odd_pre->next = p1;
		even_pre->next = p2;

		odd_pre = odd_pre->next;
		even_pre = even_pre->next;

		p1 = p1->next->next;
		if (p1 == NULL)
		{
			break;
		}
		p2 = p1->next;
	}
	if (p1 == NULL)
	{
		odd_pre->next = even->next;
	}
	else if (p1->next == NULL)
	{
		odd_pre->next = p1;
		odd_pre = odd_pre->next;
		//odd_pre->next = even->next;
		
	}
	even_pre->next = NULL;
	cout << "list is:" << endl;
	print(odd->next);
	cout << "list is:" << endl;
	print(even->next);

	ListNode *p = p1->next, *s = head, *q = p2;
	while (p&&q)
	{
		s->next = q;
		s = s->next;//此处是s=s->next,不是s=q,容易出错
		q = q->next;

		s->next = p;
		s = s->next;//同上
		p = p->next;
	}
	if (p)
	{
		s->next = p;
	}
	if (q)
	{
		s->next = q;
	}
	//cout << "list is:" << endl;
	//print(head);
}



int main()
{
	ListNode *a = (ListNode*)malloc(sizeof(ListNode));
	ListNode *r = (ListNode*)malloc(sizeof(ListNode));
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	a->val = 0;
	a->next = NULL;
	for (int i = 6; i >= 1; i--)
	{
		ListNode* t = (ListNode*)malloc(sizeof(ListNode));
		t->val = i;
		t->next = a->next;
		a->next = t;
		//free(t);
	}
	cout << "list is:" << endl;
	print(a);
	//ListNode *p1;
	//ListNode *p2;
	reorderList(a);
	cout << "list is:" << endl;
	print(a);
	system("pause");
	return 0;
}