#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;


//179. 更新二进制位
//您的提交打败了 97.40% 的提交!
int updateBits(int n, int m, int i, int j) 
{
	// write your code here
	for (int k = 0; i <= j; ++i, ++k) 
	{
		if (m&(1 << k))  //判断m的第k位是否为1  
			n|=1<<i;  //如果为1则n的第i位置1 
		else               
			n&=~(1<<i);//否则第i位置0 
	}        
	return n;
}


int main()
{
	int n = 1024, m = 21, i = 2, j = 6;
	int res = updateBits(n, m, i, j);
	cout << res << endl;
	system("pause");
	return 1;
}