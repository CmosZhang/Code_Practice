#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


//377. ջ��push-pop����
//�����ύ����� 67.90% ���ύ!
bool isLegalSeq(vector<int> &push, vector<int> &pop) 
{
	// write your code here
	if (push.empty() || pop.empty() || push.size() != pop.size())
	{
		return false;
	}
	int index = 0;
	stack<int>mystack;
	for (int i = 0; i<pop.size(); i++)
	{
		while (mystack.empty() || mystack.top() != pop[i])
		{
			if (index >= push.size())
				//�����Ҫѹ���Ԫ�ظ�������pushV��Ԫ�ظ�����˵��popV��������pushV�ĵ�������
				return false;
			mystack.push(push[index++]);
		}
		//��ջ��Ԫ����popV��ǰԪ�����ʱ����ջ��Ԫ�ص�����������popV��һ��Ԫ��
		if (mystack.top() == pop[i])
			mystack.pop();
	}
	return true;
}