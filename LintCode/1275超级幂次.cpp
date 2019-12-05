#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int pow1(int x, int n);

//1275³¬¼¶ÃÝ´Î
int pow1(int x, int n) 
{
	if (n == 0) return 1;
	if (n == 1) return x % 1337;
	return pow1(x % 1337, n / 2) * pow1(x % 1337, n - n / 2) % 1337;
}

int superPow(int a, vector<int> &b) 
{
	// Write your code here
	long long res = 1;
	for (int i = 0; i < b.size(); ++i) 
	{
		res = pow1(res, 10)* pow1(a, b[i]) % 1337;
	}
	return res;
}

int main()
{
	vector<int>primes = {2,0,0};
	int n = 2147483647;
	int res;
	res = superPow(n, primes);
	cout << res << endl;
	system("pause");
	return 1;
}