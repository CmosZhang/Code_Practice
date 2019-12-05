#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;


//1255. 移除K位
//您的提交打败了 65.63% 的提交!
//思路：
//可以使用单调栈。
//从高位向低位依次入栈，若当前数字小于栈顶元素且k不为0，则删除栈顶元素。
//最后将栈内的元素变为数字即可。
string removeKdigits(string &num, int k) {
	// write your code here
	if (num.empty() || k >= num.size()) {
		return "0";
	}
	stack<char> stk;
	int len = num.size();
	for (int i = 0; i < len; i++) {
		while (!stk.empty() && k&&num[i] < stk.top()) {
			stk.pop();
			k--;
		}
		if (stk.empty() && num[i] == '0') {
			continue;
		}
		stk.push(num[i]);
	}
	while (k && !stk.empty()) {
		stk.pop();
		k--;
	}
	string res(stk.size(), ' ');
	for (int i = stk.size() - 1; i >= 0; i--) {
		res[i] = stk.top();
		stk.pop();
	}
	return res.empty() ? "0" : res;
}



int main() {
	string str;
	cin >> str;
	int k;
	cin >> k;
	cout << removeKdigits(str, k) << endl;
	system("pause");
	return 1;
}