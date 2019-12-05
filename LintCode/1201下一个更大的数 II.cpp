#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

//1201. 下一个更大的数 II
//您的提交打败了 89.33% 的提交!
vector<int> nextGreaterElements(vector<int> &nums) {
	// Write your code here
	if (nums.empty())
	{
		return nums;
	}
	vector<int> res(nums.size(), -1);
	int i = 0;
	stack<int> s;
	for (int i = 0; i < 2 * nums.size(); i++)
	{
		int num = nums[i%nums.size()];
		while (!s.empty() && nums[s.top()] < num)
		{
			res[s.top()] = num;
			s.pop();
		}
		if (i < nums.size())
		{
			s.push(i);
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 2,5,1,2 };
	vector<int> res = nextGreaterElements(nums);
	for (int i = 0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}