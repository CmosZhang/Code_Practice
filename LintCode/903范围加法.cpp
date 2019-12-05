#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//903. 范围加法
//Time Limit Exceeded
//92% 数据通过测试
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
	// Write your code here
	vector<int> nums(length, 0);
	if (updates.empty() || updates[0].empty())
	{
		return nums;
	}
	for (int i = 0; i < updates.size(); i++)
	{
		if (updates[i][0] >= 0 && updates[i][0] < length)
		{
			for (int j = updates[i][0]; j <= updates[i][1] && j < length; j++)
			{
				nums[j] = nums[j] + updates[i][2];
			}
		}
	}
	return nums;
}
//方法二：
//您的提交打败了 93.73% 的提交!
//坐标型动态规划
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
	// Write your code here
	vector<int> nums(length, 0);
	if (updates.empty() || updates[0].empty())
	{
		return nums;
	}
	vector<int> add(length + 1, 0);
	for (int i = 0; i < updates.size(); i++)
	{
		int start = updates[i][0];
		int end = updates[i][1];
		int inc = updates[i][2];
		add[start] += inc;
		add[end + 1] -= inc;
	}
	nums[0] = add[0];
	for (int i = 1; i < nums.size(); i++)
	{
		nums[i] = nums[i - 1] + add[i];
	}
	return nums;
}

int main()
{
	int l = 5;
	vector<vector<int>> up = { {1,3,2},{2,4,3},{0,2,-2} };
	vector<int> res = getModifiedArray(l, up);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}