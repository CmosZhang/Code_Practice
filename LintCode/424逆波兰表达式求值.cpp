#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

//424. 逆波兰表达式求值
//您的提交打败了 100.00% 的提交!
int evalRPN(vector<string> &tokens) {
	// write your code here
	if (tokens.empty()) {
		return 0;
	}
	stack<int> st;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] != "+"&&tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/") {
			st.push(atoi(tokens[i].c_str()));
		}
		else {
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			int res = 0;
			if (tokens[i] == "+") {
				res = num2 + num1;
			}
			else if (tokens[i] == "-") {
				res = num2 - num1;
			}
			else if (tokens[i] == "*") {
				res = num2 * num1;
			}
			else if (tokens[i] == "/") {
				res = num2 / num1;
			}
			st.push(res);
		}
	}
	return st.top();
}