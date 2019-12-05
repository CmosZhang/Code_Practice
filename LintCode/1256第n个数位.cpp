#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<strstream>

using namespace std;

//1256. 第n个数位
//您的提交打败了 89.22% 的提交!
//这种方法内存超出限制。空间复杂度太高。
/*
* 这里首先分析一下位数和规律
* 个位数：1-9，一共9个,共计9个数字
* 2位数：10-99,一共90个，共计180个数字
* 3位数：100-999，一共900个，共计2700个数字
* 4位数，1000-9999，一共9000个，共计36000个数字
* 以此类推，
* 这样我们就可以首先定位到是哪个数，再找到其对应的数字
*/
int findNthDigit(int n) 
{
	// write your code here
	/*if (n <= 0)
	{
		return 0;
	}
	vector<int> temp;
	for (int i = 1; i < 10; i++)
	{
		temp.push_back(i);
	}
	int num = 10;
	while (temp.size() <= n)
	{
		int a = num % 10;
		while (num / 10)
		{
			num = num / 10;//num 已经改变。逻辑存在问题
			temp.push_back(num);
		}
		temp.push_back(a);
		num++;
	}
	return temp[n - 1];*/
	int len = 1, base = 1;
	while (n > 9L * base * len) //为什么这需要一个L.防止溢出
	{
		n -= 9 * base * len;
		len++;
		base *= 10;
	}
	int curNum = (n - 1) / len + base, digit = 0;
	cout << curNum << endl;
	for (int i = (n - 1) % len; i<len; ++i) 
	{
		digit = curNum % 10;
		curNum /= 10;
	}
	return digit;
}

int main()
{
	int m = 1297;
	int res = findNthDigit(m);
	cout << res << endl;
	system("pause");
	return 1;
}