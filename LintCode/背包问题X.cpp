#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//你总共有n元，商人总共有三种商品，它们的价格分别是150元,250元,350元，
//三种商品的数量可以认为是无限多的，购买完商品以后需要将剩下的钱给商人作为小费，
//求最少需要给商人多少小费

//思路：完全背包问题，每个物品可以取无限多

int backPackX(int n) {
	// write your code here
	vector<int>dp(n + 1, 0);
	int prices[3] = { 150,250,350 };
	for (int i = 0; i < 3; i++) {
		for (int j = prices[i]; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - prices[i]] + prices[i]);
		}
	}
	int res = n - dp[n];
	return res;
}