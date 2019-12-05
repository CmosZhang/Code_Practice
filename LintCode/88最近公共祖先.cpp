#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

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


//88. 最近公共祖先
//利用vector来实现。
bool FindPath(TreeNode *root, TreeNode*A, vector<TreeNode*> &res)
{
	if (root == NULL || A == NULL)
	{
		return false;
	}
	if (root == A)
	{
		res.push_back(root);
		return true;
	}
	if (FindPath(root->left, A, res))
	{
		res.push_back(root);
		return true;
	}
	else if (FindPath(root->right, A, res))
	{
		res.push_back(root);
		return true;
	}
	else
	{
		return false;
	}
}

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B)
{
	// write your code here
	if (root == NULL || A == NULL || B == NULL)
	{
		return NULL;
	}
	vector<TreeNode*> Apath;
	vector<TreeNode*> Bpath;
	bool findA = FindPath(root, A, Apath);
	bool findB = FindPath(root, B, Bpath);
	TreeNode *ans = NULL;
	if (findA&&findB)
	{
		int Alen = Apath.size();
		int Blen = Bpath.size();
		int minsize = min(Alen, Blen);
		for (int i = Alen - minsize, j = Blen - minsize; i < Alen, j < Blen; i++, j++)
		{
			if (Apath[i] == Bpath[j])
			{
				ans = Apath[i];
				break;
			}
		}
	}
	return ans;
}


////利用栈来实现的
//使用栈来运算的话会比较复杂
//bool FindPath2(TreeNode *root, TreeNode*A, stack<TreeNode*>res2)
//{
//	if (root == NULL || A == NULL)
//	{
//		return false;
//	}
//	if (root == A)
//	{
//		res2.push(root);
//		return true;
//	}
//	if (FindPath2(root->left, A, res2))
//	{
//		res2.push(root);
//		return true;
//	}
//	else if (FindPath2(root->right, A, res2))
//	{
//		res2.push(root);
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//TreeNode * lowestCommonAncestor2(TreeNode * root, TreeNode * A, TreeNode * B)
//{
//	// write your code here
//	if (root == NULL || A == NULL || B == NULL)
//	{
//		return NULL;
//	}
//	stack<TreeNode*> Apath;
//	stack<TreeNode*> Bpath;
//	bool findA = FindPath2(root, A, Apath);
//	bool findB = FindPath2(root, B, Bpath);
//	TreeNode *ans = NULL;
//	while(findA&&findB)
//	{
//		TreeNode *temp1 = Apath.top();
//		TreeNode *temp2 = Bpath.top();
//		TreeNode *temp = NULL;
//		if (temp1 == temp2)
//		{
//			temp = Apath.top();
//			Apath.pop();
//			Bpath.pop();
//		}
//
//	}
//	return ans;
//}

//您的提交打败了 70.80% 的提交!
//采用递归的思路来做.
//这种方法来做的话，思路上比较简单，代码也容易实现
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (root == NULL || root == A || root == B)
	{
		return root;
	}
	TreeNode *left = lowestCommonAncestor(root->left, A, B);
	TreeNode *right = lowestCommonAncestor(root->right, A, B);
	if (left != NULL && right != NULL)
	{
		return root;
	}
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}