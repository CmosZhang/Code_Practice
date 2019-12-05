#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//1093. 最长升序子序列的个数
//还是得使用动态规划的方法
//dp[i] 代表以第 i 个数结尾的最长上升子序列的长度。
//ans[i] 代表以第 i 个数结尾的最长上升子序列的个数。
//dp[i] = max(dp[j] + 1), nums[j] < nums[i]。
//ans[i] = sum(ans[j]), nums[j] < nums[i] and dp[j] == dp[i] - 1。
//您的提交打败了 49.41% 的提交!
int findNumberOfLIS(vector<int> &nums) {
	// Write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	vector<int> dp(len, 0);
	dp[0] = 1;
	vector<int> ans(len, 0);
	ans[0] = 1;
	int max_len = 1;
	for (int i = 1; i < len; i++)
	{
		dp[i] = 1;
		ans[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[j]<nums[i] && dp[j] + 1>dp[i])
			{
				dp[i] = dp[j] + 1;
				ans[i] = ans[j];
			}
			else if (nums[j] < nums[i] && dp[j] + 1 == dp[i])
			{
				ans[i] += ans[j];
			}
		}
		if (dp[i] > max_len)
		{
			max_len = dp[i];
		}
	}
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		if (dp[i] == max_len)
		{
			res += ans[i];
		}
	}
	return res;
}
