#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//193. ���Ч����
//�����ύ����� 85.29% ���ύ!
//ջ�зŵ��������ź�δ��Գɹ��������ŵ��±ꡣ
//���������ţ�ֱ�ӷ���ջ��
//���������ţ���ջ���Ƿ�Ϊ�գ���Ϊ�������
//���ջΪ�գ�˵��û���������������ԣ�ֱ�ӷ���ջ��
//���ջ��Ϊ�գ���Ҫ��ջ���Ƿ���������
//���ջ���������ţ�����ջ��������������ţ�������res = ��ǰ�±� - ��ջ�������������ջ���ˣ�����ջ��ȡ-1��
//���ջ���������ţ�ֱ�ӷ���ջ�С�
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