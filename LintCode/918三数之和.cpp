#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//918. 三数之和
//您的提交打败了 81.63% 的提交!
int threeSumSmaller(vector<int> &nums, int target) {
	// Write your code here
	if (nums.empty() || nums.size() < 3)
	{
		return -1;
	}
	int count = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum >= target)
			{
				right--;
			}
			else
			{
				count += right - left;
				left++;
			}
		}
	}
	return count;
}