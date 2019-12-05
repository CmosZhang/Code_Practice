#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//完全背包问题描述：有编号分别为a,b,c,d的四件物品，它们的重量分别是2,3,4,7，
//它们的价值分别是1,3,5,9，每件物品数量无限个，现在给你个承重为10的背包，
//如何让背包里装入的物品具有最大的价值总和？

//完全背包问题与01背包问题的区别在于每一件物品的数量都有无限个，而01背包每件物品数量只有一个。

//思路：
//dp[i][j]表示前i种物品放入到一个容量为j的背包中获得的最大值，那么对于第i种物品
//我们有k种选择，0<=k*v[i]<=j,即可以选择0、1、2…k个第i种物品
//状态转移方程为：dp[i][j] = max(dp[i-1][j-v[i]*k]+p[i]*k);0<=k*v[i]<=t
//dp[0][j]=0,dp[i][0]=0;

int Knapsack(int n, vector<int>&weight, vector<int>&value) {
	vector<vector<int>>dp(weight.size(), vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[0][i] = (i / weight[0])*value[0];
	}
	for (int i = 1; i < weight.size(); i++) {
		for (int j = 0; j <= n; j++) {
			if (j < weight[i]) {//物品i不能放入背包
				dp[i][j] = dp[i - 1][j];
			}
			else {
				for (int k = 0; k*weight[i] <= j; k++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i] * k] + k * value[i]);
				}
				//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	return dp[weight.size() - 1][n];
}


//方法二：
//空间上的简化：
//i =0 时，只放第一件物品所能获得的最大价值
//i=1时，加上第二件物品所能获得的最大价值
int Knapsack2(int n, vector<int>&weight, vector<int>&value) {
	vector<int>dp(n + 1, 0);
	for (int i = 0; i < weight.size(); i++) {
		for (int j = weight[i]; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp[n];
}

int main() {
	int n = 10;
	vector<int> weight = { 2,3,4,7 };
	vector<int> value = { 1,3,5,9 };
	cout << Knapsack2(n, weight, value) << endl;
	system("pause");
	return 0;
}