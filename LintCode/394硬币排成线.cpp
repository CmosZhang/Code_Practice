#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//394. 硬币排成线
//您的提交打败了 89.20% 的提交!
//只要n是3的倍数，则先手必输，不是3的倍数，先手必胜
bool firstWillWin(int n)
{
	// write your code here
	if (n <= 0)
	{
		return false;
	}
	if (n % 3 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}