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

//��������ǰ�������
//�����ύ����� 59.00% ���ύ!
void preorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	v.push_back(root->val);
	preorder_help(root->left, v);
	preorder_help(root->right, v);
}
vector<int> preorderTraversal(TreeNode * root)
{
	// write your code here
	vector<int > v;
	if (root == NULL)return v;
	preorder_help(root, v);
	return v;
}
//�ǵݹ�汾
vector<int> preorderTraversal(TreeNode*root)
{
	vector<int> res;
	if (root == NULL){
		return res;
	}
	stack<TreeNode*>st;
	TreeNode*p = root;
	while (p != NULL || !st.empty()){
		while (p != NULL){
			st.push(p);
			res.push_back(p->val);
			p = p->left;
		}
		p = st.top();
		st.pop();
		p = p->right;
	}
}

//�����������������
void inorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	inorder_help(root->left, v);
	v.push_back(root->val);
	inorder_help(root->right, v);
}
vector<int> inorderTraversal(TreeNode * root) 
{
	// write your code here
	vector<int > v;
	if (root == NULL)return v;
	inorder_help(root, v);
	return v;
}

//�������ĺ��������
//�����ύ����� 88.40% ���ύ!
void postorder_help(TreeNode *root, vector<int > &v)
{
	if (!root)return;
	postorder_help(root->left, v);
	postorder_help(root->right, v);
	v.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode * root)
{
	// write your code here
	vector<int > v;
	if (root == NULL)return v;
	postorder_help(root, v);
	return v;
}
vector<int> postorderTraversal(TreeNode * root)
{ 
	vector<int> res;
	if (root == NULL) 
	{ 
		return res;
	}   
	stack<TreeNode*>st; 
	st.push(root);    
	while (!st.empty())
	{ 
		TreeNode *p;   
		p = st.top();    
		res.push_back(p->val);
		st.pop();       
		if (p->left != NULL) 
		{
			st.push(p->left);
		}  
		if (p->right != NULL)
		{
			st.push(p->right);
		}
	}  
	reverse(res.begin(), res.end()); 
	return res;
}

//�ڶ��ַǵݹ��������ķ���
//Ҫ��֤���ڵ������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���p,�Ƚ�����ջ��
//���p���������Ӻ��Һ��ӣ������ֱ�ӷ�����������p�������ӻ����Һ��ӣ�
//���������ӻ��Һ����Ѿ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸýڵ㡣�����������������
//��p���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���
//ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ��ڵ�ǰ�汻���ʡ�
vector<int> postorderTraversal(TreeNode * root)
{
	vector<int> res;
	if (root == NULL)
	{
		return res;
	}
	stack<TreeNode*>st;
	st.push(root);
	TreeNode *cur, *pre = NULL;//pre��ǰһ�α����ʵĽڵ�
	while (!st.empty())
	{
		cur = st.top();
		if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right)))
		{
			res.push_back(cur->val);
			st.pop();
			pre = cur;
		}
		else
		{
			if (cur->right != NULL)
			{
				st.push(cur->right);
			}
			if (cur->left != NULL)
			{
				st.push(cur->left);
			}
		}
	}
	return res;
}

//void *CreateTree(TreeNode *root)//����һ�ö�����
//{
//	TreeNode *p1 = new TreeNode(1);
//	TreeNode *p2 = new TreeNode(2);
//	TreeNode *p3 = new TreeNode(3);
//	TreeNode *p4 = new TreeNode(4);
//	TreeNode *p5 = new TreeNode(5);
//	TreeNode *p6 = new TreeNode(6);
//	TreeNode *p7 = new TreeNode(7);
//	TreeNode *p8 = new TreeNode(8);
//	TreeNode *p9 = new TreeNode(9);
//	p1->left = p2;
//	p1->right = p3;
//	p2->left = p4;
//	p2->right = p5;
//	p5->left = p6;
//	p3->left = p7;
//	p3->right = p8;
//	p8->right = p9;
//	root = p1;
//	return root;
//}

void exchange(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	TreeNode *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

// �ݹ�ʵ�ַ�ת�������Ĺ���
/*void invertBinaryTree(TreeNode * root)
{
// write your code here
if (root == NULL)
{
return;
}
invertBinaryTree(root->left);
invertBinaryTree(root->right);
exchange(root);
}*/

// �ǵݹ�ʵ�ַ�ת�������Ĺ���
void invertBinaryTree(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty())
	{
		TreeNode *temp = stk.top();
		stk.pop();
		exchange(temp);
		if (temp->left)
			stk.push(temp->left);
		if (temp->right)
			stk.push(temp->right);
	}
}

