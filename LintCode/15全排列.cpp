#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//15全排列。
//您的提交打败了 88.40% 的提交!

//使用递归的方式来做。
//递归解法
//例如，nums = [1, 2, 3, 4]求全排列，有四个位置
//当第一个元素为1时，相当于求2, 3, 4的全排列，
//而在此排列中，当2为第一个元素时，相当于求3, 4的全排列，
//又可以继续划分，3为第一个元素，4本身为一个全排列...
//当第一个元素为2时，相当于求1, 3, 4的全排列，
//而在此排列中，当1为第一个元素时，相当于求3, 4的全排列，
//又可以继续划分，3为第一个元素，4本身为一个全排列...

//求全排列
void per(vector<int> nums, int start, vector<vector<int> > &result) 
{ 
	if (start == nums.size() - 1)
	{ 
		result.push_back(nums);
	} 
	else 
	{
		for (int i = start; i<nums.size(); i++)
		{ 
			if (nums[i] != nums[start] || i == start)
			{
				swap(nums[start], nums[i]);
				per(nums, start + 1, result);
				//swap(nums[start], nums[i]);
			}
		}
	} 
}

vector<vector<int>> permute(vector<int> &nums) 
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(), nums.end());
	per(nums, 0, res);
	return res;
}

//16. 带重复元素的排列
//您的提交打败了 76.00% 的提交!
void per2(vector<int> nums, int start, vector<vector<int> > &result)
{
	if (start == nums.size() - 1)
	{
		result.push_back(nums);
	}
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			if (nums[i] != nums[start] || i == start)
			{
				swap(nums[start], nums[i]);
				per(nums, start + 1, result);
				//swap(nums[start], nums[i]);
			}
		}
	}
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(), nums.end());
	per2(nums, 0, res);
	return res;
}



int main()
{
	vector<int> nums = {1,2,3};
	vector<vector<int>>res;
	res = permute(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}