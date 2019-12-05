//��������
//�㷨��ʱ�临�Ӷ�ΪO(n*digit),digit�����������λ��
//�ռ临�Ӷ�Ϊ��O(n)
//�ȶ��ԣ��ȶ�
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//���������ҳ���������Ϊ����ȷ���������Ǽ�λ����
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

//�������򣬴ӵ�λ����λ��
void radixSort(vector<int>&arr, size_t n)
{
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int *tmp = new int[n];//�����ռ�
	while (digit--)
	{
		int count[10] = { 0 };

		//ͳ��ĳһλ������ͬ���ֵĸ���
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			count[index]++;
		}

		int start[10] = { 0 };
		//ͳ�Ƹ�λ��ͬ����������arr�г��ֵ�λ��
		for (size_t i = 1; i < n; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		//��ʼ��tmp����
		memset(tmp, 0, sizeof(int)*n);
		
		//��Ͱ��������������
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			tmp[start[index]++] = arr[i];
		}

		//��tmp�����е�Ԫ�ؿ�����ԭ����
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