#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//75. 寻找峰值
/*注意事项
It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.*/
//下面的代码没有任何问题，就是时间复杂度太高。
//尝试用二分法。
//int findPeak(vector<int> &A)
//{
//	// write your code here
//	if (A.size() <= 2)
//	{
//		return -1;
//	}
//	int len = A.size();
//	for (int i = 1; i < len - 1; i++)
//	{
//		if (A[i] > A[i - 1] && A[i] > A[i + 1])
//		{
//			return i;
//		}
//	}
//}

//二分法，打败96.4%的提交，不容易想到。
//int findPeak(vector<int> &A)//不用考虑A异常的情况
//{
//	int len = A.size();
//	int low = 0;
//	int high = len - 1;
//	int mid;
//	while (low < high)
//	{
//		mid = (low + high) / 2;
//		if (mid == 0)//数组长度为2 循环导致数组不断减小。
//		{
//			return 1;//如果不加前两个if,else if,算法运行时间会增加。
//			//不加这两个打败56%的提交，加上打败96.4%的提交。
//		}
//		else if (mid == len - 1)//数组长度为1
//		{
//			return mid - 1;
//		}
//		else if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
//		{
//			return mid;
//		}
//		else if (A[mid] < A[mid - 1])
//		{
//			high = mid - 1;//左侧存在峰值
//		}
//		else
//		{
//			low = mid + 1;//右侧存在峰值
//		}
//	}
//}

//利用双指针法打败99.4%的提交，这个容易想到。
int findPeak(vector<int> &A)
{
	int start = 1, end = A.size() - 2;
	while (start <= end)
	{
		if (A[start] > A[start - 1] && A[start] > A[start + 1])
			return start;
		else start++;
		if (A[end] > A[end - 1] && A[end] > A[end + 1])
			return end;
		else end--;
	}
	return -1;
}

int main()
{
	vector<int>nums = { 1, 2, 1, 3, 4, 5, 7, 6 };
	int res2;
	res2 = findPeak(nums);
	cout << res2 << endl;
	system("pause");
	return 1;
}