#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//183. ľ�ļӹ�
//�����ύ�����100.00% ���ύ!
//ľ�ĵ���󳤶ȿ϶�<=������ÿһ������k����֮��(sum)
//����������ֵ��ʼ������
int woodCut(vector<int> &L, int k)
{
	// write your code here
	if (L.size() <= 0)
	{
		return 0;
	}
	int max = 0;//Ѱ�����ֵ
	for (int i = 0; i < L.size(); i++)
	{
		if (max < L[i])
		{
			max = L[i];
		}
	}
	//ʹ�ö��ֲ���������
	int low = 1;
	int high = max - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;//����д��ֹ��ջ�����
		int count = 0;
		for (int i = 0; i < L.size(); i++)
		{
			count += L[i] / mid;
		}
		if (count >= k)
		{
			low = mid + 1;
		}
		if (count < k)
		{
			high = mid - 1;
		}
	}
	return high;
}

int main()
{
	vector<int> wood = { 232, 124, 456 };
	int k = 7;
	int res = woodCut(wood, k);
	cout << res << endl;
	system("pause");
	return 1;
}