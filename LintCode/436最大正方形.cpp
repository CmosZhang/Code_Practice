#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//436. 最大正方形
//您的提交打败了 67.40% 的提交!
int maxSquare(vector<vector<int>> &matrix)
{
	// write your code here
	if (matrix.empty())
	{
		return 0;
	}
	int res = 0;
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>>dp(row, vector<int>(col, 0));

	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 1)
		{
			dp[i][0] = 1;
			res = max(res, dp[i][0]);
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (matrix[0][j] == 1)
		{
			dp[0][j] = 1;
			res = max(res, dp[0][j]);
		}
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				res = max(res, dp[i][j]);
			}
		}
	}
	return res * res;
}

int main()
{
	vector<vector<int>> matrix = { {1, 0, 1, 0, 0} };
	cout << maxSquare(matrix) << endl;
	system("pause");
	return 0;
}