//155. ����������С���
int minDepth(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	if (root->left == NULL)
	{
		return minDepth(root->right) + 1;
	}
	if (root->right == NULL)
	{
		return minDepth(root->left) + 1;
	}
	return min(minDepth(root->right), minDepth(root->left)) + 1;
}

//97. ��������������
//�����ύ����� 100.00% ���ύ!��������С��ȵĴ��롣
int maxDepth(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	if (root->left == NULL)
	{
		return maxDepth(root->right) + 1;
	}
	if (root->right == NULL)
	{
		return maxDepth(root->left) + 1;
	}
	return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}

//69. �������Ĳ�α���
//�����ύ����� 64.20% ���ύ!
vector<vector<int>> levelOrder(TreeNode * root) 
{
	// write your code here
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

//70. �������Ĳ�α��� II
//�����ύ����� 15.20% ���ύ!��ʹ��ջ��ֱ�ӶԶ�άvector���з�ת������
//ʹ��ջ���������4%���ύ��
vector<vector<int>> levelOrderBottom(TreeNode * root)
{
	// write your code here
	vector<vector<int>>res;
	//����һ��ջ
	stack<vector<int>>restemp;
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
			restemp.push(temp);
		}
	}
	//�������Ǹ��������һ����ת
	//int l = res.size();
	//for (int i = 0; i<l / 2; i++)
	//{
	//	vector<int>temp2;
	//	temp2 = res[i];
	//	res[i] = res[l - 1 - i];
	//	res[l - 1 - i] = temp2;
	//}
	while (!restemp.empty())
	{
		res.push_back(restemp.top());
		restemp.pop();
	}
	return res;
}

//71. �������ľ���β�α���
//�����ύ����� 81.60% ���ύ!
//�����ڲ�α����Ļ����Ͻ�����չ���������������Ҫ��תvector.
vector<vector<int>> zigzagLevelOrder(TreeNode * root) 
{
	// write your code here
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
	//�������Ǹ��������һ����ת
	int l = res.size();
	for (int i = 0; i < l; i++)
	{
		if (i % 2 != 0)
		{
			vector<int>temp2;
			temp2 = res[i];
			reverse(temp2.begin(),temp2.end());
			res[i] = temp2;
		}
	}
	return res;
}


//73.ǰ������������������������
//�����ύ����� 79.00% ���ύ!
//ʹ�õݹ�ķ�ʽ������
TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	// write your code here
	if (preorder.empty() || inorder.empty())
	{
		return NULL;
	}
	int inlen = inorder.size();
    //�������ڵ㣬ǰ������ĵ�һ������Ǹ��ڵ㡣
	TreeNode *root = new TreeNode(preorder[0]);
	//�ҵ���������ĸ��ڵ��λ�á�
	int gen = 0;
	for (int i = 0; i < inlen; i++)
	{
		if (inorder[i] == preorder[0])
		{
			gen = i;
			break;
		}
	}
	//������������ڵ���ߵĽڵ�λ�ڶ����������
	//���ڵ��ұߵĽڵ�λ�ڶ��������ұ�
	vector<int>left_pre, left_in, right_pre, right_in;
	for (int i = 0; i < gen; i++)
	{
		left_in.push_back(inorder[i]);//������
		left_pre.push_back(preorder[i+1]);//ǰ�������������
	}
	for (int i = gen + 1; i < inlen; i++)
	{
		right_in.push_back(inorder[i]);//������
		right_pre.push_back(preorder[i]);//ǰ�������������
	}
	//ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
	//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
	root->left=buildTree(left_pre,left_in);//������ǰ�� ����������
	root->right=buildTree(right_pre,right_in);//������ǰ�� ����������
	return root;
}


//72. ��������ͺ�����������������
//�����ύ����� 97.00% ���ύ!
//ʹ�õݹ�ķ�ʽ������
TreeNode * buildTree2(vector<int> &inorder, vector<int> &postorder) 
{
	// write your code here
	if (inorder.empty() || postorder.empty())
	{
		return NULL;
	}
	//���ҵ����ڵ㡣
	int inlen = inorder.size();
	int postlen = postorder.size();
	//�������ڵ㣬������������һ������Ǹ��ڵ㡣
	TreeNode *root = new TreeNode(postorder[postlen - 1]);
	//�ҵ���������ĸ��ڵ��λ�á�
	int gen = 0;
	for (int i = 0; i < inlen; i++)
	{
		if (inorder[i] == postorder[postlen - 1])
		{
			gen = i;
			break;
		}
	}
	//������������ڵ���ߵĽڵ�λ�ڶ����������
	//���ڵ��ұߵĽڵ�λ�ڶ��������ұ�
	vector<int>left_post, left_in, right_post, right_in;
	for (int i = 0; i < gen; i++)
	{
		left_in.push_back(inorder[i]);//���������������
		left_post.push_back(postorder[i]);//���������������
	}
	for (int i = gen + 1; i < inlen; i++)
	{
		right_in.push_back(inorder[i]);//���������������
		right_post.push_back(postorder[i - 1]);//���������������
	}
	//ȡ�����������������ڵ���ߺ��ұߵ�����
	//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
	root->left = buildTree(left_in, left_post);//���������� ����������
	root->right = buildTree(right_in, right_post);//���������� ����������
	return root;
}


