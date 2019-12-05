#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

//1119. 三个数的最大乘积
//您的提交打败了 99.22% 的提交!
int maximumProduct(vector<int> &nums)
{
	// Write your code here
	if (nums.empty())
	{
		return 0;
	}
	int ans;
	int max = INT_MIN, second_max = INT_MIN, third_max = INT_MIN;
	int min = INT_MAX, second_min = INT_MAX;
	int n = nums.size();
	for (int i = 0; i<n; i++)
	{
		if (max<nums[i])
		{
			third_max = second_max;
			second_max = max;
			max = nums[i];
		}
		else if (second_max<nums[i])
		{
			third_max = second_max;
			second_max = nums[i];
		}
		else if (third_max<nums[i])
		{
			third_max = nums[i];
		}
		if (nums[i]<min)
		{
			second_min = min;
			min = nums[i];
		}
		else if (nums[i]<second_min)
		{
			second_min = nums[i];
		}
	}
	int max1 = max * second_max*third_max;
	int max2 = max * second_min*min;
	if (max1 >= max2)
	{
		ans = max1;
	}
	else
	{
		ans = max2;
	}
	return ans;
}