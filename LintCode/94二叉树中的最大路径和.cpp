#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

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
//94. �������е����·����
//�����ύ����� 100.00% ���ύ!
//�����������
/*
int result;  
int maxPathSum(TreeNode* root)
{       
    result = INT_MIN;   // ����ȫ���ڵ�Ϊ���������   
	getPath(root);       
	return result;    
}    

int getPath(TreeNode* node)
{        
	if(node == NULL)
	{           
		return 0;      
	}      
	int left = getPath(node->left); 
	int right = getPath(node->right);
	int tmp = max(max(left+node->val, right+node->val), node->val); // ����������Ǿ����ڵ�node�ҿ���������ϵģ���Ҫ���ظ��ϲ�ʹ��    
	result = max(result,max(tmp, left+right+node->val));    // ����������ϵ����ֻ��Ҫ���ڸ��½�����������Ϸ���      
	return tmp;    
}
*/

//�����ύ����� 100.00% ���ύ!
int helper(TreeNode*root, int &res)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = helper(root->left, res);
	int right = helper(root->right, res);
	res = max(res, max(0, left) + max(0, right) + root->val);
	return max(left, right) + root->val;
}

int maxPathSum(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return 0;
	}
	int res = INT_MIN;
	helper(root, res);
	return res;
}

void main() {
	char str[] = "S\065AB";
	printf("\n%d", sizeof(str));
	system("pause");
}