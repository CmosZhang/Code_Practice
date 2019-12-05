#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//52. 下一个排列
//您的提交打败了 100.00% 的提交!
vector<int> nextPermutation(vector<int> &nums)
{
	// write your code here
	vector<int> res;
	if (nums.size() <= 0)
	{
		return res;
	}
	for (int i = nums.size() - 1; i >= 0; i--) 
	{
		for (int j = nums.size() - 1; j > i; j--)
		{
			if (nums[i] < nums[j])
			{
				swap(nums[i], nums[j]);
				sort(nums.begin() + i + 1, nums.end());
				return nums;
			}
		}
	}
	sort(nums.begin(), nums.end());
	return nums;
}


int main()
{
	vector<int> nums = { 1,3,2,3 };
	vector<int> res;
	res = nextPermutation(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}