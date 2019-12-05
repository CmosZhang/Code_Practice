#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给一些不同价值和数量的硬币。找出这些硬币可以组合在1 ~ n范围内的值的数量


int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
	int m = value.size();
	vector<bool> dp(n + 1, false);
	int res = 0;
	dp[0] = true;
	for (int i = 0; i < m; i++) {
		vector<int> cnt(n + 1, 0);
		for (int j = value[i]; j <= n; j++) {
			if (!dp[j] && dp[j - value[i]] && cnt[j - value[i]] < amount[i]) {
				cnt[j] = cnt[j - value[i]] + 1;
				res++;
				dp[j] = true;
			}
		}
	}
	return res;
}