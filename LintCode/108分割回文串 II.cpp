#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

//108. 分割回文串 II
//您的提交打败了 38.40% 的提交!
//先利用动态规划的方式，找到这个字符串中所有的回文子串
vector<vector<bool>> getIsPalindrome(string &s)
{
	vector<vector<bool>> Palindrome(s.size(), vector<bool>(s.size(), false));
	for (int i = 0; i < s.size(); i++)
	{
		Palindrome[i][i] = true;
	}
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			Palindrome[i][i + 1] = true;
		}
	}

	for (int i = s.size() - 1; i >= 0; i--)
	{
		for (int j = i + 2; j < s.size(); j++)
		{
			Palindrome[i][j] = Palindrome[i + 1][j - 1] && (s[i] == s[j]);
		}
	}

	return Palindrome;
}

int minCut(string &s) {
	// write your code here
	if (s.empty() || s.size() == 1)
	{
		return 0;
	}
	vector<vector<bool>> Palindrome = getIsPalindrome(s);

	vector<int> dp(s.size() + 1, 0);
	dp[0] = -1;
	for (int i = 1; i <= s.size(); i++)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (Palindrome[j][i - 1])
			{
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	return dp[s.size()];
}

int main()
{
	string s = "aab";
	cout << minCut(s) << endl;
	system("pause");
	return 0;
}