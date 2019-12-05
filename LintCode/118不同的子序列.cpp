#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//118. 不同的子序列
//您的提交打败了 99.60% 的提交!
int numDistinct(string &S, string &T)
{
	// write your code here
	if (S.size() == 0 && T.size() != 0)
	{
		return 0;
	}

	int len1 = S.size();
	int len2 = T.size();

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

	//初始条件
	for (int i = 0; i <= len1; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 1; j <= len2; j++)
	{
		dp[0][j] = 0;
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (S[i - 1] == T[j - 1])
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[len1][len2];
}

int main()
{
	string s1 = "rabbbit";
	string s2 = "rabit";
	int res = numDistinct(s1, s2);
	cout << res << endl;
	system("pause");
	return 0;
}