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



//535. ´ò½Ù·¿ÎÝ III
//
int houseRobber3(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return 0;
	}

}