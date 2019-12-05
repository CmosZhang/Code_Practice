#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

bool isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i*i < num; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

//699. 判断k个素数之和 
//您的提交打败了 83.87% 的提交!
bool isSumOfKPrimes(int n, int k) 
{
	// write your code here
	if (n < 2 * k || k <= 0)
		return false;
	if (k == 1)
		return isPrime(n);
	//若k也为偶数（k=2q），n>=4q，n可以分成q个大于等于4的数，根据猜想，每个数又可以表示为两个质数的和，故可以表示为k（即2q）个质数的和，返回true
	//若k为奇数，为了保证n可以是k个数的和，必存在素数2，返回isSumOfKPrimes(n - 2, k - 1)
	if (n % 2 == 0)
	{
		if (k % 2 == 0)
			return true;
		else
			return isSumOfKPrimes(n - 2, k - 1);
	}
	//若k为偶数，n不可能由偶数个奇数组成，必存在素数2，返回isSumOfKPrimes(n - 2, k - 1)
	//若k为奇数，必然存在至少一个奇数，返回isSumOfKPrimes(n - 3, k - 1)
	else
	{
		if (k % 2 == 0)
			return isSumOfKPrimes(n - 2, k - 1);
		else
			return isSumOfKPrimes(n - 3, k - 1);
	}
}



int main()
{
	bool flag = false;
	int n = 10;
	int k = 2;
	flag = isSumOfKPrimes(n, k);
	cout << flag << endl;
	system("pause");
	return 0;
}