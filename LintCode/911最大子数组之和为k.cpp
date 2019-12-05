#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>

using namespace std;

//911. 最大子数组之和为k
//暴力求解
//您的提交打败了 9.20% 的提交!
//时间复杂度为O(n^2)
int maxSubArrayLen(vector<int> &nums, int k) {
	// Write your code here
	if (nums.empty())
	{
		return 0;
	}
	int res = INT_MIN;
	int sum = 0;
	int len = nums.size();
	if (len == 1 && nums[0] == k)
	{
		res = 1;
	}
	for (int i = 0; i < len - 1; i++)
	{
		sum += nums[i];
		for (int j = i + 1; j < len; j++)
		{
			sum += nums[j];
			if (sum == k)
			{
				res = max(res, j - i + 1);
			}
		}
		sum = 0;
	}
	return res;
}

//题目要求
//时间复杂度为O(n)
//用map维护前缀和对应的最大终点位置，然后枚举子数组开始位置，在map中进行查找
//从下标为 0 到下标为 100，和 sum = 2000，
//假设我们要求的目标 k=800，那么我们只要知道从 0 开始，
//最早出现的下标 i，使得 0 到 i 之间的和为 1200，
//这样就能保证 i+1 到 1000 的和为 800，
//同时还能保证这个长度是以 1000 结尾的最大的长度
int maxSubArrayLen(vector<int> &nums, int k) {
	if (nums.empty())
	{
		return 0;
	}
	unordered_map<int, int>m;
	int n = nums.size();
	vector<int> sum(n + 1, 0);
	m[k] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + nums[i - 1];
		if (m.find(sum[i]) != m.end())
		{
			ans = max(ans, i - m[sum[i]]);
		}
		if (m.find(sum[i] + k) == m.end())
		{
			m[sum[i] + k] = i;
		}
	}
	return ans;
}