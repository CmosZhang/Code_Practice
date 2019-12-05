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


//691. 恢复二叉搜索树
//您的提交打败了 100.00% 的提交!
void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
	if (!root) return;
	inorder(root->left, list, vals);
	list.push_back(root);
	vals.push_back(root->val);
	inorder(root->right, list, vals);
}
TreeNode* bstSwappedNode(TreeNode *root) {
	vector<TreeNode*> list;
	vector<int> vals;
	inorder(root, list, vals);
	sort(vals.begin(), vals.end());
	for (int i = 0; i < list.size(); ++i) {
		list[i]->val = vals[i];
	}
	return root;
}
