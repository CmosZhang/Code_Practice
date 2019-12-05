#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给定一些物品数组和一个目标值，问有多少种可以组成目标的组合数，
//比如给定物品数组 [2,3,6,7] 和目标值 7, 那么就有2种可能：[7] 和 [2, 2, 3]。所以返回2。
//这道题也可以这样描述：给1，2，5，10硬币无数多个，请问凑80元的方案总数。

//硬币可以重复选择
//状态转移方程：
//dp[i][j]代表前i种硬币凑成j元的方案数量  
//dp[i][j]=dp[i-1][j]+dp[i-1][j-A[i]*1]+dp[i-1][j-A[i]*2]+...+

int backpack(vector<int>&item, int target) {
	int len = item.size();
	vector<vector<int>> dp(len + 1, vector<int>(target, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j <= target; j++) {
			int k = 0;
			while (k*item[i - 1] < j) {
				dp[i][j] += dp[i - 1][j - item[i - 1] * k];
				k++;
			}
		}
	}
	return dp[len][target];
}

//如果硬币不能重复选择，每种硬币只能使用一次
//dp[i][j]表示前i种硬币凑成j元的方案
//dp[i][j] = dp[i-1][j]+dp[i-1][j-A[i]]
//dp[0][0] = 1
int backpack2(vector<int>&item, int target) {
	int len = item.size();
	vector<vector<int>> dp(len + 1, vector<int>(target, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			if (item[i - 1] <= j) {
				dp[i][j] += dp[i - 1][j - item[i - 1]];
			}
		}
	}
	return dp[len][target];
}