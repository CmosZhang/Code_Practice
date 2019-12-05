#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//65. 两个排序数组的中位数
//挑战
//时间复杂度为O(log n)
//您的提交打败了 7.20% 的提交!

//选择排序
void SelectSort(vector<int>&a, int n) //选择排序
{
	int mix, temp;
	for (int i = 0; i<n - 1; i++) //每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
	{
		mix = i; //假设最小元素的下标
		for (int j = i + 1; j<n; j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (a[j]<a[mix])
				mix = j;
		//若数组中真的有比假设的元素还小，就交换
		if (i != mix)
		{
			temp = a[i];
			a[i] = a[mix];
			a[mix] = temp;
		}
	}
}
double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
	// write your code here
	int n = B.size();
	for (int i = 0; i < n; i++)
	{
		A.push_back(B[i]);
	}

	int m = A.size();
	int left = 0, right = m;

	//选择排序
	SelectSort(A, m);
	double res;
	//找中位数
	int mid = (left + right) / 2;
	//cout << mid << endl;
	if (m % 2 == 0)
	{
		//double res = (A[mid] + A[mid - 1]) / 2;
		return res = (A[mid] + A[mid - 1]) / 2.0;
	}
	else
	{
		return A[mid];
	}
}

int main()
{
	vector<int>A = { 1,2,3,4,5,6 };
	vector<int>B = { 2,3,4,5 };

	double res = findMedianSortedArrays(A, B);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << res << endl;
	system("pause");
	return 0;
}