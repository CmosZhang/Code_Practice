#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;


//1310. 数组除了自身的乘积
//您的提交打败了 94.44% 的提交!
vector<int> productExceptSelf(vector<int> &nums) 
{
	// write your code here
	if (nums.empty())
	{
		return nums;
	}
	int len = nums.size();
	vector<int> res(len, 0);
	for (int i = 0; i < len; i++)
	{
		int start = 0;
		int end = len - 1;
		int left_mul = 1;
		while (start < i)
		{
			left_mul = left_mul * nums[start];
			start++;
		}
		int right_mul = 1;
		while (end > i)
		{
			right_mul = right_mul * nums[end];
			end--;
		}
		res[i] = left_mul * right_mul;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,4,5,2 };
	vector<int> res = productExceptSelf(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}