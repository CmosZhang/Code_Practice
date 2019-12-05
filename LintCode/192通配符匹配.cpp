#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//192. 通配符匹配
//您的提交打败了 81.20% 的提交!
//使用动态规划来做
bool isMatch(string &s, string &p)
{
	// write your code here
	if (s.empty() && p.empty())
	{
		return true;
	}
	int slen = s.size();
	int plen = p.size();

	vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));

	dp[0][0] = true;
	for (int i = 1; i < slen + 1; i++)
	{
		dp[i][0] = false;
	}
	for (int i = 1; i < plen + 1; i++)
	{
		dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
	}
	for (int i = 1; i <= slen; i++)
	{
		for (int j = 1; j <= plen; j++)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
			}
			else if (p[j - 1] == '?')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
			}
		}
	}
	return dp[slen][plen];
}


//bool isMatch(string &s, string &p) 
//{
//
//	if (s.empty() && p.empty())
//	{
//		return true;
//	}
//
//	if (p.empty())
//	{
//		return false;
//	}
//
//	if (s.empty()) 
//	{
//		for (int i = 0; i < p.size(); ++i)
//		{
//			if (p[i] != '*')
//			{
//				return false;
//			}
//		}
//	}
//
//	vector<vector<bool>>DP(s.size(), vector<bool>(p.size(), false));
//
//
//
//	for (int i = s.size() - 1; i >= 0; --i) 
//	{
//		bool visitChar = false;
//		for (int j = p.size() - 1; j >= 0; --j)
//		{
//			if (j == p.size() - 1) 
//			{
//				if (p[j] == '*') 
//				{
//					DP[i][j] = true;
//				}
//				if (i == s.size() - 1 && (s[i] == p[j] || p[j] == '?'))
//				{
//					DP[i][j] = true;
//					visitChar = true;
//				}
//				continue;
//			}
//			if (DP[i][j + 1] == true)
//			{
//				if (p[j] == '*') 
//				{
//					DP[i][j] = true;
//				}
//				else if (!visitChar && (s[i] == p[j] || p[j] == '?'))
//				{
//					visitChar = true;
//					DP[i][j] = true;
//				}
//			}
//			if (i == s.size() - 1) 
//			{
//				continue;
//			}
//			if (DP[i + 1][j] == true) 
//			{
//				if (p[j] == '*') 
//				{
//					DP[i][j] = true;
//				}
//			}
//			if (DP[i + 1][j + 1] == true) 
//			{
//				if (s[i] == p[j]) 
//				{
//					visitChar = true;
//					DP[i][j] = true;
//				}
//				if (p[j] == '?') 
//				{
//					visitChar = true;
//					DP[i][j] = true;
//				}
//				if (p[j] == '*') 
//				{
//					DP[i][j] = true;
//				}
//			}
//		}
//	}
//
//	return DP[0][0];
//}


int main()
{
	string s = "aa";
	string p = "*";
	cout << isMatch(s, p) << endl;
	system("pause");
	return 0;
}