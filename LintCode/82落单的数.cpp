#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//82. 落单的数
//您的提交打败了 97.00% 的提交!
int singleNumber(vector<int> &A)
{
	// write your code here
	if (A.size() <= 0)
	{
		return -1;
	}
	int len = A.size();
	int ans = A[0];
	for (int i = 1; i < len; i++)
	{
		ans = ans ^ A[i];
	}
	return ans;
}