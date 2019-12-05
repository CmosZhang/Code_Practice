#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

class ListNode
{
    public:
		int val;
		struct ListNode *next;
		ListNode(int val)
		{
			this->val = val;
			this->next = NULL;
		}
};

class TreeNode
{
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val)
		{
			this->val = val;
			this->left = this->right = NULL;

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

//106. ��������ת��Ϊ���ֲ�����
//
TreeNode * sortedListToBST(ListNode * head) 
{
	// write your code here
	if (head == NULL )
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		TreeNode* root = new TreeNode(head->val);
		return root;
	}
	//p1����ǰ�벿��
	//p2����ת��ĺ�벿�֡�
	//ListNode *pNode1 = head;
	//ListNode *pNode2 = head->next;
	//ListNode *pNode3 = pNode1;
	//while (pNode2 &&pNode2->next)
	//{
	//	pNode3 = pNode1;
	//	pNode1 = pNode1->next;
	//	pNode2 = pNode2->next->next;
	//}
	//int gen = pNode1->val;
	//pNode2 = pNode1->next;
	//pNode1->next = NULL;
	////pNode1 = head;
	//pNode3->next = NULL;
	//cout << "list is:" << endl;
	//print(pNode1);

	//cout << "list is:" << endl;
	//print(pNode2);
	//cout << pNode1->val << endl;
	//TreeNode *root = new TreeNode(gen);
	//root->left = sortedListToBST(pNode1);
	//root->right = sortedListToBST(pNode2);
	//return root;
	ListNode* before = head;   //��¼��ѡ���ĸ��ڵ��ǰһ���ڵ㣬������潫����Ͽ���Ȼ��ݹ�
	ListNode* slow = head->next;
	ListNode* fast = head->next->next;
	while (fast != NULL && fast->next != NULL)
	{  //����ָ�����������ѡ���е�ڵ㣬slowָ��Ľڵ�
		before = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	before->next = NULL;             //�Ͽ����ڵ���ߵ�����
	TreeNode* root = new TreeNode(slow->val);  //�������ڵ㣬 ���ݹ鹹����������
	//cout << "list is:" << endl;
	//print(head);
	//cout << "list is:" << endl;
	//print(slow->next);
	//cout << slow->val << endl;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(slow->next);
	return root;
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
	//reorderList(a);
	//cout << "list is:" << endl;
	//print(a);
	//a = sortList2(a);
	//cout << "list is:" << endl;
	//print(a);
	TreeNode *ans=NULL;
	cout << !ans << endl;
	ans = sortedListToBST(a);
	system("pause");
	return 0;
}