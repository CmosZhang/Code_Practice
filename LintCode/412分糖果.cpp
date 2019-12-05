#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//412. 分糖果
//您的提交打败了 35.00% 的提交!
int candy(vector<int> &ratings) {
	// write your code here
	if (ratings.empty())
	{
		return 0;
	}
	int res = 0;
	int len = ratings.size();
	vector<int> nums(len, 1);
	for (int i = 0; i < len - 1; i++)
	{
		if (ratings[i + 1] > ratings[i])
		{
			nums[i + 1] = nums[i] + 1;
		}
	}
	for (int i = len - 1; i > 0; i--)
	{
		if (ratings[i - 1] > ratings[i])
		{
			nums[i - 1] = max(nums[i - 1], nums[i] + 1);
		}
	}
	for (int i = 0; i < len; i++)
	{
		res += nums[i];
	}
	return res;
}

int main()
{
	vector<int> rating = { 1, 2,1 };
	cout << candy(rating) << endl;
	system("pause");
	return 0;
}