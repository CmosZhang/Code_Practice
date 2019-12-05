#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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

//二叉树的前序遍历。
//您的提交打败了 59.00% 的提交!
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
//非递归版本
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

//二叉树的中序遍历。
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

//二叉树的后序遍历。
//您的提交打败了 88.40% 的提交!
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

//第二种非递归后序遍历的方法
//要保证根节点在左孩子和右孩子访问之后才能访问，因此对于任一结点p,先将其入栈，
//如果p不存在左孩子和右孩子，则可以直接访问他，或者p存在左孩子或者右孩子，
//但是其左孩子或右孩子已经访问过了，则同样可以直接访问该节点。若非上述两种情况，
//则将p的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子
//前面被访问，左孩子和右孩子都在根节点前面被访问。
vector<int> postorderTraversal(TreeNode * root)
{
	vector<int> res;
	if (root == NULL)
	{
		return res;
	}
	stack<TreeNode*>st;
	st.push(root);
	TreeNode *cur, *pre = NULL;//pre是前一次被访问的节点
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

//void *CreateTree(TreeNode *root)//创建一棵二叉树
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

// 递归实现翻转二叉树的功能
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

// 非递归实现翻转二叉树的功能
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

//155. 二叉树的最小深度
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

//97. 二叉树的最大深度
//您的提交打败了 100.00% 的提交!类似于最小深度的代码。
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

//69. 二叉树的层次遍历
//您的提交打败了 64.20% 的提交!
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

//70. 二叉树的层次遍历 II
//您的提交打败了 15.20% 的提交!不使用栈，直接对二维vector进行翻转操作。
//使用栈来做，打败4%的提交。
vector<vector<int>> levelOrderBottom(TreeNode * root)
{
	// write your code here
	vector<vector<int>>res;
	//利用一个栈
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
	//比上面那个程序多了一个反转
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

//71. 二叉树的锯齿形层次遍历
//您的提交打败了 81.60% 的提交!
//还是在层次遍历的基础上进行扩展，奇数的输出，需要反转vector.
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
	//比上面那个程序多了一个反转
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


//73.前序遍历和中序遍历构建二叉树
//您的提交打败了 79.00% 的提交!
//使用递归的方式来做。
TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	// write your code here
	if (preorder.empty() || inorder.empty())
	{
		return NULL;
	}
	int inlen = inorder.size();
    //创建根节点，前序遍历的第一个点就是根节点。
	TreeNode *root = new TreeNode(preorder[0]);
	//找到中序遍历的根节点的位置。
	int gen = 0;
	for (int i = 0; i < inlen; i++)
	{
		if (inorder[i] == preorder[0])
		{
			gen = i;
			break;
		}
	}
	//中序遍历，根节点左边的节点位于二叉树的左边
	//根节点右边的节点位于二叉树的右边
	vector<int>left_pre, left_in, right_pre, right_in;
	for (int i = 0; i < gen; i++)
	{
		left_in.push_back(inorder[i]);//左子树
		left_pre.push_back(preorder[i+1]);//前序遍历的左子树
	}
	for (int i = gen + 1; i < inlen; i++)
	{
		right_in.push_back(inorder[i]);//右子树
		right_pre.push_back(preorder[i]);//前序遍历的右子树
	}
	//取出前序和中序遍历根节点左边和右边的子树
	//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	root->left=buildTree(left_pre,left_in);//左子树前序 左子树中序
	root->right=buildTree(right_pre,right_in);//右子树前序 右子树中序
	return root;
}


//72. 中序遍历和后序遍历树构造二叉树
//您的提交打败了 97.00% 的提交!
//使用递归的方式来做。
TreeNode * buildTree2(vector<int> &inorder, vector<int> &postorder) 
{
	// write your code here
	if (inorder.empty() || postorder.empty())
	{
		return NULL;
	}
	//先找到根节点。
	int inlen = inorder.size();
	int postlen = postorder.size();
	//创建根节点，后序遍历的最后一个点就是根节点。
	TreeNode *root = new TreeNode(postorder[postlen - 1]);
	//找到中序遍历的根节点的位置。
	int gen = 0;
	for (int i = 0; i < inlen; i++)
	{
		if (inorder[i] == postorder[postlen - 1])
		{
			gen = i;
			break;
		}
	}
	//中序遍历，根节点左边的节点位于二叉树的左边
	//根节点右边的节点位于二叉树的右边
	vector<int>left_post, left_in, right_post, right_in;
	for (int i = 0; i < gen; i++)
	{
		left_in.push_back(inorder[i]);//中序遍历的左子树
		left_post.push_back(postorder[i]);//后序遍历的左子树
	}
	for (int i = gen + 1; i < inlen; i++)
	{
		right_in.push_back(inorder[i]);//中序遍历的右子树
		right_post.push_back(postorder[i - 1]);//后序遍历的右子树
	}
	//取出后序和中序遍历根节点左边和右边的子树
	//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	root->left = buildTree(left_in, left_post);//左子树中序 左子树后序
	root->right = buildTree(right_in, right_post);//右子树中序 右子树后序
	return root;
}


//95. 验证二叉查找树
//您的提交打败了 100.00% 的提交!
//只要中序遍历不是一个递增顺序，则不是二叉查找树
bool isValidBST(TreeNode * root)
{
	// write your code here
	if (root == NULL)
	{
		return true;
	}
	vector<int> inres;//中序遍历的结果是有序的。
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

//11. 二叉查找树中搜索区间
//您的提交打败了 99.00% 的提交!
vector<int> searchRange(TreeNode * root, int k1, int k2) 
{
	// write your code here
	vector<int>res;
	if (root == NULL)
	{
		return res;
	}
	vector<int> inres;//中序遍历的结果是有序的。
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

//177. 把排序数组转换为高度最小的二叉搜索树
//您的提交打败了 60.40% 的提交!
TreeNode *bulidSortedTree(vector<int> &A, int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	//创建根节点。
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



//480. 二叉树的所有路径
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
//您的提交打败了 100.00% 的提交!
//采用递归的思路来做。
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

//726. 验证满二叉树
//您的提交打败了 100.00% 的提交!
//使用递归的思路
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



////7. 二叉树的序列化和反序列化
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

//163. 不同的二叉查找树
//您的提交打败了 93.80% 的提交!
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


//164. 不同的二叉查找树 II
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
	//创建二叉树
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

	cout << "前序遍历:" << endl;
	vector<int> pre = preorderTraversal(p1);
	for (auto i : pre)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "翻转二叉树:" << endl;
	invertBinaryTree(p1);
	vector<int>pre2 = preorderTraversal(p1);
	for (auto i : pre2)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "二叉树的最小深度:";
	int d = minDepth(p1);
	cout << d << endl;




	system("pause");
	return 1;
}
