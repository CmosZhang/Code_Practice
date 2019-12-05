#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

#define MAX  100

using namespace std;

//�������Ĵ���ṹ
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};


//1311. �����������������������
//�����ύ����� 69.30% ���ύ!
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
	// write your code here
	if (root == NULL || root == p || root == q){
		return root;
	}
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left != NULL && right != NULL){
		return root;
	}
	if (left != NULL){
		return left;
	}
	if (right != NULL){
		return right;
	}
	return NULL;
}

//��������û���õ����������������ʡ�
//�����ύ����� 59.65% ���ύ!
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
	int parentVal = root->val;
	int pVal = p->val;
	int qVal = q->val;
	if (pVal > parentVal&&qVal > parentVal) {
		return lowestCommonAncestor(root->right, p, q);
	}
	else if (pVal < parentVal&&qVal < parentVal) {
		return lowestCommonAncestor(root->left, p, q);
	}
	else {
		return root;
	}
}