//95. ��֤���������
//�����ύ����� 100.00% ���ύ!
//ֻҪ�����������һ������˳�����Ƕ��������
bool isValidBST(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return true;
	}
	vector<int> inres;//��������Ľ��������ġ�
	inres = inorderTraversal(root);
	for (int i = 0; i < inres.size() - 1; ++i)
	{
		if (inres[i] >= inres[i + 1])
		{
			return false;
		}
	}
	return true;
}

//11. �������������������
//�����ύ����� 99.00% ���ύ!
vector<int> searchRange(TreeNode * root, int k1, int k2) 
{
	// write your code here
	vector<int>res;
	if (root == NULL)
	{
		return res;
	}
	vector<int> inres;//��������Ľ��������ġ�
	inres = inorderTraversal(root);
	for (int i = 0; i < inres.size(); i++)
	{
		if (inres[i] >= k1 && inres[i] <= k2)
		{
			res.push_back(inres[i]);
		}
	}
	return res;
}

//177. ����������ת��Ϊ�߶���С�Ķ���������
//�����ύ����� 60.40% ���ύ!
TreeNode *bulidSortedTree(vector<int> &A, int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	//�������ڵ㡣
	TreeNode *root = new TreeNode(A[mid]);
	root->left = bulidSortedTree(A, start, mid - 1);
	root->right = bulidSortedTree(A, mid + 1, end);
	return root;
}
TreeNode * sortedArrayToBST(vector<int> &A)
{
	// write your code here
	if (A.empty())
	{
		return NULL;
	}
	int low = 0;
	int high = A.size() - 1;
	return bulidSortedTree(A, low, high);
}



//480. ������������·��
vector<string> binaryTreePaths(TreeNode * root) 
{
	// write your code here
	vector<string>res;
	if (root == NULL)
	{
		return res;
	}	
}

//469. Same Tree
//�����ύ����� 100.00% ���ύ!
//���õݹ��˼·������
bool isIdentical(TreeNode * a, TreeNode * b) 
{
	// write your code here
	if (a == NULL && b == NULL)
	{
		return true;
	}
	if (a == NULL || b == NULL)
	{
		return false;
	}
	if (isIdentical(a->left, b->left) && isIdentical(a->right, b->right))
	{
		return (a->val == b->val)? true : false;
	}
	return false;
}

//726. ��֤��������
//�����ύ����� 100.00% ���ύ!
//ʹ�õݹ��˼·
bool isFullTree(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return true;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else if (root->left == NULL)
	{
		return false;
	}
	else if (root->right == NULL)
	{
		return false;
	}
	return  isFullTree(root->left) && isFullTree(root->right);
}

//88. Lowest Common Ancestor of a Binary Tree
//TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) 
//{
//	// write your code here
//
//
//
//
//
//}



////7. �����������л��ͷ����л�
//string serialize(TreeNode * root) 
//{
//	// write your code here
//	string res;
//	if (root == NULL)
//	{
//		return res;
//	}
//
//
//}
//TreeNode * deserialize(string &data) 
//{
//	// write your code here
//}

//163. ��ͬ�Ķ��������
//�����ύ����� 93.80% ���ύ!
int numTrees(int n)
{
	// write your code here
	if (n <= 0)
	{
		return 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++) 
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}


//164. ��ͬ�Ķ�������� II
//vector<TreeNode *> generateTrees(int n)
//{
//	// write your code here
//
//
//
//
//
//
//}


//



int main()
{
	//����������
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	TreeNode *p7 = new TreeNode(7);
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

	cout << "ǰ�����:" << endl;
	vector<int> pre = preorderTraversal(p1);
	for (auto i : pre)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "��ת������:" << endl;
	invertBinaryTree(p1);
	vector<int>pre2 = preorderTraversal(p1);
	for (auto i : pre2)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "����������С���:";
	int d = minDepth(p1);
	cout << d << endl;




	system("pause");
	return 1;
}
