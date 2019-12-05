#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//656. 大整数乘法
//您的提交打败了 97.20% 的提交!
string multiply(string &num1, string &num2)
{
	// write your code here

	string res(num1.size() + num2.size(), '0');

	string shorter = num1.size() < num2.size() ? num1 : num2;
	string longer = num1.size() < num2.size() ? num2 : num1;
	
	for (int i = shorter.size() - 1; i >= 0; --i)
	{
		int carry = 0;//进位
		for (int j = longer.size() - 1; j >= 0; --j)
		{
			int temp = (longer[j] - '0')*(shorter[i] - '0') + carry + res[i + j + 1] - '0';
			res[i + j + 1] = temp % 10 + '0';
			carry = temp / 10;
			if (carry&&j == 0)//如果短串已经到最左边(j==0)并且carry是不为0的，那么res要修改；
				res[i] += carry;
		}
	}
	//去掉前排的0
	int i = 0;
	while (res[i] == '0')//此处不要写i++;
		res.erase(0, 1);
	return res.size() == 0 ? "0" : res;
}