#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//假设你身上有 n 元，超市里有多种大米可以选择，每种大米都是袋装的，
//必须整袋购买，给出每种大米的重量，价格以及数量，求最多能买多少公斤的大米

//其实这个问题可以看作是一个多重背包问题,在01背包的基础上多了一重循环


//思路：把物品的不同数量的打包看作是不同的物品
//然后使用0-1背包的方法解决
//f[i]为身上有i元时，最多买的大米数量
//状态转移方程为：f[i] = max(f[i],f[k-prices[i]]+weight[i]);
int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
	int m = prices.size();
	vector<int> f(n + 1, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= amounts[i]; j++) {
			for (int k = n; k >= prices[i]; k--) {
				f[k] = max(f[k], f[k - prices[i]] + weight[i]);
			}
		}
	}
	return f[n];
}

int main() {
	int V, m;
	while (cin >> V >> m) {
		vector<int> amount(m);
		vector<int> weight(m);
		vector<int> prices(m);
		for (int i = 0; i < m; i++) {
			cin >> amount[i] >> weight[i] >> prices[i];
		}
		cout << backPackVII(V, weight,prices , amount) << endl;
	}
}