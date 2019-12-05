#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个包含了一些数字的数组，和一个目标值，从数组里面取数做排列，
//使得排列的数字的和等于target。问有多少种排列方法。数字是阔以重复取出来的。
//比如给定数组[1, 2, 4]和target值4。那么能得到如下的组合。总共有6种，则返回6.


int backPackVI(vector<int>&nums, int target) {
	vector<int> dp(target + 1);
	dp[0] = 1;
	for (int i = 1; i <= target; i++) {
		for (auto num : nums) {
			if (i >= num) {
				dp[i] += dp[i - num];
			}
		}
	}
	return dp[target];
}