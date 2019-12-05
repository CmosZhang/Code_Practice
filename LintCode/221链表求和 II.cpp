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



//221. 链表求和 II
//您的提交打败了 92.40% 的提交!
string addStrings(string &num1, string &num2)
{
	// write your code here
	string res = "";

	//先将两个数弄成长度一致
	if (num1.size() < num2.size())
	{
		num1 = string(num2.size() - num1.size(), '0') + num1;
	}
	else
	{
		num2 = string(num1.size() - num2.size(), '0') + num2;
	}
	//进位
	int carry = 0;
	for (int i = num1.size() - 1; i >= 0; --i)//个位在最后面
	{
		char temp = (num1[i] - '0' + num2[i] - '0' + carry) % 10 + '0';
		res = temp + res;
		//cout << res << endl;
		carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
	}
	if (carry)
		res = '1' + res;
	return res;
}

ListNode * addLists2(ListNode * l1, ListNode * l2) 
{
	// write your code here
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	string num1 = "";
	while (l1 != NULL)
	{
		char temp1 = l1->val + '0';
		num1 = num1 + temp1;
		l1 = l1->next;
	}
	//cout << num1;
	string num2 = "";
	while (l2 != NULL)
	{
		char temp2 = l2->val + '0';
		num2 = num2 + temp2;
		l2 = l2->next;
	}
	string res = addStrings(num1,num2);
	ListNode *dummy = new ListNode(0);
	ListNode *s = dummy;
	for (int i = 0; i < res.size(); i++)
	{
		int temp = res[i] - '0';
		ListNode *newNode = new ListNode(temp);
		s->next = newNode;
		s = s->next;
	}
	s->next = NULL;
	return dummy->next;
}