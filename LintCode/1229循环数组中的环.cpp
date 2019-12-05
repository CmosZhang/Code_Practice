#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//1229. 循环数组中的环
//暴力求解
//您的提交打败了 98.31% 的提交!
bool circularArrayLoop(vector<int> &nums) {
	// Write your code here
	if (nums.empty())
	{
		return false;
	}
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == 0)
		{
			continue;
		}
		int cur = nums[i];
		nums[i] = 0;//从这个位置出发，随后返回这个位置的时候，就不需要再计算从这个位置出发是否可以形成环，要不会一直循环下去
		//移动到的下一个位置
		int next = (i + cur + len) % len;
		if (next == i)//没有发生移动
		{
			continue;
		}
		while (cur*nums[next] > 0)//方向要固定，要么一直往左，要么一直往右
		{
			cur = nums[next];
			nums[next] = 0;//与上面同样的道理
			next = (cur + next + len) % len;
		}
		if (next == i)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 2,-1,1,2,2};
	cout << circularArrayLoop(nums) << endl;
	system("pause");
	return 0;
}