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


//35. 翻转链表
ListNode *reverse(ListNode *head)
{
	ListNode *dummy = NULL;
	while (head != NULL)
	{
		ListNode *temp = head->next;
		head->next = dummy;
		dummy = head;
		head = temp;
	}
	return dummy;
}

ListNode *print(ListNode *head)   
{    
	 ListNode *p;    
	 p=head;    
	 if(head!=NULL)    
	 {        
		 do        
		 {      
			 cout << p->val << "," ;        
			 p=p->next;        
		 }while(p!=NULL);    
	 }
	 cout << endl;
	 return 0;
}

//372. 在O(1)时间复杂度删除链表节点
void deleteNode(ListNode * node)
{
	node->val = node->next->val;
	ListNode *tmp = node->next;
	node->next = tmp->next;
	delete tmp;
}

ListNode *add(ListNode *head,ListNode *insert)//插入一个新节点
{
	ListNode *p, *next;
	p = head->next;
	while (p ->val > insert ->val)
	{
		p = p->next;
	}
	next = p->next;
	p->next = insert;
	insert->next = next;
	return head;
}

ListNode *del(ListNode *head, int x) //删除数值为a的节点
{
	ListNode *p, *next, *pre = NULL;
	p = head;
	while (p->val != x)
	{
		pre = p;
		p = p->next;
	}
	next = p->next;
	pre->next = next;
	delete p;
	return head;
}

//174. 删除链表中倒数第n个节点
ListNode *removeNthFromEnd(ListNode * head, int n) //删除链表倒数第n个节点
{
	ListNode *p, *pp, *pre = NULL, *next;
	p = head;
	pp = head;
	int length = 0;
	while (pp != NULL) //链表长度
	{
		length++;
		pp = pp->next;
	}
	if (n > length || n <= 0)
	{
		return head;
	}
	else if (n == length)
	{
		return head->next;
	}
	else
	{
		int k = length - n;
		while (k != 0)
		{
			pre = p;
			p = p->next;
			k--;
		}
		next = p->next;
		pre->next = next;
		delete p;
		return head;
	}
}

//96. 链表划分
ListNode * partition(ListNode * head, int x)
{
	//给定一个单链表和数值x，划分链表使得所有小于x的节点排在大于等于x的节点之前。
	if (head == NULL)
	{
		return 0;
	}
	ListNode *p = head;
	ListNode *lefthead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *righthead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *right = righthead, *left = lefthead;
	while (p != NULL) 
	{
		if (p->val < x)
		{
			left->next = p;
			left = p;
		}
		else
		{
			right->next = p;
			right = p;
		}
		p = p->next;
	}
	right->next = NULL;
	left->next = righthead->next;
	head = lefthead;
	free(lefthead);
	free(righthead);
	return head;  //有时候要看题目要求，看输出的时候是否包含头节点。
	// return head->next;
}

//36. 翻转链表 II
ListNode * reverseBetween(ListNode * head, int m, int n)
{
	//翻转链表中第m个节点到第n个节点的部分 并没有达到具体要求。没有原地一次翻转成功
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *p, *pre = NULL;
	p = head;
	ListNode *dummy;
	dummy = head;
	for (int i = 0; i < m; i++)
	{
		pre = p;
		p = p->next;
	}
	ListNode *temp;
	for (int j = m; j < n; j++)
	{
		temp = p->next;//找到m的next
		p->next = temp->next; //将m的next设为m的next的next
		temp->next = pre->next;//将m的next插入pre和pre的next之间
		pre->next = temp;
	}
	return dummy;

	// 下面这种方法，会节约空间。在原地一次翻转完成。
	//if (!head || !head->next || n == m)
	//	return head;    //将p转移到链表的第m个节点，pre保存m前一个节点    
	//struct ListNode* pre = NULL;
	//struct ListNode* p = head;
	//int temp_m = m;
	//while (temp_m-- > 1)
	//{
	//	pre = p;
	//	p = p->next;
	//}    //接下来是反转操作，reverse_head，reverse_tail，reverse_tail_after分别存储反转链表的头部，尾部节点，尾部节点后一个节点(可能为NULL)，为了之后的连接    
	//struct ListNode* reverse_head = NULL;
	//struct ListNode* reverse_tail = p;
	//struct ListNode* reverse_tail_after = NULL;
	//struct ListNode* q = NULL;
	//int temp_n = n;
	//while (temp_n - m > 0)
	//{
	//	q = p->next;
	//	reverse_tail_after = q->next;
	//	p->next = reverse_head;
	//	reverse_head = p;
	//	p = q;	
	//  temp_n--;
	//}
	//p->next = reverse_head;
	//reverse_head = p;    //接下来建立头部和反转部分的连接   
	//if (m == 1)
	//{	//反转链表的head就是链表的head	
	//	head = reverse_head;
	//}
	//else
	//{	//用pre将正序头部和反转链表连接	
	//	pre->next = reverse_head;
	//}    //接下来建立反转部分和尾部的连接    
	//if (reverse_tail_after)
	//{
	//	reverse_tail->next = reverse_tail_after;
	//}
	//return head;
}

