#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//664. 数 1
//您的提交打败了 45.02% 的提交!
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

vector<int> countBits(int num) 
{
	// write your code here
	vector<int> res;
	if (num < 0)
	{
		return res;
	}
	for (int i = 0; i <= num; i++)
	{
		int count = countOnes(i);
		res.push_back(count);
	}
	return res;
}