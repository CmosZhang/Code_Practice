#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

//200������Ӵ�
//Memory Limit Exceeded,�ڴ泬�����ơ�
bool isPalindrome(string s)
{
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

/*
string longestPalindrome(string &s) 
{
	// write your code here
	if (s.empty())
	{
		return s;
	}
	int len = s.size();
	int maxlen = 0;
	vector<string> res;
	string maxString;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			if (isPalindrome(s.substr(i, j)))
			{
				int temp = j;
				if (j > maxlen)  //��ͬ��С���ִ�֮�洢һ����
				{
					maxlen = j;
					maxString = s.substr(i, j);
				}
				//cout << temp << endl;

			}
		}
	}
	//cout << maxlen << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]<< endl;
		if (res[i].size() == maxlen)
		{
			maxString = res[i];
		}
	}
	return maxString;
}
*/

/*
//������⡣
string longestPalindrome(string &s)
{
	// write your code here
	if (s.empty())
	{
		return s;
	}
	int len = s.size();
	int maxlen = 0;
	string maxString;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			if (isPalindrome(s.substr(i, j)))
			{
				int temp = j;
				if (j > maxlen)
				{
					maxlen = j;
					maxString = s.substr(i, j);
				}
			}
		}
	}
	return maxString;
}
*/


//ʹ�ö�̬�滮�㷨
/**
string longestPalindrome(string &s)
{
	int length = s.size();
	if (length == 1)
	{
		return s;
	}
	int maxlength = 0;
	int start;
	bool P[50][50] = { false };
	for (int i = 0; i<length; i++)//��ʼ��׼��
	{
		P[i][i] = true;
		if (i<length - 1 && s[i] == s[i+1])
		{
			P[i][i + 1] = true;
			start = i;
			maxlength = 2;
		}
	}
	for (int len = 3; len<length; len++)//�Ӵ�����
		for (int i = 0; i <= length - len; i++)//�Ӵ���ʼ��ַ
		{
			int j = i + len - 1;//�Ӵ�������ַ
			if (P[i + 1][j - 1] && s[i] == s[j])
			{
				P[i][j] = true;
				maxlength = len;
				start = i;
			}
		}
	if (maxlength >= 2)
		return s.substr(start, maxlength);
	return NULL;
}
*/


//ʹ���������㷨
//���ڻ��Ĵ��ĳ��ȿ����ż������"bob"��������ʽ�Ļ��ģ�"noon"����ż����ʽ�Ļ��ģ�
//�������㷨�ĵ�һ����Ԥ����
//��������ÿһ���ַ������Ҷ�����һ�������ַ����������'#'����ô
//bob-->    #b#o#b#
//noon-->    #n#o#o#n# 
//�������ĺô��ǲ���ԭ�ַ�������������ż����������֮��õ����ַ����ĸ�������������
//�����ύ����� 87.00% ���ύ!
string PostProcess(string &s)
{
	string res = "%#";  //
	if (s.empty() || s.length() == 1)
	{
		return s;
	}
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		res = res + s[i];
		res = res + '#';
	}
	return res;
}

//��������ֻҪ�ҵ������İ뾶����֪����Ļ����Ӵ����ַ������ˡ�
//ֻ֪�������޷���λ�Ӵ������ǻ���Ҫ֪���Ӵ�����ʼλ�á�   
string longestPalindrome(string &s)
{
	if (s.empty() || s.size() == 1)
	{
		return s;
	}
	//�õ�Ԥ������ַ���
	string temp = PostProcess(s);

	//�������㷨�ĺ���
	//�ҳ��Ӵ�����ʼλ��
	vector<int> p(temp.size(), 0);
	int mx = 0, id = 0, resLen = 0, resCenter = 0;
	for (int i = 1; i < temp.size(); ++i) 
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (temp[i + p[i]] == temp[i - p[i]])
			++p[i];
		if (mx < i + p[i]) 
		{
			mx = i + p[i];
			id = i;
		}
		if (resLen < p[i]) 
		{
			resLen = p[i];
			resCenter = i;
		}
	}
	return s.substr((resCenter - resLen) / 2, resLen - 1);
}



int main()
{
	string s = "noon";
	string ans = longestPalindrome(s);
	cout << ans << endl;
	system("pause");
	return 0;
}