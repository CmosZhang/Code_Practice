//double类型的数组排序
//要求复杂度为O(n)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//使用基数排序的方式
void radixSort(double input[], long long length)
{
	double *tmp_12 = (double *)malloc((length + 10) * sizeof(double));//辅助空间
	long long negCnt = 0; //记录负数的个数
	int bucket[65536];

	//将64位划分成4个字节，1次排序1个字节
	for (int i = 0; i < 4; i++)
	{
		//计数器清零
		for (int j = 0; j < 65536; j++)
			bucket[j] = 0;
		//统计计数
		int digit = i * 16;
		for (long long j = 0; j < length; j++)
			bucket[reinterpret_cast<unsigned long long&>(input[j]) >> digit & 0xffff]++;
		//计算各段的起始位置
		for (int j = 1; j < 65536; j++)
			bucket[j] = bucket[j - 1] + bucket[j];
		//复制到临时数组，并记录负数的个数
		for (long long j = length - 1; j >= 0; j--)
		{
			int temp = --bucket[reinterpret_cast<unsigned long long&>(input[j]) >> digit & 0xffff];
			tmp_12[temp] = input[j];
			if ((i == 0) && input[j] < 0)
			{
				negCnt++;
			}
		}
		//将临时数组中的数复制到原数组
		//在最后一遍排序时得到的顺序：正数从小到大，负数从大到小
		//所以我们将正负数的位置翻转到从小到大排列的正确位置
		for (long long j = 0; j < length; j++)
		{
			if (i == 3)
			{
				if (tmp_12[j] < 0.0)
					input[length - 1 - j] = tmp_12[j];
				else
					input[negCnt + j] = tmp_12[j];
			}
			else
				input[j] = tmp_12[j];
		}
	}
	free(tmp_12);
}

int main()
{
	double input[] = { 3.23,6.854,12.8,79.5,1.0,0.23,-0.9 };
	radixSort(input, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}