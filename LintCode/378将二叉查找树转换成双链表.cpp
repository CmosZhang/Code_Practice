#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

class DoublyListNode
{
	public:
		int val;
		DoublyListNode *next, *prev;
		DoublyListNode(int val)
		{
			this->val = val;
			this->prev = this->next = NULL;
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


//378. 将二叉查找树转换成双链表
//您的提交打败了 69.80% 的提交!
void inorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	inorder_help(root->left, v);
	v.push_back(root->val);
	inorder_help(root->right, v);
}

DoublyListNode * bstToDoublyList(TreeNode * root) 
{
	// write your code here
	if (root == NULL)
	{
		return NULL;
	}
	vector<int > v;
	inorder_help(root, v);
	
	DoublyListNode *newHead = new DoublyListNode(0);
	DoublyListNode *p = newHead;

	for (int i = 0; i < v.size(); i++)
	{
		DoublyListNode *temp = p;
		p->next = new DoublyListNode(v[i]);
		p = p->next;
		p->prev = temp;
	}
	p = NULL;
	return newHead->next;
}