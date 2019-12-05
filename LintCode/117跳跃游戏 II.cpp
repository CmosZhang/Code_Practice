#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//117. ��Ծ��Ϸ II
//ʹ�ö�̬�滮��leetcode�ϻᳬʱ��
//�����ύ����� 20.80% ���ύ!
//int jump(vector<int> &A)
//{
//	// write your code here
//	if (A.empty())
//	{
//		return 0;
//	}
//	int len = A.size();
//	vector<int> dp(len, INT_MAX);
//	dp[0] = 0;
//
//	for (int i = 1; i < len; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (A[j] + j >= i)
//			{
//				dp[i] = min(dp[j] + 1, dp[i]);
//			}
//		}
//	}
//	return dp[len - 1];
//}

//ʹ��̰���㷨���
//˼·��
//վ����ǰλ��i, ���ɵ��������λ�ã�
//1.����ܵ������һ��λ�ã���������iָ�����һ��λ��
//2.�����ҵ���Щλ����������λ�ã���iָ�����λ��
//���iָ�����һ��λ��֮ǰ��λ�ã��������������
//�����ύ����� 91.60% ���ύ!
int jump(vector<int> &A)
{
	if (A.empty())
	{
		return 0;
	}
	int len = A.size();
	int start = 0;
	int end = 0;
	int step = 0;
	while (end < len - 1)
	{
		step++;
		int max_temp = 0;
		for (int i = start; i <= end; i++) 
		{
			max_temp = max(A[i] + i, max_temp);
			if (max_temp >= len - 1)
			{
				return step;
			}
		}
		start = end + 1;
		end = max_temp;
		if (start > end)
		{
			break;
		}
	}
	return 0;
}


int main()
{
	vector<int> A = { 2,3,1,1,4,1 };
	cout << jump(A) << endl;
	system("pause");
	return 0;
}