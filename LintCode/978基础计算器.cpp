#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

//978. ����������
//�����ύ����� 78.64% ���ύ!
//int calculate(string &s) {
//	// Write your code here
//	if (s.empty()) {
//		return 0;
//	}
//	stack<int> stk;
//	int len = s.size();
//	int res = 0;
//	int num = 0;
//	int sign = 1;//��ʾ����
//	for (int i = 0; i < len; i++) {
//		char c = s[i];
//		if (c >= '0'&&c <= '9') {
//			num = 10 * num + (int)(c - '0');
//		}
//		else if (c == '+') {
//			res += sign * num;
//			num = 0;
//			sign = 1;
//		}
//		else if (c == '-') {
//			res += sign * num;
//			num = 0;
//			sign = -1;
//		}
//		else if (c == '(') {
//			stk.push(res);
//			stk.push(sign);
//			sign = 1;
//			res = 0;
//		}
//		else if (c == ')') {
//			res += sign * num;
//			num = 0;
//			res *= stk.top();
//			stk.pop();
//			res += stk.top();
//			stk.pop();
//		}
//	}
//	if (num != 0) {
//		res += sign * num;
//	}
//	return res;
//}

//������
//�����ύ����� 26.54% ���ύ!
//
int calculate(string &s) {
	// Write your code here
	if (s.empty()) {
		return 0;
	}
	stack<int> sum, symbol;
	int res = 0, num = 0, sign = 1;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c >= '0'&&c <= '9') {
			while (s[i] >= '0'&&s[i] <= '9') {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
			res += num * sign;
			num = 0;
		}
		else if (c == '+') {
			sign = 1;
		}
		else if (c == '-') {
			sign = -1;
		}
		else if (c == '(') {
			sum.push(res);
			res = 0;
			symbol.push(sign);
			sign = 1;
		}
		else if (c == ')') {
			res *= symbol.top();
			symbol.pop();
			res += sum.top();
			sum.pop();
		}
	}
	return res;
}


int main() {
	string str;
	cin >> str;
	cout << calculate(str) << endl;
	system("pause");
	return 1;
}