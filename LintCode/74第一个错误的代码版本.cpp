#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//74. 第一个错误的代码版本
//这个版本的代码Time Limit Exceeded
//原因：防止Stack Overflow。假设low 和 high 都很大
//（但是在int的value range里面）如果两个都很大加起来就可能会超过2,147,483,647。
//更改后，您的提交打败了 28.40% 的提交!
//这个代码运行不了。SVNRepo::isBadVersion(mid)这个函数没有。
int findFirstBadVersion(int n)
{
	// write your code here
	if (n <= 0)
	{
		return n;
	}
	int low = 1;
	int high = n;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;//这不能写成 mid=(low+high)/2
		if (SVNRepo::isBadVersion(mid) == true)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}


int main()
{


	system("pause");
	return 1;
}