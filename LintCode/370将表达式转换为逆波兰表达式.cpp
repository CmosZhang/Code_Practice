#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

//370. 将表达式转换为逆波兰表达式
//

int getLevel(string opt)
{
	if (opt == "(")
		return 0;
	if (opt == "+" || opt == "-")
		return 1;
	if (opt == "*" || opt == "/")
		return 2;
	return 3;
}

bool isOperator(string c)
{
	return (c == "+" || c == "-" || c == "*" || c == "/");
}


vector<string> convertToRPN(vector<string> &expression) {
	// write your code here
	if (expression.empty()) {
		return expression;
	}
	vector<string> res;
	stack<string> st;
	int len = expression.size();
	for (int i = 0; i < len; i++) {
		string c = expression[i];
		if (c == "(") {
			st.push(c);
		}
		else if (c == ")") {
			while (st.top() != "(") {
				res.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else {
			if (!isOperator(c)) {
				st.push(c);
			}
			else {
				while (!st.empty() && getLevel(st.top()) >= getLevel(c)) {
					res.push_back(st.top());
					st.pop();
				}
				st.push(c);
			}
		}
	}
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}
	return res;
}