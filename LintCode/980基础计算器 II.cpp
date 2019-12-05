#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;


//980. 基础计算器 II
//
int calculate(string &s) {
	// Write your code here
	if (s.empty()) {
		return 0;
	}
	int len = s.size();
	//去掉前面的空格
	int i = 0;
	while (s[i] == ' ') {
		i++;
	}
	int res = 0;
}


int main() {
	string str;
	cin >> str;
	cout << calculate(str) << endl;
	system("pause");
	return 1;
}