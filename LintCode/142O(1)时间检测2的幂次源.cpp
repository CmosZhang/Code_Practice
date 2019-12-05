#include<iostream>

using namespace std;

//142. O(1)时间检测2的幂次
//您的提交打败了 88.00% 的提交!
bool checkPowerOf2(int n)
{
	// write your code here
	if (n < 1)
	{
		return false;
	}
	return n & (n - 1) == 0;
}

int main()
{
	int a = 5;
	bool flag = checkPowerOf2(a);
	cout << flag << endl;
	system("pause");
	return 1;
}