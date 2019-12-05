#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//92. 背包问题
//您的提交打败了 39.00% 的提交!
int backPack(int m, vector<int> &A) 
{
	// write your code here
	if (A.empty() || m <= 0)
	{
		return 0;
	}
	int len = A.size();
	vector<vector<int>> dp(m + 1, vector<int>(len + 1, 0));

    //i代表背包容量
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (A[j - 1] > i)//当前大小大于剩余背包容器
			{
				dp[i][j] = dp[i][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], A[j - 1] + dp[i - A[j - 1]][j - 1]);
			}
		}
	}
	return dp[m][len];
}

int main()
{
	vector<int> nums = { 12,3,7,4,5,13,2,8,4,7,6,5,7 };
	int m = 90;
	int res = backPack(m, nums);
	cout << res << endl;
	system("pause");
	return 0;
}