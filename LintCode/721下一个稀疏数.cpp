#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//721. 下一个稀疏数
//您的提交打败了 97.77% 的提交!
//稀疏数的理解有误，不是相互交叉出现0，1.
//如果为110，最近的稀疏数为1000.
int nextSparseNum(int x) 
{
	// write your code here
	vector<int> temp;
	int n = x;
	while (n)
	{
		int r = n % 2;
		temp.push_back(r);
		n >>= 1;
	}
	//temp里面存储的是x的二进制表示。从低位到高位。
	temp.push_back(0); //结果可能会多一位
	int len = temp.size();
	int pos = 0;
	for (int i = 1; i < len - 1; i++)
	{
		if (temp[i] == 1 && temp[i - 1] == 1 && temp[i + 1] == 0)
		{
			temp[i + 1] = 1;
			for (int j = i; j >= pos; j--)
			{
				temp[j] = 0;
			}	
		    pos = i + 1;
		}
	}
	//n的32位二进制存储，从高位到低位
	//二进制转换为10进制
	int sum = 0;
	for (int i = 0; i <len; i++)
	{
		sum = sum + temp[i] * (1 << i);
	}
	return sum;
}


int main()
{
	int x = 86;
	int res = nextSparseNum(x);
	cout << res << endl;
	system("pause");
	return 1;
}