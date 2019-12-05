#include<iostream>
#include<vector>
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

//689. 两数之和 - BST版本
//方法先中序遍历得到一个有序数组，然后利用两数之和来做。
//您的提交打败了 53.00% 的提交!
//这种方法利用了辅助空间。
void inorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	inorder_help(root->left, v);
	v.push_back(root->val);
	inorder_help(root->right, v);
}
vector<int> twoSum(TreeNode * root, int n) {
	// write your code here
	vector<int> res;
	if (root == NULL)
	{
		return res;
	}
	vector<int > v;
	inorder_help(root, v);
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		if (v[left] + v[right] == n)
		{
			res.push_back(v[left]);
			res.push_back(v[right]);
			return res;
		}
		else if (v[left] + v[right] > n)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return res;
}

//不用辅助空间的方法
//您的提交打败了 72.00% 的提交!
TreeNode *search(TreeNode *root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (val == root->val)
	{
		return root;
	}
	if (val < root->val)
	{
		return search(root->left, val);
	}
	return search(root->right, val);
}

vector<int> helper(TreeNode*root, TreeNode *topRoot, int n)
{
	vector<int> ans;
	if (root == NULL)
	{
		return ans;
	}
	TreeNode *another = search(topRoot, n - root->val);
	if (another != NULL && another != root)
	{
		ans.push_back(root->val);
		ans.push_back(n - root->val);
		return ans;
	}
	ans = helper(root->left, topRoot, n);
	if (!ans.empty())
	{
		return ans;
	}
	return helper(root->right, topRoot, n);
}

vector<int> twoSum(TreeNode * root, int n) {
	return helper(root, root, n);
}