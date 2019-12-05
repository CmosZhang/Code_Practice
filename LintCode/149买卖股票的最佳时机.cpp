#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//lintcode 149Ã‚
//int maxProfit(vector<int> &prices) 
//{
//	// write your code here
//	if (prices.empty())
//	{
//		return 0;
//	}
//	int maxprofit = 0;
//	int minprice = prices[0];
//	for (int i = 0; i < prices.size(); i++)
//	{
//		minprice = min(minprice,prices[i]);
//		maxprofit = max(maxprofit, prices[i] - minprice);
//	}
//	return maxprofit;
//}



//lintcode 150Ã‚
int maxProfit(vector<int> &prices)
{
	if (prices.empty())
	{
		return 0;
	}
	int maxprofit = 0;
    int minprice = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		maxprofit = maxprofit + max(0, prices[i] - prices[i-1]);
	}
	return maxprofit;
}

int main()
{
	vector<int> p;
	int a;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		p.push_back(a);
	}

	int price;
	price = maxProfit(p);

	cout << price << endl;

	system("pause");
	return 1;
}