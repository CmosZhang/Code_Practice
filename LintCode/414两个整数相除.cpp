#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


//414. 两个整数相除
//用减法的形式来实现除法
//您的提交打败了 91.40% 的提交!
int divide(int dividend, int divisor) 
{
	// write your code here
	if (dividend == 0)
	{
		return 0;
	}
	if (divisor == 0)
	{
		return 2147483647;
	}
	int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

	long long a = llabs(dividend), b = llabs(divisor), res = 0;
	while (a >= b) 
	{
		for (long long c = b, cnt = 1; a >= c; c <<= 1, cnt <<= 1) 
		{
			a -= c;
			res += cnt;
		}
	}
	////Time Limit Exceeded
	//这种方式会超时，在计算2147483647和1这组数据的时候
	//while (a >= b)
	//{
	//	a -= b;
	//	res++;
	//}
	if (res == 2147483648 && sign > 0)
		return 2147483647;
	return sign * res;
}

int main()
{
	int dividend = 10;
	int divisor = 2;
	cout << divide(dividend, divisor) << endl;
	system("pause");
	return 0;
}