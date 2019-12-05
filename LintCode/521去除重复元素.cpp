#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//521. È¥³ıÖØ¸´ÔªËØ
int deduplication(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int len = nums.size();
	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (nums[i] == nums[j])
			{
				count++;
			}
		}
	}
	return len - count;
}