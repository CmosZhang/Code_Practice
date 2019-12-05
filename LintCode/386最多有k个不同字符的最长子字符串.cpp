#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

//386. 最多有k个不同字符的最长子字符串
//您的提交打败了 60.40% 的提交!
int lengthOfLongestSubstringKDistinct(string &s, int k)
{
	// write your code here
	if (s.empty() || k <= 0)
	{
		return 0;
	}
	int ret = 0;
	int start = 0;
	int end = 0;
	map<char, int> m;
	for (int i = 0; i < s.length(); i++)
	{
		m[s[i]]++;
		end = i;
		while (m.size() > k)
		{
			m[s[start]]--;
			if (m[s[start]] == 0)
			{
				m.erase(m.find(s[start]));
			}
			start++;
		}
		ret = max(ret, end - start + 1);
	}
	return ret;
}

int main()
{
	string str = "world";
	int k = 4;
	int res = lengthOfLongestSubstringKDistinct(str, k);
	cout << res << endl;
	system("pause");
	return 0;
}