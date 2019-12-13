#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//927. 翻转字符串II
//空间复杂度为O(n)，时间复杂度为O(n)
//您的提交打败了 84.05% 的提交!
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


//不使用额外的空间
//先把每个单词翻转，再把整个字符串翻转
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

//先翻转整个字符串，再翻转每个单词
//您的提交打败了 84.05% 的提交!
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
	//翻转每个单词
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			reverse(str, index, i - 1);
			index = i + 1;
		}
	}

	//翻转最后一个单词
	reverse(str, index, str.size() - 1);

	return str;

}

int main() {
	string str = "abc def gh";
	cout << reverseWords3(str) << endl;
	system("pause");
	return 0;
}