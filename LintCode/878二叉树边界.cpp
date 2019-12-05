#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


//878. 二叉树边界
//
vector<vector<int>> levelOrder(TreeNode * root){
	vector<vector<int>>res;
	queue<TreeNode*>que;
	if (root == NULL)
	{
		return res;
	}
	que.push(root);
	int len = que.size();
	while (!que.empty())
	{
		vector<int>temp;
		len = que.size();
		while (len--)
		{
			TreeNode *tem;
			tem = que.front();
			temp.push_back(tem->val);
			que.pop();
			if (tem->left != NULL)
			{
				que.push(tem->left);
			}
			if (tem->right != NULL)
			{
				que.push(tem->right);
			}
		}
		if (!temp.empty())
		{
			res.push_back(temp);
		}
	}
	return res;
}
//答案有误，无法判断一棵全是左子树组成的二叉树
//vector<int> boundaryOfBinaryTree(TreeNode * root) {
//	// write your code here
//	vector<int> res;
//	if (root == NULL) {
//		return res;
//	}
//	vector<vector<int>> tmp = levelOrder(root);
//	res.push_back(tmp[0][0]);
//	for (int i = 1; i < tmp.size(); i++) {
//		if (i != tmp.size() - 1 && tmp[i].size() != 1)
//			res.push_back(tmp[i][0]);
//		else if(i==tmp.size()-1)
//			for (int j = 0; j < tmp[i].size(); j++) {
//				res.push_back(tmp[i][j]);
//			}
//	}
//	for (int i = tmp.size() - 2; i > 0; i--) {
//		res.push_back(tmp[i].back());
//	}
//	return res;
//}

//网上的优秀答案
//思路：
//最简单直接的思路就是进行三次DFS, 分别把左边界, 叶子, 右边界放到答案序列中.
//左边界: 从根的左子节点开始, 优先向左, 没有左子节点就向右, 直到叶子节点, 沿路的所有节点放入答案序列
//叶子节点: 遍历整棵树, 为了保证逆时针顺序, 需要先访问左子节点, 碰到叶子就放入答案序列
//右边界: 与左边界类似, 只不过将节点放入答案序列的时机要延后 -- 在递归结束时放入
//您的提交打败了 69.97% 的提交!
vector<int> ans;

void dfsleft(TreeNode *rt) {
	if (rt == NULL || (rt->left == NULL && rt->right == NULL)) {
		return;
	}
	ans.push_back(rt->val);
	if (rt->left != NULL) {
		dfsleft(rt->left);
	}
	else {
		dfsleft(rt->right);
	}
}

void dfsleaf(TreeNode *rt) {
	if (rt == NULL) {
		return;
	}
	if (rt->left == NULL && rt->right == NULL) {
		ans.push_back(rt->val);
		return;
	}
	dfsleaf(rt->left);
	dfsleaf(rt->right);
}

void dfsright(TreeNode *rt) {
	if (rt == NULL || (rt->left == NULL && rt->right == NULL)) {
		return;
	}
	if (rt->right != NULL) {
		dfsright(rt->right);
	}
	else {
		dfsright(rt->left);
	}
	ans.push_back(rt->val);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return ans;
	}
	ans.push_back(root->val);
	if (root->left == NULL && root->right == NULL) {
		return ans;
	}
	dfsleft(root->left);
	dfsleaf(root);
	dfsright(root->right);
	return ans;
}