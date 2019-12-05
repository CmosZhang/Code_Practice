#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class ExpressionTreeNode {
public:
	string symbol;
	ExpressionTreeNode *left, *right;
	ExpressionTreeNode(string symbol) {
		this->symbol = symbol;
		this->left = this->right = NULL;
	}
};


//367. ���������
//˼·���Ƚ����ʽת����һ���沨�����ʽ��Ȼ������沨�����ʽ����һ�ñ����
//�����ύ����� 32.80% ���ύ!
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


ExpressionTreeNode *build(vector<string> &expression) {
	// write your code here
	vector<string> RPN = convertToRPN(expression);
	int len = RPN.size();
	stack<ExpressionTreeNode*>nodeStack;
	for (int i = 0; i < len; i++) {
		string s = RPN[i];
		ExpressionTreeNode *pNode = new ExpressionTreeNode(s);
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			ExpressionTreeNode *pRight = nodeStack.top();
			nodeStack.pop();
			ExpressionTreeNode *pLeft = nodeStack.top();
			nodeStack.pop();
			pNode->right = pRight;
			pNode->left = pLeft;
			nodeStack.push(pNode);
		}
		else {
			nodeStack.push(pNode);
		}
	}
	if (nodeStack.empty()) {
		return NULL;
	}
	else {
		return nodeStack.top();
	}
}