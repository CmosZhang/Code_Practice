#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//75. Ѱ�ҷ�ֵ
/*ע������
It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.*/
//����Ĵ���û���κ����⣬����ʱ�临�Ӷ�̫�ߡ�
//�����ö��ַ���
//int findPeak(vector<int> &A)
//{
//	// write your code here
//	if (A.size() <= 2)
//	{
//		return -1;
//	}
//	int len = A.size();
//	for (int i = 1; i < len - 1; i++)
//	{
//		if (A[i] > A[i - 1] && A[i] > A[i + 1])
//		{
//			return i;
//		}
//	}
//}

//���ַ������96.4%���ύ���������뵽��
//int findPeak(vector<int> &A)//���ÿ���A�쳣�����
//{
//	int len = A.size();
//	int low = 0;
//	int high = len - 1;
//	int mid;
//	while (low < high)
//	{
//		mid = (low + high) / 2;
//		if (mid == 0)//���鳤��Ϊ2 ѭ���������鲻�ϼ�С��
//		{
//			return 1;//�������ǰ����if,else if,�㷨����ʱ������ӡ�
//			//�������������56%���ύ�����ϴ��96.4%���ύ��
//		}
//		else if (mid == len - 1)//���鳤��Ϊ1
//		{
//			return mid - 1;
//		}
//		else if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
//		{
//			return mid;
//		}
//		else if (A[mid] < A[mid - 1])
//		{
//			high = mid - 1;//�����ڷ�ֵ
//		}
//		else
//		{
//			low = mid + 1;//�Ҳ���ڷ�ֵ
//		}
//	}
//}

//����˫ָ�뷨���99.4%���ύ����������뵽��
int findPeak(vector<int> &A)
{
	int start = 1, end = A.size() - 2;
	while (start <= end)
	{
		if (A[start] > A[start - 1] && A[start] > A[start + 1])
			return start;
		else start++;
		if (A[end] > A[end - 1] && A[end] > A[end + 1])
			return end;
		else end--;
	}
	return -1;
}

int main()
{
	vector<int>nums = { 1, 2, 1, 3, 4, 5, 7, 6 };
	int res2;
	res2 = findPeak(nums);
	cout << res2 << endl;
	system("pause");
	return 1;
}