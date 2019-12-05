#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//464. 整数排序 II
//使用快速排序会导致时间超出限制。
int Partition(vector<int>&a, int left, int right);
void quickSort(vector<int>&a, int left, int right);

int Partition(vector<int>&a, int left, int right)
{
	int temp = a[left];
	while (left < right)
	{
		while (left<right&&a[right]>temp)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right&&a[left] < temp)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[right] = temp;
	return left;
}

void quickSort(vector<int>&a, int left, int right)
{
	if (left<right)
	{
		int pos = Partition(a, left, right);
		//		cout << pos <<endl;
		quickSort(a, left, pos - 1);
		quickSort(a, pos + 1, right);
	}
}

void sortIntegers2(vector<int> &A)
{
	// write your code here
	if (A.size() <= 0)
	{
		return;
	}
	int left = 0;
	int right = A.size() - 1;
	quickSort(A, left, right);
}