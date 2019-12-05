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


ListNode * rotateRight(ListNode * head, int k) 
{
	// write your code here
	if (head == NULL || k <= 0)
	{
		return head;
	}
	int len = 1;
	//计算链表的长度。
	ListNode *temp = head;
	while (temp->next)
	{
		len++;
		temp = temp->next;
	}
	//cout << temp->val << endl;
	//cout << len << endl;
	k = k % len;
	if (k == 0)
	{
		return head;
	}
	ListNode *end = head;
	for (int i = 0; i < k; i++)
	{
		end = end->next;
	}
	ListNode *start = head;
	while (end->next)
	{
		start = start->next;
		end = end->next;
	}
	end->next = head;
	head = start->next;
	start->next = NULL;
	return head;
}

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
	int k = 3;
	ListNode *ans = rotateRight(a, 3);
	cout << "list is:" << endl;
	print(ans);
	system("pause");
	return 0;
}