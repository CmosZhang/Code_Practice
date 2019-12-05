#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//77. �����������
//�����ύ����� 84.80% ���ύ!
int longestCommonSubsequence(string &A, string &B)
{
	// write your code here
	if (A.empty() || B.empty())
	{
		return 0;
	}
	int m = A.length();
	int n = B.length();

	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[m][n];
}

int main()
{
	string s1 = "ABCD";
	string s2 = "EACB";
	int res = longestCommonSubsequence(s1, s2);
	cout << res << endl;
	system("pause");
	return 0;
}