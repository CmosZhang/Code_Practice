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



//578. 最近公共祖先 III
//与之前的题目相比，多了一个判断条件，判断节点A和节点B是否存在与这个树中
//您的提交打败了 67.60% 的提交!

bool foundA = false;
bool foundB = false;

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
	// write your code here
	TreeNode* res = lowestCommonAncestorHelper(root, A, B);
	if (foundA && foundB)    	// 程序执行完之后查看是否两个节点都能找到
		return res;
	else
		return NULL;
}
TreeNode *lowestCommonAncestorHelper(TreeNode *root, TreeNode *A, TreeNode *B)
{
	if (root == NULL)
	{
		return root;
	}
	TreeNode *left = lowestCommonAncestorHelper(root->left, A, B);
	TreeNode *right = lowestCommonAncestorHelper(root->right, A, B);

	// 如果 root 是要找的，更新全局变量
	if (root == A || root == B) {
		foundA = (root == A) || foundA;
		foundB = (root == B) || foundB;
		return root;
	}

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


//方法二：
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

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B)
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
