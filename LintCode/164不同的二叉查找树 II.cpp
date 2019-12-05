#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX  100

using namespace std;

//�������Ĵ���ṹ
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


//164. ��ͬ�Ķ�������� II
//�����ύ����� 41.20% ���ύ!
//�ú��������ص��Ǵ�start��ʼ����end��β��Ԫ�����ɶ���������ļ���
vector<TreeNode *> generateBST(int start, int end)
{
	vector<TreeNode*>res;
	if (start > end)
	{
		res.push_back(NULL);
	}
	for (int i = start; i <= end; i++)//��iΪ���ڵ��ж����ֶ��������
	{
		vector<TreeNode*> lefts = generateBST(start, i - 1);//���ﷵ�ص���һ�����ϣ���ʾ��iΪ��ʱ�����������ܵ����м���
		vector<TreeNode*> rights = generateBST(i + 1, end);//���ﷵ�ص���һ�����ϣ���ʾ��iΪ��ʱ�����������ܵ����м���
		for (auto left : lefts)
		{
			for (auto right : rights)
			{
				TreeNode *root = new TreeNode(i);//�����п��ܵĽ���洢��res�С�
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