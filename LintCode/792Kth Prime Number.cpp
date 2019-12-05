#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//第k个质数
int kthPrime(int n)
{
	// write your code here
	if (n <= 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	int count = 1;
	int flag = 0;
	for (int i = 3; i <= n; i = i + 2)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			count++;
		}
		flag = 0;
	}
	return count;
}


int main()
{
	int n = 11;
	int res = kthPrime(11);
	cout << res << endl;
	system("pause");
	return 1;
}