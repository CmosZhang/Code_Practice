#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

//532.逆序对
//直接遍历求
//时间复杂度太高
//88% 数据通过测试
//long long reversePairs(vector<int> &A)
//{
//	// write your code here
//	if (A.empty())
//	{
//		return 0;
//	}
//	long long ans = 0;
//	for (int i = 0; i < A.size() - 1; i++)
//	{
//		for (int j = i + 1; j < A.size(); j++)
//		{
//			if (A[j] < A[i])
//			{
//				ans++;
//			}
//		}
//	}
//	return ans;
//}

//您的提交打败了 100.00% 的提交!
long long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end)
{
	if (begin == end)
	{
		copy[begin] = data[begin];
		return 0;
	}
	long long L = (end - begin) / 2;

	long long left = InversePairsCore(copy, data, begin, begin + L);
	long long right = InversePairsCore(copy, data, begin + L + 1, end);

	int i = begin + L;
	int j = end, inxcopy = end;

	long long count = 0;
	while (i >= begin && j >= begin + L + 1) 
	{
		if (data[i]>data[j]) 
		{
			copy[inxcopy--] = data[i--];
			count += j - begin - L;
		}
		else copy[inxcopy--] = data[j--];
	}
	//for(i=begin;i<=end;i++) copy[i]=data[i];
	for (; i >= begin; i--) copy[inxcopy--] = data[i];
	for (; j >= begin + L + 1; j--) copy[inxcopy--] = data[j];
	return left + right + count;
}
//
//long long reversePairs(vector<int> &A)
//{
//	// write your code here
//	if (A.empty() || A.size() < 2)
//	{
//		return 0;
//	}
//	vector<int> copy;
//	for (int i = 0; i < A.size(); i++)
//	{
//		copy.push_back(A[i]);
//	}
//	long long ans = InversePairsCore(A, copy, 0, A.size() - 1);
//
//	copy.clear();
//	return ans % 1000000007;
//}


long long InversePairsCore(vector<int>&data, vector<int>&copy, int begin, int end)
{
	if (begin == end)
	{
		copy[begin] = data[begin];
		return 0;
	}

	long long mid = (end - begin) / 2;

	long long left = InversePairsCore(copy, data, begin, begin + mid);
	long long right = InversePairsCore(copy, data, begin + mid + 1, end);

	long long i = begin + mid;
	long long j = end, inxcopy = end;

	long long count = 0;//统计逆序对的个数
	while (i >= begin && j >= begin + mid + 1)
	{
		if (data[i]>data[j])//只有前半部分的数值大于后半部分的数值才有可能组成逆序对。
		{
			copy[inxcopy--] = data[i--];
			count += j - begin - mid;
		}
		else
		{
			copy[inxcopy--] = data[j--];
		}
	}
	while (i >= begin)
	{
		copy[inxcopy--] = data[i--];
	}
	while (j >= begin + mid + 1)
	{
		copy[inxcopy--] = data[j--];
	}
	return left + right + count;
}

long long reversePairs(vector<int>&A)
{
	if (A.empty() || A.size()<2)
	{
		return 0;
	}
	vector<int> copy;
	for (int i = 0; i<A.size(); i++)
	{
		copy.push_back(A[i]);
	}
	long long ans = InversePairsCore(A, copy, 0, A.size() - 1);
	copy.clear();
	return ans % 1000000007;
}


int main()
{
	vector<int> nums = { 2, 4, 1, 3, 5 };
	long long res = reversePairs(nums);
	cout << res << endl;
	system("pause");
	return 0;
}