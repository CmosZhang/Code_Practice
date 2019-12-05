#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//669. 换硬币
//您的提交打败了 35.40% 的提交!
int coinChange(vector<int> &coins, int amount)
{
	// write your code here
	if (coins.empty() || amount <= 0)
	{
		return 0;
	}
	int len = coins.size();
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < amount + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i >= coins[j] && dp[i - coins[j]] < INT_MAX)
			{
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
			}
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
	vector<int> coins = { 1, 2, 5 };
	int amount = 11;
	cout << coinChange(coins, amount) << endl;
	system("pause");
	return 0;
}
