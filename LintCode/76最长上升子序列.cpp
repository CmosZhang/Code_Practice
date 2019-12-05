#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//76. 最长上升子序列
//您的提交打败了 81.20% 的提交!
int longestIncreasingSubsequence(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	vector<int> dp(len, 1);
	int res = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}

//使用二分法来做
int help(vector<int>&arr, int arr_size, int target) {
	int start = 0;
	int end = arr_size - 1;
	int middle;
	while (start + 1 < end) {
		middle = start + (end - start) / 2;
		if (target == arr[middle]) {
			end = middle;
			continue;
		}
		if (target < arr[middle]) {
			end = middle;
			continue;
		}
		start = middle;
	}
	if (arr[start] >= target) {
		return start;
	}
	if (arr[end] >= target) {
		return end;
	}
	return -1;
}

int longestIncreasingSubsequence(vector<int> &nums) {
	// write your code here
	if (nums.size() == 0) {
		return 0;
	}
	if (nums.size() == 1) {
		return 1;
	}
	int len = nums.size();
	vector<int> arr(len + 1, INT_MAX);
	arr[0] = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		int index = help(arr, nums.size() + 1, nums[i]);
		arr[index] = nums[i];
	}
	for (int i = nums.size(); i > 0; i--) {
		if (arr[i] != INT_MAX) {
			return i;
		}
	}
}


int main()
{
	vector<int> nums = { 9,3,6,2,7 };
	cout << longestIncreasingSubsequence(nums) << endl;
	system("pause");
	return 0;
}