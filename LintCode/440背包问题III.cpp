#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>

using namespace std;


//440. ±≥∞¸Œ Ã‚ III
//
int backPackIII(vector<int> &A, vector<int> &V, int m) {
	// write your code here
	if (A.empty() || V.empty()) {
		return 0;
	}
	int n = A.size();
	vector<int> dp(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*A[i - 1] <= m; j++) {
			for (int k = m; k >= A[i - 1]; k--) {
				dp[k] = max(dp[k], dp[k - A[i - 1]] + V[i - 1]);
			}
		}
	}
	return dp[m];
}