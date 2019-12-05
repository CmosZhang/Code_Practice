#include<iostream>
#include<algorithm>
#include<stack>
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


//902. BST�е�KС��Ԫ��
//�����ύ����� 85.40% ���ύ!

//�����������������
void inorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	inorder_help(root->left, v);
	v.push_back(root->val);
	inorder_help(root->right, v);
}
vector<int> inorderTraversal(TreeNode * root)
{
	// write your code here
	vector<int > v;
	if (root == NULL)return v;
	inorder_help(root, v);
	return v;
}

int kthSmallest(TreeNode * root, int k)
{
	// write your code here
	if (root == NULL || k <= 0)
	{
		return -1;
	}
	vector<int> ans = inorderTraversal(root);
	if (k > ans.size())
	{
		return -1;
	}
	return ans[k - 1];
}

//��kС����
//�����ύ����� 92.00% ���ύ!
int index, kth;
int kthSmallest(TreeNode * root, int k) {
	if (root == NULL) {
		return -1;
	}
	index = 0;
	inorder(root, k);
	return kth;
}

void inorder(TreeNode*root, int k) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, k);
	index++;
	if (index == k) {
		kth = root->val;
	}
	if (index < k) {
		inorder(root->right, k);
	}
}

//��K��Ľڵ�
int count1 = 0;
TreeNode* KthNode(TreeNode* root, int k)
{
	if (root == NULL) {
		return NULL;
	}
	TreeNode* left = KthNode(root->left, k);
	if (left != NULL)
	{
		return left;
	}
	count1++;
	if (count1 == k)
	{
		return root;
	}
	TreeNode *right = KthNode(root->right, k);
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}


//������K��Ľڵ�
//���������������ֻҪ�����������ķ���˳���ü���
int count2 = 0;
TreeNode* reverseKthNode(TreeNode* root, int k)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode *right = reverseKthNode(root->right, k);
	if (right != NULL)
	{
		return right;
	}
	count2++;
	if (count2 == k)
	{
		return root;
	}
	TreeNode *left = reverseKthNode(root->left, k);
	if (left != NULL)
	{
		return left;
	}
	return NULL;
}
