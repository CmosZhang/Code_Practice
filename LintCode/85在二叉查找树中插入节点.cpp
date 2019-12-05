#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX  100

using namespace std;

//二叉树的储存结构
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

//85. 在二叉查找树中插入节点
//递归解法打败5.2%的提交。
//TreeNode * insertNode(TreeNode * root, TreeNode * node)
//{
//	// write your code here
//	//如果根节点为空。
//	if (root == NULL)
//	{
//		return node;
//	}
//	//
//	if (root->val > node->val)
//	{
//		root->left = insertNode(root->left, node);
//	}
//	else
//	{
//		root->right = insertNode(root->right, node);
//	}
//	return root;
//}

//非递归解法
//
TreeNode * insertNode(TreeNode * root, TreeNode * node)
{
	if (root == NULL)
	{
		return node;
	}
	TreeNode *temp = root;
	TreeNode *pre;
	while (temp)
	{
		pre = temp;
		if (temp->val > node->val)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	//插入结点
	if (pre->val > node->val)
		pre->left = node;
	if (pre->val <= node->val)
		pre->right = node;
	return root;
}

//87. 删除二叉查找树的节点
//递归解法
//
//TreeNode * removeNode(TreeNode * root, int value) 
//{
//	// write your code here
//	if (root == NULL)
//	{
//		return root;
//	}
//	if (root->val > value)
//	{
//		root->left = removeNode(root->left, value);
//	}
//	else if (root->val < value)
//	{
//		root->right = removeNode(root->right, value);
//	}
//	else
//	{
//		if (root->left == NULL || root->right == NULL)
//		{
//			root = (root->left != NULL) ? root->left : root->right;
//		}
//		else 
//		{
//			TreeNode *cur = root->right;
//			while (cur->left != NULL) 
//			{
//				cur = cur->left;
//			}
//			root->val = cur->val;
//			root->right = removeNode(root->right, cur->val);
//		}
//	}
//	return root;
//}


//非递归解法
//存在问题，40%的时候没有通过测试数据。
//您的提交打败了 75.20% 的提交!
TreeNode * removeNode(TreeNode * root, int value)
{
	if (root == NULL)
	{
		return root;
	}
	TreeNode *cur = root;
	TreeNode *parent = root, *del = NULL;
	while (cur)
	{
		if (cur->val > value)
		{
			parent = cur;
			cur = cur->left;
		}
		else if (cur->val < value)
		{
			parent = cur;
			cur = cur->right;
		}
		else
		{
			del = cur; //要删除的节点。 parent 要删除节点的父节点。
			if (cur->left == NULL) //左孩子为空
			{
				if (parent->left == cur)
				{
					parent->left = cur->right;
				}
				else if (parent->right == cur)
				{
					parent->right = cur->right;
				}
				else
				{
					root = parent->right; //删除的节点是根节点
				}
			}
			else if (cur->right == NULL) //右孩子为空
			{
				if (parent->left == cur)
				{
					parent->left = cur->left;
				}
				else if (parent->right == cur)
				{
					parent->right = cur->left;
				}
				else
				{
					root = parent->left; //删除的节点是根节点。
				}
			}
			else //左右孩子都不为空
			{
				TreeNode *temp = cur->right;
				while (temp->left)//这一不容易出问题。
				{
					parent = temp;
					temp = temp->left;
				}
				del = temp;
				cur->val = temp->val;
				if (parent->left == temp) //如果这个最小的节点是左节点，指向为空，temp->right为空
				{
					parent->left = temp->right; 
				}
				else
				{
					parent->right = temp->right;
				}
			}
			free(del);
		}
	}
	return root;
}