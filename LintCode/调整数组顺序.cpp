#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//题目要求：
//讲等于0的数字排列在数组后面，不等于0的数字排列在数组前面，并保持数组有序
//思路：先将0排到后面，然后针对前面的数字进行快排


void partitionArray(vector<int> &nums)
{
	// write your code here
	if (nums.empty())
	{
		return;
	}
	int len = nums.size();
	int start = 0;
	int end = len - 1;
	while (start<end)
	{
		while (nums[start] != 0 && start < end)
		{
			start++;
		}
		while (nums[end] == 0 && start < end)
		{
			end--;
		}
		if (start < end)
		{
			swap(nums[start], nums[end]);
		}
	}
	sort(nums.begin(), nums.begin() + start);//这一步可以换成自己写的快排
}


int main()
{
	vector<int> nums = { 5,3,2,4,0,5,0,8,2,0,1,0,9 };
	partitionArray(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}