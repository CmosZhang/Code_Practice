#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//514Õ¤À¸È¾É«
int numWays(int n, int k) 
{
	// write your code here
	if (n <= 0 || k <= 0)
	{
		return 0;
	}
	vector<int> dp(n, 0);
	dp[0] = k;
	dp[1] = k * k;
	for (int i = 2; i < n; i++)
	{
		dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
	}
	return dp[n - 1];
}