#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//17. 子集
//您的提交打败了 100.00% 的提交!
void helper(vector<vector<int>>&res, int len, vector<int>&nums, vector<int>temp)
{
	if (len == nums.size())
	{
		res.push_back(temp);
		return;
	}
	else
	{
		helper(res, len + 1, nums, temp);
		temp.push_back(nums[len]);
		helper(res, len + 1, nums, temp);
	}
}

vector<vector<int>> subsets(vector<int> &nums) 
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(),nums.end());
	vector<int> temp;
	helper(res, 0, nums, temp);
	return res;
}

//方法二
//用DFS来做
//您的提交打败了 100.00% 的提交!
void dfs(vector<vector<int>>&res, vector<int>nums, vector<int>&temp, int index)
{
	res.push_back(temp);
	for (int i = index; i < nums.size(); i++)
	{
		if (i != index && nums[i] == nums[i - 1])
			continue;
		temp.push_back(nums[i]);
		dfs(res, nums, temp, i + 1);
		temp.pop_back();
	}
}

//18. 子集 II
//您的提交打败了 100.00% 的提交!
//把重复元素删掉
vector<vector<int>> subsetsWithDup(vector<int> &nums) 
{
	// write your code here
	vector<vector<int>> res;
	if (nums.empty())
	{
		res.push_back(nums);
		return res;
	}
	sort(nums.begin(), nums.end());
	vector<int> temp;
	//helper(res, 0, nums, temp);
	//sort(res.begin(), res.end());
	//res.erase(unique(res.begin(), res.end()), res.end());//把相邻的重复元素放到最后，然后删除
	dfs(res, nums, temp, 0);
	return res;
}


int main()
{
	vector<int> nums = { 1,1,2,3,2,2 };
	vector<vector<int>> res = subsetsWithDup(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
 	system("pause");
	return 0;
}