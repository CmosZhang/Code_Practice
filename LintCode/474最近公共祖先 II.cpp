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


//474. ����������� II
//�����ύ����� 23.60% ���ύ!
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

//��Ϊ����ָ�򸸽ڵ��ָ�룬���Կ���ת��������Ľ����
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