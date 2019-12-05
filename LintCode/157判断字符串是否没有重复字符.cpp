#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//157. �ж��ַ����Ƿ�û���ظ��ַ�
//�����ύ����� 84.80% ���ύ!
//���⣬û�е���ֱ��ͨ����
bool isUnique(string &str) 
{
	// write your code here
	if (str.size() <= 0)
	{
		return true;
	}
	int m[256] = { 0 };
	for (int i = 0; i < str.size(); i++)
	{
		m[str[i]]++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (m[str[i]] > 1)
		{
			return false;
		}
	}
	return true;
}