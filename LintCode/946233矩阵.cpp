#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

//946. 233����
//�����ύ����� 96.30% ���ύ!
//int calcTheValueOfAnm(vector<int> &X, int m) {
//	// write your code here
//	if (X.empty() || m <= 0)
//	{
//		return 0;
//	}
//	int n = X.size();
//	//�õ���233����Ĵ�С
//	vector<vector<int>> temp(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i < m + 1; i++)
//	{
//		string res = "233";
//		temp[0][i] = atoi(res.c_str());
//		res += '3';
//	}
//	for (int i = 1; i < n + 1; i++)
//	{
//		temp[i][0] = X[i - 1];
//	}
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < m + 1; j++)
//		{
//			temp[i][j] = temp[i - 1][j] + temp[i][j - 1];
//		}
//	}
//	return temp[n][m] % 10000007;
//}