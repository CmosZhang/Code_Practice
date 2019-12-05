#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


//633. 寻找重复的数
//您的提交打败了 75.40% 的提交!
//题目所要求的方法。
int findhelper(vector<int>&nums, int len, int start, int middle)
{
	if (nums.empty())
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] >= start && nums[i] <= middle)
		{
			count++;
		}
	}
	return count;
}

int findDuplicate(vector<int> &nums) 
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int start = 1;
	int len = nums.size();
	int end = len - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = findhelper(nums, len, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return 0;
}


//利用哈希映射来做。
//这种情况下，使用了辅助空间
int findDuplicate(vector<int> &nums)
{
	if (nums.empty())
	{
		return 0;
	}
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (m.find(nums[i]) != m.end()) 
			return nums[i];
		++m[nums[i]];
	}
}

int main()
{
	vector<int>num = { 5,5,4,3,2,1 };
	int ans = findDuplicate(num);
	cout << ans << endl;
	system("pause");
	return 0;
}