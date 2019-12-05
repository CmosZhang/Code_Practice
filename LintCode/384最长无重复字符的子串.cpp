#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//384. 最长无重复字符的子串
//
int lengthOfLongestSubstring(string &s)
{
	// write your code here
	if (s.size() <= 0)
	{
		return 0;
	}
	int m[256] = { 0 };
	int res = 0, start = 0, temp = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] == 1 && m[s[i]] >= start)
		{
			start = m[s[i]] + 1;
		}
		temp = i - start + 1;
		m[s[i]] = i;
		res = max(res, temp);
	}
	return res;
}

int main()
{
	string str = "abcabcbb";
	int res = lengthOfLongestSubstring(str);
    cout << res << endl;
	system("pause");
	return 1;
}