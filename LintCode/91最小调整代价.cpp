#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//91. 最小调整代价
//您的提交打败了 79.20% 的提交!
int MinAdjustmentCost(vector<int> &A, int target)
{
	// write your code here
	if (A.empty())
	{
		return 0;
	}
	int len = A.size();
	//101的意思是因为数组中最大的数为100.
	//初始化数组
	vector<vector<int>> dp(len + 1, vector<int>(101, INT_MAX));

	for (int i = 0; i <= 100; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (dp[i - 1][j] != INT_MAX)
			{
				for (int k = 0; k <= 100; k++)
				{
					if (abs(j - k) <= target)
					{
						if (dp[i][k] > dp[i - 1][j] + abs(A[i - 1] - k))
						{
							dp[i][k] = dp[i - 1][j] + abs(A[i - 1] - k);
						}
					}
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		if (dp[len][i] < ans)
		{
			ans = dp[len][i];
		}
	}
	return ans;
}

int main()
{
	vector<int> nums = { 3,5,4,7 };
	int k = 2;
	long long res = MinAdjustmentCost(nums, k);
	cout << res << endl;
	system("pause");
	return 0;
}