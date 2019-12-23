#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//46. 主元素
//您的提交打败了 13.80% 的提交!
bool CheckMore(vector<int>&nums, int len, int res)
{
	if (nums.empty())
	{
		return false;
	}
	int times = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == res)
		{
			times++;
		}
	}
	bool flag = true;
	if (times * 2 <= len)
	{
		flag = false;
	}
	return flag;
}

int majorityNumber(vector<int> &nums) {
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	int res = nums[0];
	int times = 1;
	for (int i = 1; i < len; i++)
	{
		if (times == 0)
		{
			res = nums[i];
			times = 1;
		}
		else if (nums[i] == res)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if (!CheckMore(nums, len, res))
	{
		res = 0;
	}
	return res;
}
