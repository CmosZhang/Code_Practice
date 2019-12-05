#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//700. 杆子分割
//您的提交打败了 99.13% 的提交!
int cutting(vector<int> &prices, int n) 
{
	// Write your code here
	if (prices.empty() || n <= 0)
	{
		return 0;
	}
	int len = prices.size();
	vector<int> dp(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + prices[j - 1]);
		}
	}
	return dp[n];
}

int main()
{
	vector<int> prices = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n = 8;
	cout << cutting(prices, n) << endl;
	system("pause");
	return 0;
}
