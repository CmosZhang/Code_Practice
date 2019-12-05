#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

//460. 在排序数组中找最接近的K个数
//您的提交打败了 24.60% 的提交!
int FindTargetIndex(vector<int>&A, int target)
{
    int low = 0, high = A.size() - 1;
	while (low + 1 < high)
	{
		int mid = low + (high - low) / 2;
		if (A[mid] < target)
		{
			low = mid;
		}
		else if (A[mid] > target)
		{
			high = mid;
		}
		else
		{
			return mid;
		}
	}
	return high;
}

vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
	// write your code here
	vector<int> ans(k, 0);
	if (A.empty() || A.size() == 0)
	{
		return ans;
	}
	if (k > A.size())
	{
		return A;
	}
	int index = FindTargetIndex(A, target);
	int left = index - 1;
	int right = index;
	//for循环换成while语句，用push_back来做也可以
	for (int i = 0; i < k; i++)
	{
		if (left < 0)
		{
			ans[i] = A[right];
			right++;
		}
		else if (right >= A.size())
		{
			ans[i] = A[left];
			left--;
		}
		else
		{
			if (target - A[left] <= A[right] - target)
			{
				ans[i] = A[left];
				left--;
			}
			else
			{
				ans[i] = A[right];
				right++;
			}
		}
	}
	return ans;
}


int main()
{
	vector<int> A = { 1,2,3 };
	int k = 3;
	int target = 2;
	vector<int> res = kClosestNumbers(A, target, k);
	for (int i = 0; i < k; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}