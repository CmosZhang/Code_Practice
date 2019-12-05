#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//512. 解码方法
//您的提交打败了 33.20% 的提交!
int numDecodings(string &s) {
	// write your code here
	if (s.empty()) {
		return 0;
	}
	vector<int> dp(s.size() + 1, 0);
	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;

	for (int i = 2; i <= s.size(); i++) {
		if (s[i - 1] != '0') {
			dp[i] = dp[i - 1];
		}
		int val = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
		if (val >= 10 && val <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp.back();
}

int main() {
	string str;
	getline(cin, str);
	cout << numDecodings(str) << endl;
	system("pause");
	return 0;
}