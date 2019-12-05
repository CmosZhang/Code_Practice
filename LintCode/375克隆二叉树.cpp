#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//�������Ĵ���ṹ
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

//375. ��¡������
//�����ύ����� 97.60% ���ύ!
//û������
//TreeNode * cloneTree(TreeNode * root)
//{
//	// write your code here
//	return root;
//}

//�����ύ����� 84.00% ���ύ!
//ʹ�õݹ�ķ���
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