#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//151. 买卖股票的最佳时机 III
//您的提交打败了 97.20% 的提交!
int maxProfit(vector<int> &prices) 
{
	// write your code here
	if (prices.empty())
	{
		return 0;
	}
	int maxprofit = 0;

	int len = prices.size();
	vector<int> left(len, 0);
	vector<int> right(len, 0);

	int minprice = prices[0];
	for (int i = 1; i < len; i++)
	{
		minprice = min(minprice, prices[i]);
		left[i] = max(left[i - 1], prices[i] - minprice);
	}

	int maxprice = prices[len - 1];
	for (int i = len - 2; i >= 0; i--)
	{
		maxprice = max(maxprice, prices[i]);
		right[i] = max(right[i + 1], maxprice - prices[i]);
	}

	for (int i = 0; i < len; i++)
	{
		maxprofit = max(maxprofit, left[i] + right[i]);
	}
	return maxprofit;
}


int main()
{
	vector<int> p = { 4,4,6,1,1,4,2,5 };
	int price;
	price = maxProfit(p);
	cout << price << endl;
	system("pause");
	return 0;
}