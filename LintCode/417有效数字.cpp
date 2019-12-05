#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//417. 有效数字
//您的提交打败了 98.80% 的提交!
//考虑的情况多。
bool isNumber(string &s) 
{
	// write your code here
	if (s.size() <= 0)
	{
		return false;
	}
	int len = s.size();
	//去除头部的空格。
	int start = 0;
	while (start < len&&s[start] == ' ')
	{
		start++;
	}
	if (start == len)
	{
		return false;   //字符串全是空格。
	}
	bool flag_dian = false; //判断小数点。
	bool flag_e = false; //判断科学记数法e。
	bool flag_blank = false; //判断空格。
	//处理正负号
	if (s[start] == '+' || s[start] == '-')
	{
		start++;
	}
	if (s[start] == '.')
	{
		flag_dian = true;
		start++;
	}
	if (!(s[start] >= '0' && s[start] <= '9'))//第一个字符必须是数字
	{
		return false;
	}
	while (start < len)
	{
		if (s[start] >= '0'&&s[start] <= '9')
		{
			start++;
		}
		else if (!flag_blank&&s[start] == ' ') //如果出现空格，空格要持续到结束。
		{
			while (s[start] == ' '&&start < len)
			{
				start++;
			}
			if (start == len)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (!flag_dian && !flag_e&&s[start] == '.')//处理. 点之前不能有e.
		{
			flag_dian = true;
			start++;
		}
		else if (!flag_e&&s[start] == 'e')
		{
			flag_e = true;
			start++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s = "0.1";
	bool flag = isNumber(s);
	cout << flag << endl;
	system("pause");
	return 1;
}