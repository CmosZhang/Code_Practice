#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<queue>
#include<unordered_set>

using namespace std;


//860. 不同岛屿的个数
//
vector<vector<int>> dirs{ { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };

//利用DFS来求解。
void dfs(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<vector<bool>>& visited, set<string>& s)
{
	int m = grid.size(), n = grid[0].size();
	visited[i][j] = true;
	for (auto dir : dirs)
	{
		int x = i + dir[0], y = j + dir[1];
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y])
			continue;
		string str = to_string(x - x0) + "_" + to_string(y - y0);
		s.insert(str);
		dfs(grid, x0, y0, x, y, visited, s);
	}
}

//利用BFS来求解。
//您的提交打败了 99.58% 的提交!
void bfs(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<vector<bool>>& visited, set<string>& s)
{
	int m = grid.size(), n = grid[0].size();
	visited[i][j] = true;
	queue<int> myQue;
	myQue.push(i);
	myQue.push(j);
	while (!myQue.empty())
	{
		i = myQue.front();
		myQue.pop();
		j = myQue.front();
		myQue.pop();
		for (auto dir : dirs)
		{
			int x = i + dir[0], y = j + dir[1];
			if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y])
				continue;
			visited[x][y] = true;
			myQue.push(x);
			myQue.push(y);
			string str = to_string(x - x0) + "_" + to_string(y - y0);//访问的点基于原点的坐标。
			//把这个访问的点放入到set 里边。
			//cout << str << endl;
			s.insert(str);
		}
	}
}

int numberofDistinctIslands(vector<vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	unordered_set<string> res;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				set<string> s;
				bfs(grid, i, j, i, j, visited, s);
				string t = "";
				for (auto str : s) 
					t += str + "_";
				res.insert(t);
			}
		}
	}
	return res.size();
}

int main()
{
	vector<vector<int>> num = { { 1,1,0,0,0 },{ 1,1,0,0,0 },{ 0,0,0,1,1 },{ 0,0,0,1,1 } };
	int k = 2;
	int ans = numberofDistinctIslands(num);
	cout << ans << endl;
	system("pause");
	return 0;
}