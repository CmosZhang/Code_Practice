#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;


int evalRPN(vector<string> &tokens) {
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

int evaluateExpression(vector<string> &expression) {
	if (expression.empty()) {
		return 0;
	}
	vector<string> RPN = convertToRPN(expression);
	return evalRPN(RPN);
}