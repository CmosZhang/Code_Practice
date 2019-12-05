#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

#define MAX  100

using namespace std;

//�������Ĵ���ṹ
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


//448. �����������������
//�����ύ����� 71.40% ���ύ!
void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
	if (!root) return;
	inorder(root->left, list, vals);
	list.push_back(root);
	vals.push_back(root->val);
	inorder(root->right, list, vals);
}

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
	// write your code here
	if (root == NULL || p == NULL) {
		return NULL;
	}
	vector<TreeNode*> list;
	vector<int> vals;
	inorder(root, list, vals);
	for (int i = 0; i < list.size(); i++) {
		if (p == list[i]) {
			if (i == list.size() - 1) {
				return NULL;
			}
			else {
				return list[i + 1];
			}
		}
	}
	return NULL;
}