#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


void recoverRotatedSortedArray(vector<int> &nums)
{
	// write your code here
	//最简单方法
	//sort(nums.begin(),nums.end());//打败82.8%的提交。
	if (nums.empty()) 
		return;
	for (int i = 0; i < nums.size() - 1; i++) 
	{
		if (nums[i] > nums[i + 1]) 
		{        //找到起始数字
			for (int j = 0; j <= i; j++) 
			{
				nums.push_back(nums[0]);
				nums.erase(nums.begin());
			}
			break;
		}
	}//打败98.2%的提交。
}

int main()
{
	vector<int>nums = { 4, 5, 1, 2, 3 };
	recoverRotatedSortedArray(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}