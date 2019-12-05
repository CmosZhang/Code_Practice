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

//760. ������������ͼ
//ÿ�ν�������������һ��ֵ��������������
//�����ύ����� 75.00% ���ύ!
vector<int> rightSideView(TreeNode * root) {
	// write your code here
	vector<int> res;
	if (root == NULL) {
		return res;
	}
	queue<TreeNode*> que;
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
			res.push_back(temp.back());
		}
	}
	return res;
}