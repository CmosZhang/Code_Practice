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

//480. 二叉树的所有路径
//您的提交打败了 100.00% 的提交!
vector<string> binaryTreePaths(TreeNode* root) 
{
	// Write your code here
	vector<string> result;
	if (root == NULL) 
	{
		return result;
	}
	vector<int> path;
	DFS(root, path, result);
	return result;
}

void DFS(TreeNode * root, vector<int> &path, vector<string> &result) 
{
	path.push_back(root->val);
	if (root->left == NULL && root->right == NULL)
	{
		string temp;
		for (int p : path)
		{
			char pa[256];
			sprintf(pa, "%d", p);
			temp += pa;
			temp += "->";
		}
		result.push_back(temp.substr(0, temp.size() - 2));
		return;
	}
	if (root->left != NULL) 
	{
		DFS(root->left, path, result);
		path.pop_back();
	}
	if (root->right != NULL) 
	{
		DFS(root->right, path, result);
		path.pop_back();
	}
}