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


int sumNumbers(TreeNode * root);
////1353. ���ڵ㵽Ҷ�ڵ����
////
int sumNumbers(TreeNode * root) {
	// write your code here
	if (root == NULL) {
		return 0;
	}
}

int main() {
	

}

