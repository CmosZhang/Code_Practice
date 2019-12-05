#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

//200最长回文子串
//Memory Limit Exceeded,内存超出限制。
bool isPalindrome(string s)
{
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

/*
string longestPalindrome(string &s) 
{
	// write your code here
	if (s.empty())
	{
		return s;
	}
	int len = s.size();
	int maxlen = 0;
	vector<string> res;
	string maxString;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			if (isPalindrome(s.substr(i, j)))
			{
				int temp = j;
				if (j > maxlen)  //相同大小的字串之存储一个。
				{
					maxlen = j;
					maxString = s.substr(i, j);
				}
				//cout << temp << endl;

			}
		}
	}
	//cout << maxlen << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]<< endl;
		if (res[i].size() == maxlen)
		{
			maxString = res[i];
		}
	}
	return maxString;
}
*/

/*
//暴力求解。
string longestPalindrome(string &s)
{
	// write your code here
	if (s.empty())
	{
		return s;
	}
	int len = s.size();
	int maxlen = 0;
	string maxString;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			if (isPalindrome(s.substr(i, j)))
			{
				int temp = j;
				if (j > maxlen)
				{
					maxlen = j;
					maxString = s.substr(i, j);
				}
			}
		}
	}
	return maxString;
}
*/


//使用动态规划算法
/**
string longestPalindrome(string &s)
{
	int length = s.size();
	if (length == 1)
	{
		return s;
	}
	int maxlength = 0;
	int start;
	bool P[50][50] = { false };
	for (int i = 0; i<length; i++)//初始化准备
	{
		P[i][i] = true;
		if (i<length - 1 && s[i] == s[i+1])
		{
			P[i][i + 1] = true;
			start = i;
			maxlength = 2;
		}
	}
	for (int len = 3; len<length; len++)//子串长度
		for (int i = 0; i <= length - len; i++)//子串起始地址
		{
			int j = i + len - 1;//子串结束地址
			if (P[i + 1][j - 1] && s[i] == s[j])
			{
				P[i][j] = true;
				maxlength = len;
				start = i;
			}
		}
	if (maxlength >= 2)
		return s.substr(start, maxlength);
	return NULL;
}
*/


//使用马拉车算法
//由于回文串的长度可奇可偶，比如"bob"是奇数形式的回文，"noon"就是偶数形式的回文，
//马拉车算法的第一步是预处理，
//做法是在每一个字符的左右都加上一个特殊字符，比如加上'#'，那么
//bob-->    #b#o#b#
//noon-->    #n#o#o#n# 
//这样做的好处是不论原字符串是奇数还是偶数个，处理之后得到的字符串的个数都是奇数个
//您的提交打败了 87.00% 的提交!
string PostProcess(string &s)
{
	string res = "%#";  //
	if (s.empty() || s.length() == 1)
	{
		return s;
	}
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		res = res + s[i];
		res = res + '#';
	}
	return res;
}

//所以我们只要找到了最大的半径，就知道最长的回文子串的字符个数了。
//只知道长度无法定位子串，我们还需要知道子串的起始位置。   
string longestPalindrome(string &s)
{
	if (s.empty() || s.size() == 1)
	{
		return s;
	}
	//得到预处理的字符串
	string temp = PostProcess(s);

	//马拉车算法的核心
	//找出子串的起始位置
	vector<int> p(temp.size(), 0);
	int mx = 0, id = 0, resLen = 0, resCenter = 0;
	for (int i = 1; i < temp.size(); ++i) 
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (temp[i + p[i]] == temp[i - p[i]])
			++p[i];
		if (mx < i + p[i]) 
		{
			mx = i + p[i];
			id = i;
		}
		if (resLen < p[i]) 
		{
			resLen = p[i];
			resCenter = i;
		}
	}
	return s.substr((resCenter - resLen) / 2, resLen - 1);
}



int main()
{
	string s = "noon";
	string ans = longestPalindrome(s);
	cout << ans << endl;
	system("pause");
	return 0;
}