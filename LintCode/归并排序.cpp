#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//归并排序
//归并排序是一种稳定的排序方式，时间复杂度为O(nlogn),
//需要一个临时数组来作为辅助空间，空间复杂度为O(n).

//合并两个排序数组，这个需要辅助空间
void Merge(vector<int>&num, int low, int high, int mid)
{
	if (num.empty())
	{
		return;
	}
	int *temp = new int[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (num[i] <= num[j])
		{
			temp[k++] = num[i++];
		}
		else
		{
			temp[k++] = num[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = num[i++];
	}
	while (j <= high)
	{
		temp[k++] = num[j++];
	}
	//将合并后的数组拷贝到原数组中
	for (int i = low, k = 0; i <= high; i++, k++)
	{
		num[i] = temp[k];
	}
	delete[] temp;
}

//然后用二路归并的方式来排序
//采用递归的思路
void merge_sort(vector<int>&num, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		merge_sort(num, low, mid);
		merge_sort(num, mid + 1, high);
		Merge(num, low, high, mid);
	}
}

int main()
{
	vector<int> num = { 8,3,4,5,2,1,3,7,9,4,3,3 };
	merge_sort(num, 0, num.size() - 1);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}