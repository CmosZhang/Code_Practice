#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>

using namespace std;


//563. ±³°üÎÊÌâ V
//
int backPackV(vector<int> &nums, int target) {
	// write your code here
	if (nums.empty()) {
		return -1;
	}
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= target; i++) {
		dp[i] == (i == nums[0]) ? (dp[i] + 1) : 0;
	}
	for (int i = 1; i < nums.size(); i++) {
		for (int j = target; j - nums[i] >= 0; j--) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[target];
}
