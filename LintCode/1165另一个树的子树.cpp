#include<iostream>
#include<algorithm>
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


//1165. 另一个树的子树
//

bool isSubtreeHelper(TreeNode * s, TreeNode * t)
{
	if (s == NULL && t == NULL)
	{
		return true;
	}
	if (s == NULL || t == NULL)
	{
		return false;
	}
	if (s->val != t->val)
	{
		return false;
	}
	return isSubtreeHelper(s->left, t->left) && isSubtreeHelper(s->right, t->right);
}

bool isSubtree(TreeNode * s, TreeNode * t)
{
	// Write your code here
	if (s == NULL)
	{
		return false;
	}
	bool res = false;
	res = isSubtreeHelper(s, t);
	if (!res)
	{
		res = isSubtree(s->left, t);
	}
	if (!res)
	{
		res = isSubtree(s->right, t);
	}
	return res;
}