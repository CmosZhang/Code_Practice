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



//93. ƽ�������
//�����ύ����� 43.60% ���ύ!
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

//������
//�ڱ���ÿ���ڵ��ʱ�򣬼�¼�����
//һ�߱���һ���ж�ÿ���ڵ��ǲ���ƽ��ġ�
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