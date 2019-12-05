#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;


//1255. �Ƴ�Kλ
//�����ύ����� 65.63% ���ύ!
//˼·��
//����ʹ�õ���ջ��
//�Ӹ�λ���λ������ջ������ǰ����С��ջ��Ԫ����k��Ϊ0����ɾ��ջ��Ԫ�ء�
//���ջ�ڵ�Ԫ�ر�Ϊ���ּ��ɡ�
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