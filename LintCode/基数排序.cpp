//基数排序
//算法的时间复杂度为O(n*digit),digit代表最大数的位数
//空间复杂度为：O(n)
//稳定性：稳定
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//遍历序列找出最大的数（为的是确定最大的数是几位数）
int GetMaxDigit(vector<int>&arr, size_t n)
{
	int digit = 1;
	int base = 10;
	for (size_t i = 0; i < n; i++)
	{
		while (arr[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	return digit;
}

//基数排序，从低位到高位排
void radixSort(vector<int>&arr, size_t n)
{
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int *tmp = new int[n];//辅助空间
	while (digit--)
	{
		int count[10] = { 0 };

		//统计某一位出现相同数字的个数
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			count[index]++;
		}

		int start[10] = { 0 };
		//统计个位相同的数在数组arr中出现的位置
		for (size_t i = 1; i < n; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		//初始化tmp数组
		memset(tmp, 0, sizeof(int)*n);
		
		//从桶中重新排序数据
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			tmp[start[index]++] = arr[i];
		}

		//将tmp数组中的元素拷贝回原数组
		for (int i = 0; i < n; i++)
		{
			arr[i] = tmp[i];
		}
		base *= 10;
	}
	delete[] tmp;
}

int main()
{
	vector<int> num = { 123,234,543,6789,547,673,78,23,123,324 };
	radixSort(num, num.size());
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}