#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//138. 子数组之和
//您的提交打败了 86.80% 的提交!
vector<int> subarraySum(vector<int> &nums)
{
	// write your code here
	vector<int>res;
	if (nums.empty())
	{
		return res;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum = sum + nums[i];
		//数组只有一个元素，数值为0的情况。
		if (sum == 0)
		{
			res.push_back(i);
			return res;
		}
		for (int j = i + 1; j < nums.size(); j++)
		{
			sum = sum + nums[j];
			if (sum == 0)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
		sum = 0;
	}
}

int main()
{
	vector<int>num = { -3, 1, 2, -3, 4 };
	vector<int>res = subarraySum(num);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}