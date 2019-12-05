#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//117. 跳跃游戏 II
//使用动态规划在leetcode上会超时。
//您的提交打败了 20.80% 的提交!
//int jump(vector<int> &A)
//{
//	// write your code here
//	if (A.empty())
//	{
//		return 0;
//	}
//	int len = A.size();
//	vector<int> dp(len, INT_MAX);
//	dp[0] = 0;
//
//	for (int i = 1; i < len; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (A[j] + j >= i)
//			{
//				dp[i] = min(dp[j] + 1, dp[i]);
//			}
//		}
//	}
//	return dp[len - 1];
//}

//使用贪婪算法最好
//思路：
//站到当前位置i, 检测可到达的所有位置：
//1.如果能到达最后一个位置，则跳出，i指向最后一个位置
//2.否则，找到这些位置中数最大的位置，让i指向这个位置
//如果i指向最后一个位置之前的位置，则继续上述步骤
//您的提交打败了 91.60% 的提交!
int jump(vector<int> &A)
{
	if (A.empty())
	{
		return 0;
	}
	int len = A.size();
	int start = 0;
	int end = 0;
	int step = 0;
	while (end < len - 1)
	{
		step++;
		int max_temp = 0;
		for (int i = start; i <= end; i++) 
		{
			max_temp = max(A[i] + i, max_temp);
			if (max_temp >= len - 1)
			{
				return step;
			}
		}
		start = end + 1;
		end = max_temp;
		if (start > end)
		{
			break;
		}
	}
	return 0;
}


int main()
{
	vector<int> A = { 2,3,1,1,4,1 };
	cout << jump(A) << endl;
	system("pause");
	return 0;
}