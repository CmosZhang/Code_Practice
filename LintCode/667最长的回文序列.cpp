#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


//667. ��Ļ�������
//�����ύ����� 100.00% ���ύ!
int longestPalindromeSubseq(string &s) {
	// write your code here
	if (s.empty())
	{
		return 0;
	}
	int len = s.size();
	//ʹ�ö�̬�滮�ķ�ʽ����
	vector<vector<int>>dp(len, vector<int>(len, 0));
	for (int i = len - 1; i >= 0; i--)
	{
		dp[i][i] = 1;
		for (int j = i + 1; j < len; j++)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][len - 1];
}