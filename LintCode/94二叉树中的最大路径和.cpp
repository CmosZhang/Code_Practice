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
//94. 二叉树中的最大路径和
//您的提交打败了 100.00% 的提交!
//网上优秀代码
/*
int result;  
int maxPathSum(TreeNode* root)
{       
    result = INT_MIN;   // 考虑全部节点为负数的情况   
	getPath(root);       
	return result;    
}    

int getPath(TreeNode* node)
{        
	if(node == NULL)
	{           
		return 0;      
	}      
	int left = getPath(node->left); 
	int right = getPath(node->right);
	int tmp = max(max(left+node->val, right+node->val), node->val); // 这三种情况是经过节点node且可以向上组合的，需要返回给上层使用    
	result = max(result,max(tmp, left+right+node->val));    // 不能向上组合的情况只需要用于更新结果，无需向上返回      
	return tmp;    
}
*/

//您的提交打败了 100.00% 的提交!
int helper(TreeNode*root, int &res)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = helper(root->left, res);
	int right = helper(root->right, res);
	res = max(res, max(0, left) + max(0, right) + root->val);
	return max(left, right) + root->val;
}

int maxPathSum(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return 0;
	}
	int res = INT_MIN;
	helper(root, res);
	return res;
}

void main() {
	char str[] = "S\065AB";
	printf("\n%d", sizeof(str));
	system("pause");
}