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


//878. �������߽�
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
//�������޷��ж�һ��ȫ����������ɵĶ�����
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

//���ϵ������
//˼·��
//���ֱ�ӵ�˼·���ǽ�������DFS, �ֱ����߽�, Ҷ��, �ұ߽�ŵ���������.
//��߽�: �Ӹ������ӽڵ㿪ʼ, ��������, û�����ӽڵ������, ֱ��Ҷ�ӽڵ�, ��·�����нڵ���������
//Ҷ�ӽڵ�: ����������, Ϊ�˱�֤��ʱ��˳��, ��Ҫ�ȷ������ӽڵ�, ����Ҷ�Ӿͷ��������
//�ұ߽�: ����߽�����, ֻ�������ڵ��������е�ʱ��Ҫ�Ӻ� -- �ڵݹ����ʱ����
//�����ύ����� 69.97% ���ύ!
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