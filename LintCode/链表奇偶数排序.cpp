#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//链表奇偶数排序
//
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int val) {
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
//第二种版本的归并算法：
//合并两个排序数组
ListNode*mergelist(ListNode*head1, ListNode*head2)
{
	ListNode* newhead = new ListNode(-1);
	ListNode* newtail = newhead;
	while (head1&&head2)
	{
		if (head1->val <= head2->val)
		{
			newtail->next = head1;
			head1 = head1->next;
		}
		else
		{
			newtail->next = head2;
			head2 = head2->next;
		}
		newtail = newtail->next;
		newtail->next = NULL;
	}
	if (head1)
	{
		newtail->next = head1;
	}
	if (head2)
	{
		newtail->next = head2;
	}
	return newhead->next;
}

//获取链表的中间节点
ListNode *getmidnode(ListNode*head)
{
	if (head == NULL)
	{
		return head;
	}
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *pre = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode *getmid(ListNode*head)
{
	ListNode* fast = head->next;
	ListNode* slow = head->next;
	ListNode* prev = head;
	while (true)
	{
		if (fast == NULL) break;
		fast = fast->next;
		if (fast == NULL) break;
		fast = fast->next;

		prev = slow;
		slow = slow->next;
	}
	prev->next = NULL; //将链表分为两段
	return slow;
}

//归并排序
ListNode* merge_sort(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* head1 = head;
	ListNode* head2 = getmid(head); //获取中间节点，将链表分为两段
	head1 = merge_sort(head1); //分别对两段链表进行排序
	head2 = merge_sort(head2);
	return mergelist(head1, head2); //将两段有序链表合并
}

//ListNode * oddEvenList(ListNode * head)
//{
//	if (head == NULL || head->next == NULL) {
//		return head;
//	}
//	ListNode *odd = new ListNode(0);
//	ListNode *even = new ListNode(0);
//	ListNode *odd_pre = odd;
//	ListNode *even_pre = even;
//	ListNode *p1 = head;
//	while (p1 != NULL) {
//		int value = p1->val;
//		if (value % 2 == 1) {
//			odd_pre->next = p1;
//			odd_pre = odd_pre->next;
//		}
//		else {
//			even_pre->next = p1;
//			even_pre = even_pre->next;
//		}
//		p1 = p1->next;
//	}
//	odd_pre->next = NULL;
//	even_pre->next = NULL;
//	ListNode* newodd = merge_sort(odd->next);
//	ListNode* neweven = merge_sort(even->next);
//	ListNode *temp = newodd;
//	while (temp->next != NULL){
//		temp = temp->next;
//	}
//	temp->next = neweven;
//	return odd->next;
//}


ListNode * insertionSortList(ListNode * head) {
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

ListNode * oddEvenList(ListNode * head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode *odd = new ListNode(0);
	ListNode *even = new ListNode(0);
	ListNode *odd_pre = odd;
	ListNode *even_pre = even;
	ListNode *p1 = head;
	while (p1 != NULL) {
		int value = p1->val;
		if (value % 2 == 1) {
			odd_pre->next = p1;
			odd_pre = odd_pre->next;
			odd->next = insertionSortList(odd->next);
		}
		else {
			even_pre->next = p1;
			even_pre = even_pre->next;
			even->next = insertionSortList(even->next);
		}
		p1 = p1->next;
	}
	odd_pre->next = NULL;
	even_pre->next = NULL;
	ListNode *temp = odd->next;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = even->next;
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
		int temp;
		cin >> temp;
		t->val = temp;
		t->next = a->next;
		a->next = t;
		//free(t);
	}
	cout << "list is:" << endl;
	print(a);
	r = oddEvenList(a->next);
	cout << "the result of list is:" << endl;
	print(r);

	system("pause");
	return 0;
}