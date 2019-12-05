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


//599. ��ѭ�������������ڵ�
//��������ֻ��һ��ֵ��ʱ�����
//�����ύ����� 93.00% ���ύ!
//ʱ�临�ӶȻ��ǱȽϸ�
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
		//�ҵ������λ��
		if (x <= cur->val&&x >= pre->val)
		{
			break;
		}
		//����ѭ���������жϣ����ֵ->��Сֵ�������xС����Сֵ��x�������ֵ���ڴ˴�����
		if (pre->val > cur->val && (x < cur->val || x>pre->val))
		{
			break;
		}
		//ѭ��һȦ
		if (cur == node)
		{
			break;
		}
	}
	//����ý��
	dummy->next = cur;
	pre->next = dummy;
	return dummy;
}