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



//578. ����������� III
//��֮ǰ����Ŀ��ȣ�����һ���ж��������жϽڵ�A�ͽڵ�B�Ƿ�������������
//�����ύ����� 67.60% ���ύ!

bool foundA = false;
bool foundB = false;

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
	// write your code here
	TreeNode* res = lowestCommonAncestorHelper(root, A, B);
	if (foundA && foundB)    	// ����ִ����֮��鿴�Ƿ������ڵ㶼���ҵ�
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

	// ��� root ��Ҫ�ҵģ�����ȫ�ֱ���
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


//��������
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
