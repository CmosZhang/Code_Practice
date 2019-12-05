#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//157. 判断字符串是否没有重复字符
//您的提交打败了 84.80% 的提交!
//简单题，没有调试直接通过。
bool isUnique(string &str) 
{
	// write your code here
	if (str.size() <= 0)
	{
		return true;
	}
	int m[256] = { 0 };
	for (int i = 0; i < str.size(); i++)
	{
		m[str[i]]++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (m[str[i]] > 1)
		{
			return false;
		}
	}
	return true;
}