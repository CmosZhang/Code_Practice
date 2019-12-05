#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//43. 最大子数组 III
//
int maxSubArray(vector<int> &nums, int k) 
{
	// write your code here
	if (nums.empty() || k <= 0)
	{
		return 0;
	}
	int len = nums.size();
	vector<vector<int>> dp(k + 1, vector<int>(len + 1, 0));


}