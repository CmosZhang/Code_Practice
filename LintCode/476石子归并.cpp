#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//476. ʯ�ӹ鲢
//��̬�滮����Ŀ
//dp[i][j]��ʾmerge��i��j��stones�ķ�����
//dp[i][j]=min(dp[i][k],dp[k+1][j])+sum[i][j]
//�����ύ����� 99.60% ���ύ!
int stoneGame(vector<int> &A) {
	// write your code here
	if (A.empty()) {
		return 0;
	}
	int n = A.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<int> sum(n, 0);
	sum[0] = A[0];
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + A[i];
	}
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i + len < n; ++i) {
			dp[i][i + len] = INT_MAX;
			int temp = sum[i + len] - sum[i - 1];
			for (int k = i; k < i + len; ++k) {
				dp[i][i + len] = min(dp[i][i + len], dp[i][k] + dp[k + 1][i + len] + temp);
			}
		}
	}
	return dp[0][n - 1];
}