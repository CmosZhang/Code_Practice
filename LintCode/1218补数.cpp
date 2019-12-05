#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1218. 补数
//您的提交打败了 100.00% 的提交!
//计算一个正整数的补数
int findComplement(int num) 
{
	// Write your code here
	vector<int> temp;
	while (num)
	{
		int r = num % 2;
		temp.push_back(r);
		num >>= 1;
	}
	//temp里面存储的是x的二进制表示。从低位到高位。
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 1)
		{
			temp[i] = 0;
		}
		else
		{
			temp[i] = 1;
		}
	}
	//二进制转换为10进制
	int sum = 0;
	for (int i = 0; i <temp.size(); i++)
	{
		sum = sum + temp[i] * (1 << i);
	}
	return sum;
}