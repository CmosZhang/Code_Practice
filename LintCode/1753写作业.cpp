#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//1753. 写作业
//您的提交打败了 78.65% 的提交!
long long search(vector<int>&sums, int target)
{
	if (target >= sums[sums.size() - 1])
	{
		return sums[sums.size() - 1];
	}
	if (target < sums[0])
	{
		return -1;
	}
	int left = 0; 
	int right = sums.size() - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (sums[mid] <= target && sums[mid + 1] > target)
		{
			return sums[mid];
		}
		else if (sums[mid] > target&&sums[mid - 1] <= target)
		{
			return sums[mid - 1];
		}
		else if (sums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

long long doingHomework(vector<int> &cost, vector<int> &val)
{
	// Write your code here.
	long long ans = 0;
	int len = cost.size();
	int sum = 0;
	vector<int> sums(len, 0);
	for (int i = 0; i < len; i++)
	{
		sum = sum + cost[i];
		sums[i] = sum;
	}
	for (int j = 0; j < val.size(); j++)
	{
		long long temp = search(sums, val[j]);
		if (temp != -1)
		{
			ans = ans + temp;
		}
	}
	return ans;
}