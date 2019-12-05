#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>

using namespace std;

//994. 连续数组
//
int findMaxLength(vector<int> &nums) 
{
	// Write your code here
	if (nums.size() <= 0)
	{
		return 0;
	}
	int sum = 0;
	int len = nums.size();
	int count = 0;
	unordered_map<int, int> m{ { 0, -1 } };
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == 0)
		{
			sum = sum - 1;
		}
		else
		{
			sum = sum + 1;
		}
		if (m.count(sum)) 
		{
			count = max(count, i - m[sum]);
		}
		else 
		{
			m[sum] = i;
		}
	}
	return count;
}

int main()
{
	vector<int> nums = { 0,1,0,0,0,1,1,1,0,0 };
	int res = 0;
	res = findMaxLength(nums);
	cout << res << endl;
	system("pause");
	return 0;
}