//112. 删除排序链表中的重复元素
ListNode * deleteDuplicates(ListNode * head) 
{
	// write your code here
	// 删除排序链表中重复的元素，重复的元素是放在一起的，不是分开存储的。
	// 例如链表：1，2，2，4，5，6。 或者，6，4，4，5，3。
	// 这个代码只能解决重复元素存放在一起的情况。
	// 给定一个排序链表，删除所有重复的元素每个元素只留下一个。
	if (head == NULL)
	{
		return head;
	}
	ListNode *p = head;
	ListNode *temp;
	while (p != NULL)
	{
		temp = p->next;
		if (temp != NULL && p->val == temp->val)
		{
			p->next = temp->next;
		}
		else
		{
			p = p->next;
		}
	}
	return head;
}

//113. 删除排序链表中的重复数字 II
//您的提交打败了 83.40% 的提交!
//创建一个新的链表，起个过渡作用。
ListNode * deleteDuplicates2(ListNode * head)
{
	// write your code here
	double temp = 1.2;
	ListNode *dummy = new ListNode(0);
	ListNode *s = dummy;
	if (head == NULL)
		return head;
	ListNode *p = head;
	while (p != NULL && p->next != NULL)
	{
		if (p->val == p->next->val)
			temp = p->val;
		if (p->val != temp)
		{
			ListNode *pre = new ListNode(p->val);
			s->next = pre;
			s = s->next;
		}
		p = p->next;
	}
	if (p->val != temp)
	{
		ListNode *pre = new ListNode(p->val);
		s->next = pre;
		s = s->next;
	}
	return dummy->next;
}

//ListNode * insertionSortList(ListNode * head) 
//{
//	// write your code here
//	// 用插入排序对链表排序
//	if (head == NULL)
//	{
//		return 0;
//	}
//	ListNode *p = head;
//	ListNode *pp = head;
//	//int length = 0;
//	//while (pp != NULL) //链表长度
//	//{
//	//	length++;
//	//	pp = pp->next;
//	//}
//	ListNode *temp;
//	while (p != NULL)
//	{
//
//	}
//	return head;
//}






int main()
{
	ListNode *a = (ListNode*)malloc(sizeof(ListNode));
	ListNode *r = (ListNode*)malloc(sizeof(ListNode));
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	a->val = 0;
	a->next = NULL;
	for (int i = 6; i >=1 ; i--)
	{
		ListNode* t = (ListNode*)malloc(sizeof(ListNode));
		t->val = i;
		t->next = a->next;
		a->next = t;
		//free(t);
	}

	cout << "list is:" << endl;
	print(a);
	r = reverse(a);
	cout << "the reverse of list is:" << endl;
	print(r);
	ListNode *ins = (ListNode*)malloc(sizeof(ListNode));
	ins->val = 2;
	ins->next = NULL;
	cout << "add a node:" << endl;
    r = add(a,ins);
	
	print(r);
	//free(ins);
	//int x = 4;
	//s = del(a, x);
	//cout << "delete a node:" << endl;
	//print(s);
	//int n = 3;
	//s = removeNthFromEnd(a, n);
	//cout << "list after removeNthFromEnd:" << endl;
	//print(s);
	//cout << "deletenode:" << endl;
	//deleteNode(ins);
	//print(s);

	cout << "list after reverseBetween:" << endl;
	reverseBetween(r, 2, 4);
	print(r);
	cout << "list after partition :" << endl;
	partition(r, 4);
	print(r);	

	cout << "list after deleteDuplicates2 :" << endl;
	ListNode *dummy = new ListNode(0);
	dummy = deleteDuplicates2(r);
	print(dummy);
	system("pause");
	return 0;
}