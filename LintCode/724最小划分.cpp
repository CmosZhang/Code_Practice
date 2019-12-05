#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//724. 最小划分
//
int findMin(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	int sumt = sum;
	sum = sum / 2;
	vector<int> dp(sumt + 1, 0);
	dp[0] = 1;
	// 背包问题思路，求解总和为j的分配是否存在
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = sum; j >= nums[i]; j--)
		{
			dp[j] += dp[j - nums[i]];
		}
	}
	//从后往前遍历，存在总和最大的j时，即是最小的划分
	for (int i = sum; i >= 0; i--)
	{
		if (dp[i] != 0)
			return abs(i * 2 - sumt);
	}
}