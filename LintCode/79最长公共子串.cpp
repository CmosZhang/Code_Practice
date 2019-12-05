#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//79. 最长公共子串
//
//您的提交打败了 81.80% 的提交!
//int longestCommonSubstring(string &A, string &B) 
//{
//	int Alen = A.size();
//	int Blen = B.size();
//	if (Alen == 0 || Blen == 0)
//	{
//		return 0;
//	}
//	int max = 0;
//	for (int i = 0; i < Alen; i++)
//	{
//		for (int j = 0; j < Blen; j++)
//		{
//			int m = i, n = j;
//			int len = 0;
//			while (m < Alen && n < Blen)
//			{
//				if (A[m] != B[n])
//				{
//					break;
//				}
//				m++;
//				n++;
//				len++;
//			}
//			if (len > max)
//			{
//				max = len;
//			}
//		}
//	}
//	return max;
//}

//使用动态规划解法
//您的提交打败了 81.40% 的提交!
int longestCommonSubstring(string &A, string &B)
{
	if (A.empty() || B.empty())
	{
		return 0;
	}
	int m = A.length();
	int n = B.length();

	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				res = max(dp[i + 1][j + 1], res);
			}
			else
			{
				dp[i + 1][j + 1] = 0;
			}
		}
	}
	return res;
}

int main()
{
	string s1 = "ABCD";
	string s2 = "CBCE";
	int res = longestCommonSubstring(s1, s2);
	cout << res << endl;
	system("pause");
	return 0;
}