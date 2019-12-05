#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//193. 最长有效括号
//您的提交打败了 85.29% 的提交!
//栈中放的是左括号和未配对成功的右括号的下标。
//遇到左括号，直接放入栈中
//遇到右括号，看栈中是否为空，分为两种情况
//如果栈为空，说明没有最近的左括号配对，直接放入栈中
//如果栈不为空，还要看栈顶是否是左括号
//如果栈顶是左括号，弹出栈顶（最近的左括号），更新res = 当前下标 - 新栈顶（如果弹出后栈空了，则新栈顶取-1）
//如果栈顶是右括号，直接放入栈中。
int longestValidParentheses(string &s) {
	// write your code here
	if (s.empty()) {
		return 0;
	}
	stack<int> stk;
	int res = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			if (stk.empty()) {
				stk.push(i);
			}
			else {
				if (s[stk.top()] == '(') {
					stk.pop();
					res = max(res, i - (stk.empty() ? -1 : stk.top()));
				}
				else {
					stk.push(i);
				}
			}
		}
	}
	return res;
}


int main() {
	string str;
	cin >> str;
	cout << longestValidParentheses(str) << endl;
	system("pause");
	return 0;
}