#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//1667. 区间统计
//您的提交打败了 79.31% 的提交!
long long intervalStatistics(vector<int> &arr, int k) 
{
	// Write your code here.
	if (arr.empty() || arr.size() == 0)
	{
		return 0;
	}
	int len = arr.size();
	int left = 0, right = 0;
	long long ans = 0;
	long long numofOne = 0;

	while (right < len)
	{
		if (arr[right] == 1)
		{
			numofOne++;
			right++;
			continue;
		}
		if (arr[left] == 1)
		{
			numofOne--;
			left++;
			continue;
		}
		while (numofOne > k) 
		{
			if (arr[left] == 1)
			{
				numofOne--;
			}
			left++;
		}
		ans += right - left + 1 - numofOne;
		right++;
	}
	return ans;
}

int main()
{
	vector<int> nums = { 0, 0, 1, 0, 1, 1, 0 };
	int k = 1;
	long long res = intervalStatistics(nums, k);
	cout << res << endl;
	system("pause");
	return 0;
}