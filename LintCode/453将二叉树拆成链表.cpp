#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

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

//453. ���������������
//
TreeNode *head = NULL;
TreeNode *realhead = NULL;
void preorder_help(TreeNode *root)
{
	if (!root)return;
	if (head == NULL)
	{
		head = root;
		realhead = root;
	}
	else
	{
		head->right = root;
		head = head->right;//
		//head->left = NULL;//��Ӧ�������⣬��Ϊ��������������Ϊ�գ����ͻ��������
	}
	preorder_help(root->left);
	preorder_help(root->right);
}

void flatten(TreeNode * root) 
{
	// write your code here
	if (root == NULL)
	{
		return;
	}
	preorder_help(root);
	root = realhead;
	while (realhead)
	{
		realhead->left = NULL;
		realhead = realhead->right;
	}
}



//�����ύ����� 85.60% ���ύ!
/*
void flatten(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
	   return;
	}
	switchToLink(root);
}

TreeNode* switchToLink(TreeNode* root)
{
	if (root == NULL)
	{
	   return NULL;
	}

	TreeNode* left = switchToLink(root->left);
	TreeNode* right = switchToLink(root->right);

	if (left != NULL)
	{
	   left->right = root->right;
	   root->right = root->left;
	}

	root->left = NULL;

	if (right != NULL)
	{
	    return right;
	}
	else if (left != NULL)
	{
	    return left;
	}
	else 
	{
	    return root;
	}
}
*/