#include<iostream>
#include<stack>

using namespace std;


//140. 快速幂
//您的提交打败了 96.00% 的提交!
//int powtemp(int a, int b, int n)
//{
//	if (n == 0) return 1;
//	if (n == 1) return a % b;
//	return powtemp(a, b, n / 2) * powtemp(a, b, n - n / 2) % b;
//}
int fastPower(int a, int b, int n)
{
	// write your code here
	if (b == 0 || n < 0)
		return -1;
	if (n == 0)
		return 1 % b;
	if (n == 1)
		return a % b;
	long long res = 1;
	res = fastPower(a, b, n >> 1) % b;
	res = (res*res) % b;
	if (n & 1 == 1)
	{
		res = (res*a) % b;
	}
	return res;
}

int main()
{
	int a = 11, b = 123898, n = 12345;
	int res = fastPower(a, b, n);
	cout << res << endl;
	system("pause");
	return 0;
}