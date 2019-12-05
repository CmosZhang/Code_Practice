#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


//433. 岛屿的个数
//利用深度优先遍历来做。
//您的提交打败了 100.00% 的提交!
void dfs(vector<vector<int>>&grid, int i, int j)
{
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
	{
		return;
	}
	if (grid[i][j] == 1)
	{
		grid[i][j] = 0;
		if (i - 1 >= 0)
		{
			dfs(grid, i - 1, j);
		}
		if (i + 1 < grid.size())
		{
			dfs(grid, i + 1, j);
	    }
		if (j - 1 >= 0)
		{
			dfs(grid, i, j - 1);
		}
		if (j + 1 < grid[0].size())
		{
			dfs(grid, i, j + 1);
		}
	}
	else
	{
		return;
	}
}

//利用广度优先遍历来做。
//您的提交打败了 100.00% 的提交!
void bfs(vector<vector<int>>& grid, int row, int col) 
{
	int rowSize = grid.size(), colSize = grid[0].size();
	queue<int> myQue;//广度优先遍历辅助队列
	grid[row][col] = 0;//标记
	myQue.push(row);
	myQue.push(col);
	while (!myQue.empty()) 
	{
		row = myQue.front();
		myQue.pop();
		col = myQue.front();
		myQue.pop();
		if (row - 1 >= 0 && grid[row - 1][col] == 1) 
		{//上方扩展
			grid[row - 1][col] = 0;//标记
			myQue.push(row - 1);
			myQue.push(col);
		}
		if (row + 1 < rowSize && grid[row + 1][col] == 1) 
		{//下方扩展
			grid[row + 1][col] = 0;//标记
			myQue.push(row + 1);
			myQue.push(col);
		}
		if (col - 1 >= 0 && grid[row][col - 1] == 1) 
		{//左方扩展
			grid[row][col - 1] = 0;//标记
			myQue.push(row);
			myQue.push(col - 1);
		}
		if (col + 1 < colSize && grid[row][col + 1] == 1) 
		{//右方扩展
			grid[row][col + 1] = 0;//标记
			myQue.push(row);
			myQue.push(col + 1);
		}
	}
}


int numIslands(vector<vector<int>> &grid) 
{
	// write your code here
	if (grid.empty())
	{
		return 0;
	}
	int row = grid.size();
	int col = grid[0].size();
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 1)
			{
				bfs(grid, i, j);
				//dfs(grid, i, j);
				count++;
			}
		}
	}
	return count;
}


int main()
{
	vector<vector<int>> num = { {1,1,0,0,0},{0,1,0,0,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,1} };
	int ans = numIslands(num);
	cout << ans << endl;
	system("pause");
	return 0;
}