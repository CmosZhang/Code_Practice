#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stack>

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


//链表排序：
//最粗暴的方法：将链表弄成一个数组，对数组进行排序，排好序之后再生成一个链表。
//这种方式的时间复杂度为：O(n+nlgn+n),也就是O(nlgn),空间复杂度为O(n);

//但这种方法并不能让人满意
//链表版本的快排和归并排序时间复杂度为O(nlgn),空间复杂度为O(1);

//归并排序


//第一版本归并算法：
//合并两个排序数组
ListNode *MergeList(ListNode*head1, ListNode*head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	ListNode *newhead = NULL;
	if (head1->val < head2->val)
	{
		newhead = head1;
		newhead->next = MergeList(head1->next, head2);
	}
	else
	{
		newhead = head2;
		newhead->next = MergeList(head1, head2->next);
	}
	return newhead;
}

ListNode *MergeSort(ListNode*head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	//p1代表前半部分
	//p2代表翻转后的后半部分。
	ListNode *pNode1 = head;
	ListNode *pNode2 = head->next;
	while (pNode2&&pNode2->next)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next->next;
	}
	ListNode *p2 = pNode1->next;
	pNode1->next = NULL;
	ListNode *p1 = head;
	return MergeList(MergeSort(p1), MergeSort(p2));
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


//快排
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

ListNode *partion(ListNode*pBegin, ListNode*pEnd)
{
	if (pBegin == pEnd || pBegin->next == pEnd)
	{
		return pBegin;
	}
	int key = pBegin->val; //选择pBegin作为基准元素
	ListNode *p = pBegin, *q = pBegin;
	while (q != pEnd)//从pBegin开始向后进行一次遍历
	{
		if (q->val < key)
		{
			p = p->next;
			swap(&p->val, &q->val);
		}
		q = q->next;
	}
	swap(&p->val, &pBegin->val);
	return p;
}

void quick_sort(ListNode *pBegin, ListNode*pEnd)
{
	if (pBegin == pEnd || pBegin->next == pEnd)
	{
		return;
	}
	ListNode *mid = partion(pBegin, pEnd);
	quick_sort(pBegin, mid);
	quick_sort(mid->next, pEnd);
}

ListNode *sortList(ListNode*head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	quick_sort(head, NULL);
	return head;
}