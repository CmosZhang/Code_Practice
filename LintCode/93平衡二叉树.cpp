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



//93. 平衡二叉树
//您的提交打败了 43.60% 的提交!
int getHeight(TreeNode*root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	return max(lh, rh) + 1;
}

bool isBalanced(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return true;
	}
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	if (abs(lh - rh) > 1)
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}

//方法二
//在遍历每个节点的时候，记录其深度
//一边遍历一边判断每个节点是不是平衡的。
int depth(TreeNode *root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	int left = depth(root->left);
	int right = depth(root->right);
	if (left == -1 || right == -1 || abs(left - right) > 1) 
	{
		return -1;
	}
	return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) 
{
	return depth(root) != -1;
}