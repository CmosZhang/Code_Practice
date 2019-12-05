#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>


using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	// write your code 
	if (matrix.size() <= 0)
	{
		return false;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int i = 0;
	int j = col - 1;
	while (i < row&&j >= 0)
	{
		if (matrix[i][j] > target)
		{
			j--;
			continue;
		}
		else if (matrix[i][j] < target)
		{
			i++;
			continue;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//写出一个高效的算法来搜索m×n矩阵中的值，返回这个值出现的次数。
int searchMatrix2(vector<vector<int>> &matrix, int target)
{
	// write your code here
	if (matrix.size() <= 0)
	{
		return 0;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int i = 0;
	int j = col - 1;
	int count = 0;
	while (i >= 0 && i < row&&j >= 0 && j < col)
	{
		if (matrix[i][j] == target)
		{
			count++;
			if (i + 1 < row)
			{
				i++;
			}
			else if (j - 1 >= 0)
			{
				j--;
			}
			else
			{
				return count;
			}
		}
		else if (matrix[i][j]<target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return count;
}