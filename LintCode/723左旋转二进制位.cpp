#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//723. 左旋转二进制位
//您的提交打败了 94.41% 的提交!
int leftRotate(int n, int d)
{
	// write code here
	vector<int> temp;
	for (int i = 0; i < 32; i++)
	{

		int count = (n >> i) & 1;
		temp.push_back(count);
	}
	//注意反转，不反转的话，是从低位到高位。
	reverse(temp.begin(), temp.end());//n的32位二进制存储，从高位到低位。
	//左移
	vector<int> res = temp;
	for (int i = 0; i < 32; i++)
	{
		if (i < 32 - d)
		{
			res[i] = temp[i + d];
		}
		else
		{
			res[i] = temp[i + d - 32];
		}
	}
	//将二进制数转换成十进制。
	//long long防止溢出。
	long long sum = 0;
	for (int i = 31; i >= 0; i--)
	{
		sum = sum + res[i] * pow(2, 31 - i);
	}
	return sum;
}

int main()
{
	int n = 123, d = 4;
	int res = leftRotate(n, d);
	cout << res << endl;
	system("pause");
	return 1;
}