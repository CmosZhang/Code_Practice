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

TreeNode *FindMin(TreeNode *root)
{
	if (root == NULL)
	{
		return root;
	}
	else if (root->left == NULL)
	{
		return root;
	}
	else
	{
		return FindMin(root->left);
	}
}


//87. 删除二叉查找树的节点
//您的提交打败了 0.00% 的提交!
//删除节点的递归版本
TreeNode * removeNode(TreeNode * root, int value) {
	// write your code here
	TreeNode *Node;
	if (root == NULL)
	{
		return root;
	}
	if (value < root->val)
	{
		root->left = removeNode(root->left, value);
	}
	else if (value > root->val)
	{
		root->right = removeNode(root->right, value);
	}
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			TreeNode *tmp = FindMin(root->right);
			root->val = tmp->val;
			root->right = removeNode(root->right, tmp->val);
		}
		else
		{
			Node = root;
			if (root->left == NULL)
			{
				root = root->right;
			}
			else if(root->right==NULL)
			{
				root = root->left;
			}
			free(Node);
		}
	}
	return root;
}


//非递归版本
//您的提交打败了 10.40% 的提交!
//用递归的方式求解比较简单，而且容易理解
TreeNode* removeNode(TreeNode* root, int value) {
	// write your code here
	if (root == NULL)
		return NULL;
	TreeNode * head = new TreeNode(0);
	head->left = root;
	TreeNode * tmp = root, *father = head;

	//先确定要删除节点的位置
	while (tmp != NULL) {
		if (tmp->val == value)
			break;
		father = tmp;
		if (tmp->val > value)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	if (tmp == NULL)
		return head->left;

	//被删除节点的右子树是空
	if (tmp->right == NULL) {
		if (father->left == tmp)
			father->left = tmp->left;
		else
			father->right = tmp->left;
	}
	else
		if (tmp->right->left == NULL) {//被删除节点的右子树中的最小值
			if (father->left == tmp)
				father->left = tmp->right;
			else
				father->right = tmp->right;

			tmp->right->left = tmp->left;

		}
		else {
			father = tmp->right;
			TreeNode * cur = tmp->right->left;
			while (cur->left != NULL) {
				father = cur;
				cur = cur->left;
			}
			tmp->val = cur->val;
			father->left = cur->right;
		}
		return head->left;
}
