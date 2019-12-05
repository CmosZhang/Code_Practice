#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//31. 数组划分
//您的提交打败了 64.40% 的提交!
int partitionArray(vector<int> &nums, int k)
{
	// write your code here
	if (nums.empty())
	{
		return 0;
	}
	int start = 0;
	int end = nums.size() - 1;
	while (start < end)
	{
		while(nums[start] < k)
		{
			start++;
		}
		while(nums[end] >= k)
		{
			end--;
		}
		if (start <= end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
	}
	int i = 0;
	while (i < nums.size()) 
	{
		if (nums[i] >= k)
		{
			break;
		}
		i++;
	}
	return i;
}


int main()
{
	vector<int>num = { 9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9 };
	int k = 9;
	int res = partitionArray(num,k);
	cout << res << endl;
	system("pause");
	return 1;
}