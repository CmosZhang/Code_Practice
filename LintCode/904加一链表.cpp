#include<iostream>
#include<vector>
#include<string>
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

//904. ��һ����
//�����ύ����� 86.27% ���ύ!
//����һ
//string addStrings(string &num1, string &num2)
//{
//	// write your code here
//	string res = "";
//
//	//�Ƚ�������Ū�ɳ���һ��
//	if (num1.size() < num2.size())
//	{
//		num1 = string(num2.size() - num1.size(), '0') + num1;
//	}
//	else
//	{
//		num2 = string(num1.size() - num2.size(), '0') + num2;
//	}
//	//��λ
//	int carry = 0;
//	for (int i = num1.size() - 1; i >= 0; --i)//��λ�������
//	{
//		char temp = (num1[i] - '0' + num2[i] - '0' + carry) % 10 + '0';
//		res = temp + res;
//		//cout << res << endl;
//		carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
//	}
//	if (carry)
//		res = '1' + res;
//	return res;
//}
//ListNode * plusOne(ListNode * head) 
//{
//	// Write your code here
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	string num1 = "";
//	while (head != NULL)
//	{
//		char temp = head->val + '0';
//		num1 = num1 + temp;
//		head = head->next;
//	}
//	string num2 = "1";
//	string res = addStrings(num1, num2);
//	ListNode *dummy = new ListNode(0);
//	ListNode *s = dummy;
//	for (int i = 0; i < res.size(); i++)
//	{
//		int temp = res[i] - '0';
//		ListNode *newNode = new ListNode(temp);
//		s->next = newNode;
//		s = s->next;
//	}
//	s->next = NULL;
//	return dummy->next;
//}

//������
//���ϵ������
//���������ҵ������һ����Ϊ9�����֣�����Ҳ������������֣�
//˵���������־�Ϊ9����ô�ڱ�ͷ�½�һ��ֵΪ0���½ڵ㣬���м�1����Ȼ����ұ����е����ֶ���Ϊ0���ɡ�
//�����ύ����� 86.27% ���ύ!
ListNode* plusOne(ListNode* head) 
{
	ListNode* cur = head, *right = NULL;
	while (cur)
	{
		if (cur->val != 9)
			right = cur;
		cur = cur->next;
	}
	if (!right)
	{
		right = new ListNode(0);
		right->next = head;
		head = right;
	}
	right->val++;
	cur = right->next;
	while (cur)
	{
		cur->val = 0;
		cur = cur->next;
	}
	return head;
}