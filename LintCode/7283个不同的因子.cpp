#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<map>

using namespace std;


//728.3个不同的因子
//您的提交打败了 72.28% 的提交!
bool isPrime(long long n) {
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isThreeDisctFactors(long long n) {
	// write your code here
	long long x = sqrt(n);
	return x * x == n && isPrime(x);
}