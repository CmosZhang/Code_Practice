#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};


//599. 向循环有序链表插入节点
//当链表中只有一个值的时候出错
//您的提交打败了 93.00% 的提交!
//时间复杂度还是比较高
ListNode * insert(ListNode * node, int x)
{
	// write your code here
	ListNode *dummy = new ListNode(x);
	if (node == NULL)
	{
		node = dummy;
		node->next = node;
		return node;
	}
	ListNode *cur = node;
	ListNode *pre = NULL;
	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
		//找到插入的位置
		if (x <= cur->val&&x >= pre->val)
		{
			break;
		}
		//链表循环处特殊判断（最大值->最小值），如果x小于最小值或x大于最大值，在此处插入
		if (pre->val > cur->val && (x < cur->val || x>pre->val))
		{
			break;
		}
		//循环一圈
		if (cur == node)
		{
			break;
		}
	}
	//插入该结点
	dummy->next = cur;
	pre->next = dummy;
	return dummy;
}