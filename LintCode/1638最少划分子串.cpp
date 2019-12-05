#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//1638. ���ٻ����Ӵ�
//�����ύ����� 81.74% ���ύ!
int getAns(string &s, int k)
{
	// Write your code here
	int len = s.size();
	if (len <= 0 || k < 0)
	{
		return 0;
	}
	int res = 1;
	int count = 1;
	for (int i = 1; i < len; i++)
	{
		if (s[i] != s[i - 1])//�Ӵ��е���ĸ������ͬ,ͬʱ�Ӵ�����ĸ����������k
		{
			res++;
			count = 1;
		}
		else 
		{
			if (count < k)
			{
				count++;
			}
			else if (count == k)
			{
				res++;
				count = 1;
			}

		}
	}
	return res;
}


int main()
{
	string s = "aabbbc";
	int k = 2;
	int res = getAns(s, k);
	cout << res << endl;
	system("pause");
	return 1;
}