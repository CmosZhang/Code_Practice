#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>


using namespace std;

//32. 最小子串覆盖
//您的提交打败了 53.00% 的提交!
string minWindow(string &source, string &target) {
	// write your code here
	string res;
	if (source.empty() || target.empty()) {
		return res;
	}
	unordered_map<char, int> mp;
	for (int i = 0; i < target.size(); i++) {
		mp[target[i]]++;
	}
	
	int slow = 0, fast = 0, len = INT_MAX, pos = 0;

	int count = 0;//记录覆盖了几个字母

	while (fast < source.size() || count == mp.size()) {
		if (count == mp.size()) {
			if (len > fast - slow) {
				pos = slow;
				len = fast - slow;
			}
			if (mp.find(source[slow]) == mp.end()) {
				slow++;
				continue;
			}
			if (mp[source[slow]] < 0) {
				mp[source[slow++]]++;
				continue;
			}
			mp[source[slow++]] = 1;
			count--;
			continue;
		}
		if (mp.find(source[fast]) == mp.end()) {
			fast++;
			continue;
		}
		mp[source[fast]]--;
		if (mp[source[fast]] == 0) {
			count++;
		}
		fast++;
	}
	return (len == INT_MAX) ? "" : source.substr(pos, len);
}

int main() {
	string str;
	cin >> str;
	string target;
	cin >> target;
	cout << minWindow(str, target) << endl;
	system("pause");
	return 0;
}