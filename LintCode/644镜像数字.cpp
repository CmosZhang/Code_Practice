#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//644. 镜像数字
//您的提交打败了 95.38% 的提交!
bool isStrobogrammatic(string &num) 
{
	// write your code here
	if (num.size() <= 0)
	{
		return false;
	}
	int len = num.size();
	int start = 0;
	int end = len - 1;
	while (start <= end)
	{
		if ((num[start] == '6'&&num[end] == '9')|| (num[start] == '9'&&num[end] == '6'))
		{
			start++;
			end--;
		}
		else if (num[start] == num[end] && (num[start] == '1' || num[start] == '8' || num[start] == '0'))
		{
			start++;
			end--;
		}
		else
		{
			return false;
		}
	}
	return true;
}