#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//371.用递归打印数字
//您的提交打败了 19.40% 的提交!
void helper(vector<int>&res, int n, int ans)
{
	if (n == 0) 
	{
		if (ans > 0) 
		{
			res.push_back(ans);
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		helper(res, n - 1, ans * 10 + i);
	}
}

vector<int> numbersByRecursion(int n) 
{
	// write your code here
	vector<int> res;
	if (n <= 0)
	{
		return res;
	}
	helper(res, n, 0);
	return res;
}
