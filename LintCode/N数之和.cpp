#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//N数之和
//采用回溯的思路来做。
vector<vector<int>> foursum(vector<int>&nums, int target)
{
	vector<vector<int>> res;
	vector<int> cur;
	sort(nums.begin(), nums.end());
	findNsum(nums, target, 4, cur, res);
	return res;
}

void findNsum(vector<int>&nums, int target, int N, vector<int>&cur, vector<vector<int>>&res)
{
	if (N < 2 || nums.size() < N || nums[0] * N > target)
	{
		return;
	}
	if (N == 2)
	{
		int i = 0, j = nums.size() - 1;
		while (i < j)
		{
			if (nums[i] + nums[j] == target)
			{
				vector<int>temp;
				for (int p = 0; p < cur.size(); p++)
					temp.push_back(cur[p]);
				temp.push_back(nums[i]);
				temp.push_back(nums[j]);
				res.push_back(temp);
				while (i < j&&nums[i] == nums[i + 1]) i++;
				while (i < j&&nums[j] == nums[j - 1]) j--;
				i++;
				j--;
			}
			else if (nums[i] + nums[j] < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	else
	{
		for (int k = 0; k < nums.size() - N + 1; k++)
		{
			if (k == 0 || nums[k] != nums[k - 1])
			{
				vector<int> tempNums, tempCur;
				for (int t = k + 1; t < nums.size(); t++)
				{
					tempNums.push_back(nums[t]);
				}
				for (int z = 0; z < cur.size(); z++)
				{
					tempCur.push_back(cur[z]);
				}
				tempCur.push_back(nums[k]);
				findNsum(tempNums, target - nums[k], N - 1, tempCur, res);
			}
		}
	}
}