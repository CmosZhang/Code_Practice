#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

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

//375. 克隆二叉树
//您的提交打败了 97.60% 的提交!
//没有意义
//TreeNode * cloneTree(TreeNode * root)
//{
//	// write your code here
//	return root;
//}

//您的提交打败了 84.00% 的提交!
//使用递归的方法
TreeNode * cloneTree(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return root;
	}
	int temp = root->val;
	TreeNode *t = new TreeNode(temp);
	if (root->left)
	{
		t->left = cloneTree(root->left);
	}
	else
	{
		t->left = NULL;
	}
	if (root->right)
	{
		t->right = cloneTree(root->right);
	}
	else
	{
		t->right = NULL;
	}
	return t;
}