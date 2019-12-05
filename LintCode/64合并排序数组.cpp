#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


int Partition(int a[], int left, int right);
void quickSort(int a[], int left, int right);
void SelectSort(int a[], int n);

//合并排序数组
//void mergeSortedArray(int A[], int m, int B[], int n) 
//{
//	// write your code here
//	for (int i = 0; i < n; i++)
//	{
//		A[m + i] = B[i];
//	}
//	//使用冒泡排序  
//	//int temp;
//	//for (int j = 0; j < m + n - 1; j++)
//	//{
//	//	for (int k = 0; k < m + n - 1 - j; k++)
//	//	{
//	//		if (A[k]>A[k + 1])
//	//		{
//	//			temp = A[k];
//	//			A[k] = A[k + 1];
//	//			A[k + 1] = temp;
//	//		}
//	//	}
//	//}
//
//	////使用快速排序
//	//int left = 0, right = m + n - 1;
//	//quickSort(A,left,right);
//
//
//	//使用选择排序
//	SelectSort(A, m + n);
//}

void mergeSortedArray(int A[], int m, int B[], int n)
{
	int a = m - 1, b = n - 1, index = m + n - 1;
	while (a >= 0 && b >= 0)
	{
		if (A[a] > B[b])
		{
			A[index] = A[a];
			index--;
			a--;
		}
		else
		{
			A[index] = B[b];
			index--;
			b--;
		}
	}
	while (a >= 0)//数组B为空
	{
		A[index] = A[a];
		index--;
		a--;
	}
	while (b >= 0)//数组A为空
	{
		A[index] = B[b];
		index--;
		b--;
	}
}

int Partition(int a[], int left, int right)
{
	int temp = a[left];
	while (right>left)
	{
		while (left<right&&a[right]>=temp)
		{
			right--;
		}
		a[left] = a[right];
		//			cout << "a[left] =" <<a[left] << "    ";
		while (left<right&&a[left]<=temp)
		{
			left++;
		}
		a[right] = a[left];
		//			cout << "a[right] =" <<a[right] << endl;
	}
	a[right] = temp;
	return left;
}
void quickSort(int a[], int left, int right)
{
	if (left<right)
	{
		int pos = Partition(a, left, right);
		//		cout << pos <<endl;
		quickSort(a, left, pos - 1);
		quickSort(a, pos + 1, right);
	}
}

//选择排序
void SelectSort(int a[], int n) //选择排序
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

//合并排序数组2
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) 
{
	// write your code here
	vector<int> v;
	int m, n, k;
	m = A.size();
	n = B.size();
	for (int i = 0; i < m; ++i)
	{
		v.push_back(A[i]);
	}
	for (int j = 0; j < n; ++j)
	{
		v.push_back(B[j]);
	}
	k = v.size();
	int temp;
	for (int i = 0; i< k - 1; ++i)
	{
		for (int j = 0; j< k - 1 - i; ++j)
		{
			if (v[j]>v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	return v;
}

int main()
{
	int A[7] = {2,4,7,8};
	int m = 4;
	int B[] = {3,5,9};
	int n = 3;
	mergeSortedArray(A, 4, B, 3);
	for (int i = 0; i < m + n ; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}