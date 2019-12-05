#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX  100

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

//85. �ڶ���������в���ڵ�
//�ݹ�ⷨ���5.2%���ύ��
//TreeNode * insertNode(TreeNode * root, TreeNode * node)
//{
//	// write your code here
//	//������ڵ�Ϊ�ա�
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

//�ǵݹ�ⷨ
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
	//������
	if (pre->val > node->val)
		pre->left = node;
	if (pre->val <= node->val)
		pre->right = node;
	return root;
}

//87. ɾ������������Ľڵ�
//�ݹ�ⷨ
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


//�ǵݹ�ⷨ
//�������⣬40%��ʱ��û��ͨ���������ݡ�
//�����ύ����� 75.20% ���ύ!
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
			del = cur; //Ҫɾ���Ľڵ㡣 parent Ҫɾ���ڵ�ĸ��ڵ㡣
			if (cur->left == NULL) //����Ϊ��
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
					root = parent->right; //ɾ���Ľڵ��Ǹ��ڵ�
				}
			}
			else if (cur->right == NULL) //�Һ���Ϊ��
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
					root = parent->left; //ɾ���Ľڵ��Ǹ��ڵ㡣
				}
			}
			else //���Һ��Ӷ���Ϊ��
			{
				TreeNode *temp = cur->right;
				while (temp->left)//��һ�����׳����⡣
				{
					parent = temp;
					temp = temp->left;
				}
				del = temp;
				cur->val = temp->val;
				if (parent->left == temp) //��������С�Ľڵ�����ڵ㣬ָ��Ϊ�գ�temp->rightΪ��
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