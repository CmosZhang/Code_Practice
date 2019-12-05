#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//1284. �������
//�����ύ����� 87.67% ���ύ!
int integerBreak(int n)
{
	// Write your code here
	if (n <= 0)
	{
		return 0;
	}

	vector<int> dp(n + 1, 0);
	//
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;//�趨�ó�ʼֵ
		if (i == n)
		{
			dp[i] = 0;
		}
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i - j] * j, dp[i]);
		}
	}
	return dp[n];
}

int main()
{
	int n = 10;
	cout << integerBreak(n) << endl;
	system("pause");
	return 0;
}