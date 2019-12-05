#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//393. ������Ʊ�����ʱ�� IV
//�����ύ����� 86.20% ���ύ!
int maxProfit(int K, vector<int> &prices) 
{
	// write your code here
	if (prices.empty() || K <= 0)
	{
		return 0;
	}
	int len = prices.size();
	//���ȣ���� K>=prices.size()/2����ζ�������޴ν��״�������ô���������Ȼ��ÿ����������֮��������ۼӣ�
	if (K >= len / 2)
	{
		int profit = 0;
		for (int i = 1; i < len; ++i)
		{
			if (prices[i] > prices[i - 1])
			{
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
	vector<vector<int>> dp(K + 1, vector<int>(len + 1, 0));
	for (int i = 1; i < K + 1; ++i)
	{
		int buyLast = -prices[0];
		for (int j = 2; j <= len; ++j) 
		{
			dp[i][j] = max(buyLast + prices[j - 1], dp[i][j - 1]);
			buyLast = max(buyLast, dp[i - 1][j - 1] - prices[j - 1]);
		}
	}
	return dp[K][len];
}

int main()
{
	vector<int> p = { 4,4,6,1,1,4,2,5 };
	int price;
	price = maxProfit(2, p);
	cout << price << endl;
	system("pause");
	return 0;
}