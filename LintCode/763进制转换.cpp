#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//763. ½øÖÆ×ª»»
string hexConversion(int n, int k) {
	// write your code here
	string res;
	if (n == 0) {
		return "0";
	}
	while (n > 0) {
		int t = n % k;
		char c = ' ';
		if (t <= 9) {
			c = '0' + t;
		}
		else {
			c = 'A' + t - 10;
		}
		res = c + res;
		n /= k;
	}
	return res;
}