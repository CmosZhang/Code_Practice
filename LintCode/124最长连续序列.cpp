#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

//124最长连续序列。打败100%的提交。
int longestConsecutive(vector<int> &num)
{
	// write your code here
	if (num.size() <= 0)
	{
		return 0;
	}
	int len = num.size();
	sort(num.begin(), num.end());//排序好
	int count = 1;
	int length = 1;
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len&&num[i] + 1 == num[i + 1])//判断连续。
		{
			length++;//满足这个条件的话，序列最短都是2.所以length的初始值要设置为1. 
			count = max(length, count);//有多段连续的序列，找到最大的序列。
		}
		else if (i + 1 < len&&num[i] == num[i + 1])//处理重复元素
		{
			continue;
		}
		else
		{
			length = 1;
		}
	}
	return count;
}

int main()
{
	vector<int>nums = {1,3,2,4,3,2,3};
	int res = longestConsecutive(nums);
	cout << res << endl;
	system("pause");
	return 1;
}