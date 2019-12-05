#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//365. 二进制中有多少个1 
//您的提交打败了 70.80% 的提交!
//第一次提交没有考虑到负数。
int countOnes(int num) 
{
	// write your code here
	int count = 0;
	for (int i = 0; i<32; i++)   //移位逐步操作
	{
		if ((num >> i) & 1)
		{
			count++;
		}
	}
	return count;
}