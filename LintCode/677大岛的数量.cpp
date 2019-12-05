#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


//677. 大岛的数量
//您的提交打败了 99.45% 的提交!
int bfs(vector<vector<int>>& grid, int row, int col) //返回岛屿的大小。
{
	int rowSize = grid.size(), colSize = grid[0].size();
	queue<int> myQue;//广度优先遍历辅助队列
	grid[row][col] = 0;//标记
	myQue.push(row);
	myQue.push(col);
	int area = 1;
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
			area++;
		}
		if (row + 1 < rowSize && grid[row + 1][col] == 1)
		{//下方扩展
			grid[row + 1][col] = 0;//标记
			myQue.push(row + 1);
			myQue.push(col);
			area++;
		}
		if (col - 1 >= 0 && grid[row][col - 1] == 1)
		{//左方扩展
			grid[row][col - 1] = 0;//标记
			myQue.push(row);
			myQue.push(col - 1);
			area++;
		}
		if (col + 1 < colSize && grid[row][col + 1] == 1)
		{//右方扩展
			grid[row][col + 1] = 0;//标记
			myQue.push(row);
			myQue.push(col + 1);
			area++;
		}
	}
	return area;
}


int numsofIsland(vector<vector<int>> &grid, int k)
{
	// write your code here
	if (grid.empty())
	{
		return 0;
	}
	int row = grid.size();
	int col = grid[0].size();
	int count = 0;
	int area = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 1)
			{
				area = bfs(grid, i, j);
				if (area >= k)
				{
					count++;
				}
			}
		}
	}
	return count;
}


int main()
{
	vector<vector<int>> num = { { 1,1,0,0,0 },{ 0,1,0,0,1 },{ 0,0,0,1,1 },{ 0,0,0,0,0 },{ 0,0,0,0,1 } };
	int k = 2;
	int ans = numsofIsland(num, k);
	cout << ans << endl;
	system("pause");
	return 0;
}