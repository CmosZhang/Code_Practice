#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//29.交叉字符串
//不需要动态规划来做，直接递归做就可以啊
//您的提交打败了 69.00% 的提交!
/*
bool isInterleave(string s1, string s2, string s3) 
{
	// write your code here
	if (s1.length() + s2.length() != s3.length()) 
	{
		return false;
	}
	if (s3.length() == 0 && s1.length() == 0 && s2.length() == 0)
	{
		return true;
	}
	int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
	if (len1 == 0 || len2 == 0)
	{
		if (len1 == 0)
		{
			return s3.compare(s2) == 0 ? true : false;
		}
		else
		{
			return s3.compare(s1) == 0 ? true : false;
		}
	}
	if (s1[0] == s2[0] && s2[0] == s3[0])
	{
		return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
	}
	else if (s1[0] == s3[0])
	{
		return isInterleave(s1.substr(1), s2, s3.substr(1));
	}
	else if (s2[0] == s3[0])
	{
		return isInterleave(s1, s2.substr(1), s3.substr(1));
	}
	else
	{
		return false;
	}
}*/

bool isInterleave(string s1, string s2, string s3)
{
	// write your code here
	if (!(s1.length() != 0 || s2.length() != 0 || s3.length() != 0))
		return true;

	if (s1.length() + s2.length() != s3.length()) 
		return false;

	if (s1[0] == s3[0] && s2[0] != s3[0])
		return isInterleave(s1.substr(1), s2, s3.substr(1));
	else if (s2[0] == s3[0] && s1[0] != s3[0])
		return isInterleave(s1, s2.substr(1), s3.substr(1));
	else if (s2[0] == s3[0] && s1[0] == s3[0])
		return(isInterleave(s1, s2.substr(1), s3.substr(1)) || isInterleave(s1.substr(1), s2, s3.substr(1)));
	else 
		return false;
}


//使用动态规划
//您的提交打败了 69.00% 的提交!
bool isInterleave(string &s1, string &s2, string &s3) 
{
	// write your code here
	if (s1.length() + s2.length() != s3.length())
	{
		return false;
	}
	if (s3.length() == 0 && s1.length() == 0 && s2.length() == 0)
	{
		return true;
	}
	vector<vector<bool>> interleave(s1.length() + 1, vector<bool>(s2.length() + 1, false));
	interleave[0][0] = true;
	for (int i = 1; i <= s1.length(); i++) 
	{
		interleave[i][0] = interleave[i - 1][0] && s1[i - 1] == s3[i - 1];
	}
	for (int i = 1; i <= s2.length(); i++)
	{
		interleave[0][i] = interleave[0][i - 1] && s2[i - 1] == s3[i - 1];
	}

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++) 
		{
			interleave[i][j] = false;
			if (s1[i - 1] == s3[i + j - 1])
			{
				interleave[i][j] = interleave[i][j] || interleave[i - 1][j];
			}
			if (s2[j - 1] == s3[i + j - 1])
			{
				interleave[i][j] = interleave[i][j] || interleave[i][j - 1];
			}
		}
	}
	return interleave[s1.length()][s2.length()];
}

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	bool flag = isInterleave(s1, s2, s3);
	cout << flag << endl;
	system("pause");
	return 0;
}