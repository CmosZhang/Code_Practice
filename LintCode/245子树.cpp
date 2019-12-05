#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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


//245. ×ÓÊ÷
//
bool isEqual(TreeNode *T1, TreeNode *T2)
{
	if (T1 == NULL|| T2 == NULL)
	{
		return T1 == T2;
	}
	if (T1->val != T2->val) 
	{
		return false;
	}
	return isEqual(T1->left, T2->left) && isEqual(T1->right, T2->right);
}
bool isSubtree(TreeNode * T1, TreeNode * T2)
{
	// write your code here
	if (T2 == NULL)
	{
		return true;
	}
	if (T1 == NULL)
	{
		return false;
	}
	if (isEqual(T1, T2))
	{
		return true;
	}
	if (isSubtree(T1->left, T2) || isSubtree(T1->right, T2))
	{
		return true;
	}
	return false;
}