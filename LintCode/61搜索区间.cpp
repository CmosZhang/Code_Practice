#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

//61. 搜索区间
//您的提交打败了 34.60% 的提交!

vector<int> searchRange(vector<int> &A, int target) 
{
	// write your code here
	vector<int>res(2, -1);
	if (A.size() <= 0)
	{
		return res;
	}
	int len = A.size();
	int count = 0;
	int high = 0;
	int flag = 0;
	if (target <= A[len - 1])
	{
		for (int i = 0; i < len; i++)
		{
			if (A[i] == target)
			{
				flag = 1;
				count++;
				high = i;
			}
		}
		if (flag == 1)
		{
			res[0] = high - count + 1;
			res[1] = high;
		}
	}
	return res;
}


//使用二分法来做
//您的提交打败了 100.00% 的提交!
vector<int> searchRange(vector<int> &A, int target)
{
	vector<int>res(2, -1);
	if (A.size() <= 0)
	{
		return res;
	}
	int low = 0;
	int high = A.size() - 1;
	int mid;
	//找左边界
	while (low + 1 < high)
	{
		mid = low + (high - low) / 2;
		if (A[mid] == target)
		{
			high = mid;
		}
		else if (A[mid] > target)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	if (A[low] == target)
	{
		res[0] = low;
	}
	else if (A[high] == target)
	{
		res[0] = high;
	}
	else
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	//寻找右边界
	low = res[0];
	high = A.size() - 1;
	while (low + 1 < high)
	{
		mid = low + (high - low) / 2;
		if (A[mid] == target)
		{
			low = mid;
		}
		else if (A[mid] < target)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}

	}
	if (A[high] == target)
	{
		res[1] = high;
	}
	else if (A[low] == target)
	{
		res[1] = low;
	}
	else
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	return res;
}

int main()
{
	vector<int>nums = { 1,3,5,6,8,9 };
	vector<int>res;
	res = searchRange(nums,7);
	cout << res[0] << endl;
	cout << res[1] << endl;
	system("pause");
	return 1;
}