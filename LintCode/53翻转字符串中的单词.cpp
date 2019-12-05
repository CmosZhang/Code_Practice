#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//53. 翻转字符串中的单词
//这个代码只适合单一空格隔开的单词
//您的提交打败了 75.60% 的提交!
vector<string> split2(string &str1, string p)
{
	vector<string> res;
	if (str1.empty() || p.empty()) {
		return res;
	}
	int i = 0;
	string str2 = str1;
	while (str1[i] == ' ')
		str1.erase(0, 1);
	if (str1.empty()) {
		res.push_back(str2);
		return res;
	}
	string::size_type pos;
	str1 += p;
	int len = str1.size();
	for (int i = 0; i < len; i++) {
		pos = str1.find(p, i);
		if (pos < len) {
			string temp = str1.substr(i, pos - i);
			//对temp去除空格，如果为空不添加进去res;
			int j = 0;
			while (temp[j] == ' ')
				temp.erase(0, 1);
			if (!temp.empty())
				res.push_back(temp);
			i = pos + p.size() - 1;
		}
	}
	return res;
}


string reverseWords2(string &s)
{
	// write your code here
	string ans;
	if (s.empty()){
		return ans;
	}
	vector<string> str = split2(s, " ");
	for (int i = str.size() - 1; i >= 1; i--) {
		ans += str[i];
		ans += " ";
	}
	ans += str[0];
	return ans;
}

string reverseWords(string &s) { 
	stack<string> str;
	string s0 = "";
	if (s.empty())
	{
		s = "";
		return s;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != 32)
		{
			s0 += s[i];
			continue;
		}  
		else if (!s0.empty())
		{
			str.push(s0);  
			s0.clear();    
		}
	}
	if (!s0.empty())
	{
		str.push(s0);
		s0.clear();
	}
	while (!str.empty())
	{
		s0 += str.top();   //取值、并出栈。
		str.pop();
		s0 += " ";
	}
	if (s0.empty())
	{
		s = "";
		return s;
	}
	s0.erase(s0.end() - 1);
	s = s0;
	return s;
}


int main()
{
	string str;
	getline(cin, str);
	string ans = reverseWords(str);
	cout << ans << endl;
	return 0;
}