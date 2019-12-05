#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//211. 字符串置换
//您的提交打败了 49.40% 的提交!
//用空间来换取时间
bool Permutation(string &A, string &B) 
{
	// write your code here
	if (A.empty() && B.empty())
	{
		return true;
	}
	if (A.empty() || B.empty() || A.size() != B.size())
	{
		return false;
	}
	int dic[256] = { 0 };
	for (int i = 0; i < A.size(); i++)
	{
		dic[A[i]]++;
	}
	for (int i = 0; i < B.size(); i++)
	{
		dic[B[i]]--;
	}
	for (int i = 0; i < 256; i++)
	{
		if (dic[i] != 0)
		{
			return false;
		}
	}
	return true;
}