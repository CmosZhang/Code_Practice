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


//87. ɾ������������Ľڵ�
//�����ύ����� 0.00% ���ύ!
//ɾ���ڵ�ĵݹ�汾
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


//�ǵݹ�汾
//�����ύ����� 10.40% ���ύ!
//�õݹ�ķ�ʽ���Ƚϼ򵥣������������
TreeNode* removeNode(TreeNode* root, int value) {
	// write your code here
	if (root == NULL)
		return NULL;
	TreeNode * head = new TreeNode(0);
	head->left = root;
	TreeNode * tmp = root, *father = head;

	//��ȷ��Ҫɾ���ڵ��λ��
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

	//��ɾ���ڵ���������ǿ�
	if (tmp->right == NULL) {
		if (father->left == tmp)
			father->left = tmp->left;
		else
			father->right = tmp->left;
	}
	else
		if (tmp->right->left == NULL) {//��ɾ���ڵ���������е���Сֵ
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
