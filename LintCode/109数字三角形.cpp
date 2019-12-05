#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


//109. ����������
//�����ύ����� 89.20% ���ύ!
int minimumTotal(vector<vector<int>> &triangle) 
{
	// write your code here
	if (triangle.empty())
	{
		return 0;
	}
	int len = triangle.size();
	vector<int> dp(len, 0);
	for (int i = 0; i < len; i++)
	{
		dp[i] = triangle[len - 1][i];
	}
	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		}
	}
	return dp[0];
}