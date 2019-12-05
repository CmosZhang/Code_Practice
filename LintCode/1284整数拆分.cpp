#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//1284. 整数拆分
//您的提交打败了 87.67% 的提交!
int integerBreak(int n)
{
	// Write your code here
	if (n <= 0)
	{
		return 0;
	}

	vector<int> dp(n + 1, 0);
	//
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;//设定好初始值
		if (i == n)
		{
			dp[i] = 0;
		}
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i - j] * j, dp[i]);
		}
	}
	return dp[n];
}

int main()
{
	int n = 10;
	cout << integerBreak(n) << endl;
	system("pause");
	return 0;
}