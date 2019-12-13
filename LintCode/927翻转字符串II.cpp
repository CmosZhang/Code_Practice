#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//927. ��ת�ַ���II
//�ռ临�Ӷ�ΪO(n)��ʱ�临�Ӷ�ΪO(n)
//�����ύ����� 84.05% ���ύ!
string reverseWords(string &str) {
	// write your code here
	if (str.empty()) {
		return str;
	}
	string res = "";
	string temp = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			temp += str[i];
		}
		else {
			res = temp + res;
			res = ' ' + res;
			temp = "";
		}
	}
	res = temp + res;
	return res;
}


//��ʹ�ö���Ŀռ�
//�Ȱ�ÿ�����ʷ�ת���ٰ������ַ�����ת
string reverseWords2(string &str) {
	// write your code here
	int n = str.size(), pre = 0;
	for (int i = 0; i <= n; ++i) {
		if (i == n || str[i] == ' ') {
			for (int j = pre; j <= (pre + i - 1) / 2; ++j) {
				swap(str[j], str[pre + i - 1 - j]);
			}
			pre = i + 1;
		}
	}
	for (int j = 0; j <= (n - 1) / 2; ++j) {
		swap(str[j], str[n - 1 - j]);
	}
	return str;
}

//�ȷ�ת�����ַ������ٷ�תÿ������
//�����ύ����� 84.05% ���ύ!
void reverse(string &str, int start, int end) {
	while (start <= end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

string reverseWords3(string &str) {
	if (str.empty()) {
		return str;
	}
	reverse(str, 0, str.size() - 1);

	int index = 0;
	//��תÿ������
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			reverse(str, index, i - 1);
			index = i + 1;
		}
	}

	//��ת���һ������
	reverse(str, index, str.size() - 1);

	return str;

}

int main() {
	string str = "abc def gh";
	cout << reverseWords3(str) << endl;
	system("pause");
	return 0;
}