#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//379. 将数组重新排序以构造最小值
//您的提交打败了 96.40% 的提交!
static bool cmp(int a, int b)
{
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);
	return A < B;
}

string minNumber(vector<int> &nums) 
{
	// write your code here
	string res = "";
	if (nums.empty())
	{
		return res;
	}

	sort(nums.begin(), nums.end(), cmp);
	bool flag = false;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			res = res + to_string(nums[i]);
			flag = true;
		}
		else if (flag)
		{
			res = res + to_string(nums[i]);
		}
	}
	if (flag == false)
	{
		return "0";
	}
	return res;
}

int main()
{
	vector<int> num = { 0,1 };
	cout << minNumber(num) << endl;
	system("pause");
	return 0;
}