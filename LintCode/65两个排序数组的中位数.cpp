#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//65. ���������������λ��
//��ս
//ʱ�临�Ӷ�ΪO(log n)
//�����ύ����� 7.20% ���ύ!

//ѡ������
void SelectSort(vector<int>&a, int n) //ѡ������
{
	int mix, temp;
	for (int i = 0; i<n - 1; i++) //ÿ��ѭ�����飬�ҳ���С��Ԫ�أ�����ǰ�棬ǰ��ļ�Ϊ����õ�
	{
		mix = i; //������СԪ�ص��±�
		for (int j = i + 1; j<n; j++) //������������СԪ��������Ƚϣ���������С��Ԫ�ص��±�
			if (a[j]<a[mix])
				mix = j;
		//������������бȼ����Ԫ�ػ�С���ͽ���
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

	//ѡ������
	SelectSort(A, m);
	double res;
	//����λ��
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