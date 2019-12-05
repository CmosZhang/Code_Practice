#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//393. 买卖股票的最佳时机 IV
//您的提交打败了 86.20% 的提交!
int maxProfit(int K, vector<int> &prices) 
{
	// write your code here
	if (prices.empty() || K <= 0)
	{
		return 0;
	}
	int len = prices.size();
	//首先，如果 K>=prices.size()/2，意味着有无限次交易次数，那么最大利润自然是每两个交易日之间利润的累加；
	if (K >= len / 2)
	{
		int profit = 0;
		for (int i = 1; i < len; ++i)
		{
			if (prices[i] > prices[i - 1])
			{
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
	vector<vector<int>> dp(K + 1, vector<int>(len + 1, 0));
	for (int i = 1; i < K + 1; ++i)
	{
		int buyLast = -prices[0];
		for (int j = 2; j <= len; ++j) 
		{
			dp[i][j] = max(buyLast + prices[j - 1], dp[i][j - 1]);
			buyLast = max(buyLast, dp[i - 1][j - 1] - prices[j - 1]);
		}
	}
	return dp[K][len];
}

int main()
{
	vector<int> p = { 4,4,6,1,1,4,2,5 };
	int price;
	price = maxProfit(2, p);
	cout << price << endl;
	system("pause");
	return 0;
}