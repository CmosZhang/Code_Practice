#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//模拟乘法，计算a*b的值
//时间复杂度有要求
//这个代码的时间复杂度为O(min(a,b));
//肯定不是最优解
//int multi(int a, int b)
//{
//	int ans = 0;
//	if (b == 0 || a == 0)
//	{
//		return ans;
//	}
//	else if (b > 0)
//	{
//		for (int i = 1; i <= b; i++)
//		{
//			ans += a;
//		}
//		return ans;
//	}
//	else
//	{
//		for (int i = 1; i <= abs(b); i++)
//		{
//			ans += a;
//		}
//		return -ans;
//	}
//	return ans;
//}

//第二种方法：
int multi(int a, int b)
{
	int sign = 1;
	if (b < 0)
	{
		sign = -sign;
		b = -b;
	}
	if (a < 0)
	{
		sign = -sign;
		a = -a;
	}
	int ret = 0;
	//核心算法，使用到位运算
	while (b)
	{
		if (b & 1)
		{
			ret += a;
		}
		a <<= 1;
		b >>= 1;
	}
	if (sign < 0)
	{
		return -ret;
	}
	return ret;
}

int main()
{
	int a = 4, b = -4;
	cout << multi(a, b) << endl;
	system("pause");
	return 0;
}