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


//35. ��ת����
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

//372. ��O(1)ʱ�临�Ӷ�ɾ������ڵ�
void deleteNode(ListNode * node)
{
	node->val = node->next->val;
	ListNode *tmp = node->next;
	node->next = tmp->next;
	delete tmp;
}

ListNode *add(ListNode *head,ListNode *insert)//����һ���½ڵ�
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

ListNode *del(ListNode *head, int x) //ɾ����ֵΪa�Ľڵ�
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

//174. ɾ�������е�����n���ڵ�
ListNode *removeNthFromEnd(ListNode * head, int n) //ɾ����������n���ڵ�
{
	ListNode *p, *pp, *pre = NULL, *next;
	p = head;
	pp = head;
	int length = 0;
	while (pp != NULL) //������
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

//96. ������
ListNode * partition(ListNode * head, int x)
{
	//����һ�����������ֵx����������ʹ������С��x�Ľڵ����ڴ��ڵ���x�Ľڵ�֮ǰ��
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
	return head;  //��ʱ��Ҫ����ĿҪ�󣬿������ʱ���Ƿ����ͷ�ڵ㡣
	// return head->next;
}

//36. ��ת���� II
ListNode * reverseBetween(ListNode * head, int m, int n)
{
	//��ת�����е�m���ڵ㵽��n���ڵ�Ĳ��� ��û�дﵽ����Ҫ��û��ԭ��һ�η�ת�ɹ�
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
		temp = p->next;//�ҵ�m��next
		p->next = temp->next; //��m��next��Ϊm��next��next
		temp->next = pre->next;//��m��next����pre��pre��next֮��
		pre->next = temp;
	}
	return dummy;

	// �������ַ��������Լ�ռ䡣��ԭ��һ�η�ת��ɡ�
	//if (!head || !head->next || n == m)
	//	return head;    //��pת�Ƶ�����ĵ�m���ڵ㣬pre����mǰһ���ڵ�    
	//struct ListNode* pre = NULL;
	//struct ListNode* p = head;
	//int temp_m = m;
	//while (temp_m-- > 1)
	//{
	//	pre = p;
	//	p = p->next;
	//}    //�������Ƿ�ת������reverse_head��reverse_tail��reverse_tail_after�ֱ�洢��ת�����ͷ����β���ڵ㣬β���ڵ��һ���ڵ�(����ΪNULL)��Ϊ��֮�������    
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
	//reverse_head = p;    //����������ͷ���ͷ�ת���ֵ�����   
	//if (m == 1)
	//{	//��ת�����head���������head	
	//	head = reverse_head;
	//}
	//else
	//{	//��pre������ͷ���ͷ�ת��������	
	//	pre->next = reverse_head;
	//}    //������������ת���ֺ�β��������    
	//if (reverse_tail_after)
	//{
	//	reverse_tail->next = reverse_tail_after;
	//}
	//return head;
}

//112. ɾ�����������е��ظ�Ԫ��
ListNode * deleteDuplicates(ListNode * head) 
{
	// write your code here
	// ɾ�������������ظ���Ԫ�أ��ظ���Ԫ���Ƿ���һ��ģ����Ƿֿ��洢�ġ�
	// ��������1��2��2��4��5��6�� ���ߣ�6��4��4��5��3��
	// �������ֻ�ܽ���ظ�Ԫ�ش����һ��������
	// ����һ����������ɾ�������ظ���Ԫ��ÿ��Ԫ��ֻ����һ����
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

//113. ɾ�����������е��ظ����� II
//�����ύ����� 83.40% ���ύ!
//����һ���µ���������������á�
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
//	// �ò����������������
//	if (head == NULL)
//	{
//		return 0;
//	}
//	ListNode *p = head;
//	ListNode *pp = head;
//	//int length = 0;
//	//while (pp != NULL) //������
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