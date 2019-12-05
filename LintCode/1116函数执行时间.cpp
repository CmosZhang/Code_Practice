#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;


//1116. 函数执行时间
//您的提交打败了 100.00% 的提交!
//void split(const string& src, const string& separator, vector<string>& dest)
//{
//	string str = src;
//	string substring;
//	string::size_type start = 0, index;
//
//	do
//	{
//		index = str.find_first_of(separator, start);
//		if (index != string::npos)
//		{
//			substring = str.substr(start, index - start);
//			dest.push_back(substring);
//			start = str.find_first_not_of(separator, index);
//			if (start == string::npos) return;
//		}
//	} while (index != string::npos);
//
//	substring = str.substr(start);
//	dest.push_back(substring);
//}

//另外一种字符串分割函数
vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}


vector<int> exclusiveTime(int n, vector<string> &logs) {
	// write your code here
	vector<int> res;
	if (logs.empty() || n <= 0) {
		return res;
	}
	for (int i = 0; i < n; i++) {
		res.push_back(0);
	}
	stack<int> stk;
	int last_time = 0;
	int len = logs.size();
	for (int i = 0; i < len; i++) {
		vector<string>  temp;
		//split(logs[i], ":", temp);
		temp = split(logs[i], ':');
		int id = stoi(temp[0]);
		string status = temp[1];
		int time = stoi(temp[2]);
		if (status == "start") {
			if (!stk.empty()) {
				res[stk.top()] += time - last_time;
			}
			stk.push(id);
		}
		else {
			++time;
			res[stk.top()] += time - last_time;
			stk.pop();
		}
		last_time = time;
	}
	return res;
}

int main() {
	int n = 3;
	vector<string>  logs = {"0:start:0","1:start:2","2:start:3","2:end:4","1:end:5","0:end:6","1:start:7","1:end:10"};
	vector<int> res = exclusiveTime(n, logs);
	for (int i = 0; i < n; i++) {
		cout << res[i] << endl;
	}
	system("pause");
	return 1;
}