#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX  100

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


//164. 不同的二叉查找树 II
//您的提交打败了 41.20% 的提交!
//该函数，返回的是从start开始，以end结尾的元素生成二叉查找树的集合
vector<TreeNode *> generateBST(int start, int end)
{
	vector<TreeNode*>res;
	if (start > end)
	{
		res.push_back(NULL);
	}
	for (int i = start; i <= end; i++)//以i为根节点有多少种二叉查找树
	{
		vector<TreeNode*> lefts = generateBST(start, i - 1);//这里返回的是一个集合，表示以i为根时，左子树可能的所有集合
		vector<TreeNode*> rights = generateBST(i + 1, end);//这里返回的是一个集合，表示以i为根时，右子树可能的所有集合
		for (auto left : lefts)
		{
			for (auto right : rights)
			{
				TreeNode *root = new TreeNode(i);//将所有可能的结果存储到res中。
				root->left = left;
				root->right = right;
				res.push_back(root);
			}
		}
	}
	return res;
}

vector<TreeNode *> generateTrees(int n)
{
	// write your code here
	vector<TreeNode*>res;
	if (n < 1)
	{
		res.push_back(NULL);
		return res;
	}
	return generateBST(1, n);
}

int numTrees(int n) {
	// write your code here
	if (n <= 0)
	{
		return 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}


int main() {
	int n = 6;
	cout << numTrees(6) << endl;
	system("pause");
	return 0;
}