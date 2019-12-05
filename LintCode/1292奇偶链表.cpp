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

//1292. 奇偶链表
//您的提交打败了 100.00% 的提交!
ListNode * oddEvenList(ListNode * head) 
{
	// write your code here
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
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
		odd_pre->next = even->next;
		even_pre->next = NULL;
	}
	//cout << "list is:" << endl;
	//print(odd->next);
	//cout << "list is:" << endl;
	//print(even->next);
	return odd->next;
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
	a = oddEvenList(a);
	cout << "list is:" << endl;
	print(a);
	system("pause");
	return 0;
}