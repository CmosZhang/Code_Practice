#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int minVal(int a, int b)
{
	return a < b ? a : b;
}

//513����ƽ����ʹ�ö�̬�滮
int numSquares(int n) 
{
	// write your code here
	if (n <= 0)
		return 0;
	vector<int> dp(n + 1,INT_MAX); //��Ϊʲô��Ҫ��INT_MAX����ʼ����
	dp[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int sqr = (int)sqrt(i);
		if (sqr*sqr == i)
			dp[i] = 1;
		else
		{
			for (int j = 1; j <= i / 2; ++j)
				dp[i] = minVal(dp[j] + dp[i - j], dp[i]);
		}
	}
	return dp[n];
}

int main()
{
	int num = 12;
	int res = numSquares(12);
	cout << res << endl;
	system("pause");
	return 1;
}