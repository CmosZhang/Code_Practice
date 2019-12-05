#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


//二叉树的储存结构
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


//1106. 最大二叉树
//您的提交打败了 97.78% 的提交!
TreeNode * constructMaximumBinaryTree(vector<int> &nums)
{
	// Write your code here
	if (nums.empty())
	{
		return NULL;
	}
	int len = nums.size();
	int max = INT_MIN;
	//max就是根节点
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (max < nums[i])
		{
			max = nums[i];
			flag = i;
		}
	}
	//左侧
	vector<int> left;
	for (int i = 0; i < flag; i++)
	{
		left.push_back(nums[i]);
	}
	//右侧
	vector<int> right;
	for (int i = flag + 1; i < len; i++)
	{
		right.push_back(nums[i]);
	}

	TreeNode *node = new TreeNode(max);
	node->left = constructMaximumBinaryTree(left);
	node->right = constructMaximumBinaryTree(right);
	return node;
}