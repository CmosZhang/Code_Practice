#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//553. 炸弹袭击
//用最简单的方法，向四周遍历
//94% 数据通过测试
//Time Limit Exceeded
//int maxKilledEnemies(vector<vector<char>> &grid) 
//{
//	// write your code here
//	if (grid.empty() || grid.size() == 0 || grid[0].size() == 0)
//	{
//		return 0;
//	}
//	int row = grid.size();
//	int col = grid[0].size();
//	int res = 0;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			int count = 0;
//			if (grid[i][j] == '0')
//			{
//				//up
//				for (int k = i - 1; k >= 0; k--)
//				{
//					if (grid[k][j] == 'E')
//					{
//						count++;
//					}
//					if (grid[k][j] == 'W')
//					{
//						break;
//					}
//				}
//				//down
//				for (int k = i + 1; k < row; k++)
//				{
//					if (grid[k][j] == 'E')
//					{
//						count++;
//					}
//					if (grid[k][j] == 'W')
//					{
//						break;
//					}
//				}
//				//left
//				for (int k = j - 1; k >= 0; k--)
//				{
//					if (grid[i][k] == 'E')
//					{
//						count++;
//					}
//					if (grid[i][k] == 'W')
//					{
//						break;
//					}
//				}
//				//right
//				for (int k = j + 1; k <col; k++)
//				{
//					if (grid[i][k] == 'E')
//					{
//						count++;
//					}
//					if (grid[i][k] == 'W')
//					{
//						break;
//					}
//				}
//			}
//			res = max(res, count);
//		}
//	}
//	return res;
//}

//使用动态规划
//您的提交打败了 50.20% 的提交!
int maxKilledEnemies(vector<vector<char>> &grid)
{
	// write your code here
	if (grid.empty() || grid.size() == 0 || grid[0].size() == 0) 
	{
		return 0;
	}
	int row = grid.size();
	int col = grid[0].size();

	//建立4个数组来保存4个方向能炸死的人数 
	vector<vector<int>> up(row, vector<int>(col, 0));
	vector<vector<int>> down(row, vector<int>(col, 0));
	vector<vector<int>> left(row, vector<int>(col, 0));
	vector<vector<int>> right(row, vector<int>(col, 0));

	//init
	for (int i = 0; i < col; i++)
	{
		if (grid[0][i] == 'E')
		{
			up[0][i] = 1;
		}
	}
	for (int i = 0; i < col; i++)
	{
		if (grid[row - 1][i] == 'E')
		{
			down[row - 1][i] = 1;
		}
	}
	for (int i = 0; i < row; i++)
	{
		if (grid[i][0] == 'E')
		{
			left[i][0] = 1;
		}
	}
	for (int i = 0; i < row; i++)
	{
		if (grid[i][col - 1] == 'E')
		{
			right[i][col - 1] = 1;
		}
	}

	//up
	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 'W')
			{
				up[i][j] == 0;
			}
			else if (grid[i][j] == 'E')
			{
				up[i][j] = 1 + up[i - 1][j];
			}
			else if (grid[i][j] == '0')
			{
				up[i][j] = up[i - 1][j];
			}
		}
	}

	//down
	for (int i = row - 2; i >= 0; i--)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 'W')
			{
				down[i][j] == 0;
			}
			else if (grid[i][j] == 'E')
			{
				down[i][j] = 1 + down[i + 1][j];
			}
			else if (grid[i][j] == '0')
			{
				down[i][j] = down[i + 1][j];
			}
		}
	}

	//left
	for (int j = 1; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			if (grid[i][j] == 'W')
			{
				left[i][j] == 0;
			}
			else if (grid[i][j] == 'E')
			{
				left[i][j] = 1 + left[i][j - 1];
			}
			else if (grid[i][j] == '0')
			{
				left[i][j] = left[i][j - 1];
			}
		}
	}
	//right
	for (int j = col - 2; j >= 0; j--)
	{
		for (int i = 0; i < row; i++)
		{
			if (grid[i][j] == 'W')
			{
				right[i][j] == 0;
			}
			else if (grid[i][j] == 'E')
			{
				right[i][j] = 1 + right[i][j + 1];
			}
			else if (grid[i][j] == '0')
			{
				right[i][j] = right[i][j + 1];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == '0')
			{
				int tmp = up[i][j] + down[i][j] + left[i][j] + right[i][j];
				ans = max(tmp, ans);
			}
		}
	}
	return ans;
}


int main()
{
	vector<vector<char>> matrix = { { '0','E','0','0' },{'E','0','W','E'},{'0','E','0','0'} };
	cout << maxKilledEnemies(matrix) << endl;
	system("pause");
	return 0;
}