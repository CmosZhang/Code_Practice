#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//987. 具有交替位的二进制数
//您的提交打败了 100.00% 的提交!
bool hasAlternatingBits(int n)
{
	// Write your code here
	if (n <= 0)
	{
		return false;
	}
	int r = n % 2;
	n >>= 1;
	while (n)
	{
		int count = n % 2;
		if (count^r == 0)
		{
			return false;
		}
		r = count;
		n >>= 1;
	}
	return true;
}