#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//209. ��һ��ֻ����һ�ε��ַ�
//�����ύ����� 79.00% ���ύ!
//�ύһ�ξͳɹ���
char firstUniqChar(string &str)
{
	// Write your code here
	int m[256] = { 0 };
	for (int i = 0; i < str.size(); i++)
	{
		m[str[i]]++;
	}
	char res;
	for (int i = 0; i < str.size(); i++)
	{
		if (m[str[i]] == 1)
		{
			res = str[i];
			return res;
		}
	}
}