#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//162. 矩阵归零
//您的提交打败了 77.80% 的提交!
void setZeroesHelper(vector<vector<int>> &matrix, int rowmark, int colmark)
{
	int row = matrix.size();
	int col = matrix[0].size();
	for (int i = 0; i < row; i++)
	{
		if (i == rowmark)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (j == colmark)
		{
			for (int i = 0; i < row; i++)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void setZeroes(vector<vector<int>> &matrix) 
{
	// write your code here
	if (matrix.empty())
	{
		return;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<bool>> visit(row, vector<bool>(col, false));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0 && visit[i][j] == true)
			{
				setZeroesHelper(matrix, i, j);
			}
		}
	}
}