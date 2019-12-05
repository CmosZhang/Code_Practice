#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//62搜索旋转排序数组
int search(vector<int> &A, int target) 
{
	// write your code here
	if (A.size() <= 0)
	{
		return -1;
	}
	int l = A.size();
	int low = 0, high = l - 1, mid;
	//数组顺序被打乱，成为旋转排序
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		else if (A[mid] < A[high])
		{
			if (A[mid] < target && A[high] >= target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		else
		{
			if (A[low] <= target && A[mid] > target)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	return -1;
}

//63. 搜索旋转排序数组 II
//直接暴力求解，居然打败100%的提交，没有使用任何技巧。
//九章给的标准答案就是暴力求解
//bool searchII(vector<int> &A, int target)
//{
//	// write your code here
//	if (A.size() <= 0)
//	{
//		return false;
//	}
//	int l = A.size();
//	sort(A.begin(), A.end());
//	for (int i = 0; i<l; i++)
//	{
//		if (A[i] == target)
//		{
//			return true;
//		}
//	}
//	return false;
//}

//使用二分法
//您的提交打败了 100.00% 的提交!
bool searchII(vector<int> &A, int target)
{
	// write your code here
	if (A.size() <= 0)
	{
		return false;
	}
	int len = A.size();
	int low = 0, high = len - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (A[mid] == target)
		{
			return true;
		}
		if (A[low] < A[mid])//后半部分不一定有序
		{
			if (A[low] <= target && target < A[mid])//说明前半部分是有序的
				high = mid - 1;
			else
				low = mid + 1;
		}
		else if (A[low] > A[mid])//说明前半部分并不一定有序，
		{
			if (A[mid] < target && target <= A[high])//后半部分是有序的
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			//If nums[start] == nums[mid], just move start to the next index. 
			//So the worst case, that the array's elements are same, is O(n).
			low++;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 4,5,6,7,0,1,2,3};
	int res = search(nums,1);
	cout << res << endl;
	system("pause");
	return 1;
}