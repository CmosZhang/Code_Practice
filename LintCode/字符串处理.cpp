#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<cmath>
#include<limits.h>

using namespace std;

// ×Ö·û´®·Ö¸î
void split(const string& src, const string& separator, vector<string>& dest)
{
	string str = src;
	string substring;
	string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == string::npos) return;
		}
	} while (index != string::npos);

	substring = str.substr(start);
	dest.push_back(substring);
}

// ×Ö·û´®·Ö¸î£¬ÇÒ×ª»¯Îªint
//void split(const string& src, const string& separator, vector<int>& dest)
//{
//	string str = src;
//	string substring;
//	string::size_type start = 0, index;
//	do
//	{
//		index = str.find_first_of(separator, start);
//		if (index != string::npos)
//		{
//			substring = str.substr(start, index - start);
//			dest.push_back(atoi(substring.c_str()));
//			start = str.find_first_not_of(separator, index);
//			if (start == string::npos) return;
//		}
//	} while (index != string::npos);
//
//	substring = str.substr(start);
//	dest.push_back(atoi(substring.c_str()));
//}



//×Ö·û´®·Ö¸îº¯Êý
vector<string> split2(string &str1, string &p)
{
	vector<string> res;
	if (str1.empty() || p.empty()){
		return res;
	}
	string::size_type pos;
	str1 += p;
	int len = str1.size();
	for (int i = 0; i < len; i++){
		pos = str1.find(p, i);
		if (pos < len) {
			string temp = str1.substr(i, pos - i);
			res.push_back(temp);
			i = pos + p.size() - 1;
		}
	}
	return res;
}



int main()
{
	string str;
	getline(cin, str);
	vector<string> num;
	split(str, " ", num);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	system("pause");
	return 0;
}