#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//123.单词搜索
//您的提交打败了 100.00% 的提交!
//利用dfs方法来做
bool dfs(vector<vector<char>>&board, vector<vector<bool>>&visited, int index, string &word, int i, int j)
{
	if (index == word.size())
	{
		return true;
	}
	//判断越界情况
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
	{
		return false;
	}
	//之前访问过,不能再被访问
	if (visited[i][j])
	{
		return false;
	}
    //如果接下来的字符与单词中目前的index的字符不一致，要重现开始
	if (board[i][j] != word[index])
	{
		return false;
	}
	visited[i][j] = true;
	bool res = dfs(board, visited, index + 1, word, i - 1, j) || dfs(board, visited, index + 1, word, i + 1, j) || dfs(board, visited, index + 1, word, i, j + 1) || dfs(board, visited, index + 1, word, i, j - 1);
	visited[i][j] = false;
	return res;
}

bool exist(vector<vector<char>> &board, string &word) {
	// write your code here
	if (board.empty() || board[0].empty())
	{
		return false;
	}
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (dfs(board, visited, 0, word, i, j))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = { {'A','B','C','E'},{ 'S','F','C','S' },{ 'A','D','E','E' } };
	string word = "ABCCED";
	cout << exist(board, word) << endl;
	system("pause");
	return 0;
}