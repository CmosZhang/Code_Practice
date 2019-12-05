#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

#define MAX  100

using namespace std;

//二叉树的储存结构
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};



//1359. 有序数组转换为二叉搜索树
//您的提交打败了 43.48% 的提交!
TreeNode *helper(vector<int> &nums, int left, int right) {
	if (left > right) { 
		return NULL; 
	}
	int mid = (left + right) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = helper(nums, left, mid - 1);
	root->right = helper(nums, mid + 1, right);
	return root;
}
TreeNode * convertSortedArraytoBinarySearchTree(vector<int> &nums) {
	// Write your code here.
	if (nums.empty()) {
		return NULL;
	}
	return helper(nums, 0, nums.size() - 1);
}