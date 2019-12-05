#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//�鲢����
//�鲢������һ���ȶ�������ʽ��ʱ�临�Ӷ�ΪO(nlogn),
//��Ҫһ����ʱ��������Ϊ�����ռ䣬�ռ临�Ӷ�ΪO(n).

//�ϲ������������飬�����Ҫ�����ռ�
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
	//���ϲ�������鿽����ԭ������
	for (int i = low, k = 0; i <= high; i++, k++)
	{
		num[i] = temp[k];
	}
	delete[] temp;
}

//Ȼ���ö�·�鲢�ķ�ʽ������
//���õݹ��˼·
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