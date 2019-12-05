#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

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

//您的提交打败了 75.22% 的提交!
void inorder_helper(TreeNode*root, vector<int>&res) {
	if (!root) {
		return;
	}
	inorder_helper(root->left, res);
	res.push_back(root->val);
	inorder_helper(root->right, res);
}

vector<int> inorder(TreeNode *root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	inorder_helper(root, res);
	return res;
}


vector<int> findMode(TreeNode * root) {
	// write your code here
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	vector<int> temp = inorder(root);
	map<int, int>mp;
	map<int, int>::iterator it;
	for (int i = 0; i < temp.size(); i++) {
		it = mp.find(temp[i]);
		if (it == mp.end()) {
			mp.insert(pair<int, int>(temp[i], 1));
		}
		else {
			it->second++;
		}
	}
	int count = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		count = max(count, it->second);
	}
	map<int, int>::iterator it1;
	for (it1 = mp.begin(); it1 != mp.end(); it1++) {
		if (it1->second == count) {
			res.push_back(it1->first);
		}
	}
	return res;
}

int main()
{
	//创建二叉树
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	TreeNode *p7 = new TreeNode(5);
	TreeNode *p8 = new TreeNode(8);
	TreeNode *p9 = new TreeNode(9);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p5->left = p6;
	p3->left = p7;
	p3->right = p8;
	p8->right = p9;

	cout << "中序遍历:" << endl;
	vector<int> in =inorder(p1);
	for (auto i : in)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> res = findMode(p1);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	system("pause");
	return 0;
}