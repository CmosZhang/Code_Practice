#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;

class ParentTreeNode {
public:
	int val;
	ParentTreeNode *parent, *left, *right;
};


//474. 最近公共祖先 II
//您的提交打败了 23.60% 的提交!
ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
	// write your code here
	if (root == NULL || root == A || root == B)
	{
		return root;
	}
	ParentTreeNode *left = lowestCommonAncestorII(root->left, A, B);
	ParentTreeNode *right = lowestCommonAncestorII(root->right, A, B);
	if (left != NULL && right != NULL)
	{
		return root;
	}
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}

//因为存在指向父节点的指针，所以可以转换成链表的交叉点
ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B)
{
	if (root == NULL || root == A || root == B)
	{
		return root;
	}
	unordered_set<ParentTreeNode *> s;
	ParentTreeNode * tempA = A;
	ParentTreeNode * tempB = B;
	while (tempA || tempB)
	{
		if (tempA && s.find(tempA) != s.end()) 
			return tempA;
		s.insert(tempA);
		if (tempB && s.find(tempB) != s.end()) 
			return tempB;
		s.insert(tempB);

		tempA = tempA->parent;
		tempB = tempB->parent;
	}
}