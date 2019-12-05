#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//116跳跃游戏
//使用动态规划求解问题
bool canJump(vector<int> &A)
{
	// write your code here
	int l = A.size();
	if (l <= 0)
	{
		return false;
	}
	vector<int> dp(l, 0);
	dp[0] = A[0];
	for (int i = 1; i < l; i++)
	{
		if (dp[i - 1] >= i)
		{
			dp[i] = max(dp[i - 1], A[i] + i);
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	return dp[l - 1] >= l - 1;
}

//117. 跳跃游戏 II
int jump(vector<int> &A) 
{
	// write your code here
	int l = A.size();
	if (l <= 1)
	{
		return 0;
	}




}


int main()
{
	vector<int>num = { 3,2,1,0,4 };
	/*int temp;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}*/
	bool res;
	res = canJump(num);
	cout << res << endl;
	system("pause");
	return 1;
}