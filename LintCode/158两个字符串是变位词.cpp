#include<iostream>
#include<string>

using namespace std;

//输入的字符串有大小写的区分，所以设置的映射表为58.小写字母z与大写字母A的ASCII相差57.
//最后的映射表的大小应该是58.
bool anagram(string &s, string &t)
{
	// write your code here
	if (s.size() <= 0 || t.size() <= 0)
	{
		return false;
	}
	int dic[58] = { 0 };
	int index;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		index = s[i] - 'A';
		dic[index]++;
	}
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == ' ')
			continue;
		index = t[i] - 'A';
		dic[index]--;
	}
	for (int k = 0; k < 58; k++)
	{
		if (dic[k] != 0)
		{
			return false;
		}
	}
	return true;
}
