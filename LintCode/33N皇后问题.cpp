#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//33.N皇后问题
//您的提交打败了 60.60% 的提交!
bool isValid(vector<int> &pos, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		//两个皇后不能在对角线上，不能在一列
		if (col == pos[i] || abs(row - i) == abs(col - pos[i]))
		{
			return false;
		}
	}
	return true;
}

void solveNQueensDFS(int n, vector<int> &pos, int row, vector<vector<string>> &res) 
{
	if (row == n) 
	{
		vector<string> out(n, string(n, '.'));
		for (int i = 0; i < n; ++i)
		{
			out[i][pos[i]] = 'Q';
		}
		res.push_back(out);
	}
	else 
	{
		for (int col = 0; col < n; ++col) 
		{
			if (isValid(pos, row, col)) 
			{
				pos[row] = col;
				solveNQueensDFS(n, pos, row + 1, res);
				pos[row] = -1;
			}
		}
	}
}

vector<vector<string>> solveNQueens(int n)
{
	// write your code here
	vector<vector<string> > res;
	vector<int> pos(n, -1);
	solveNQueensDFS(n, pos, 0, res);
	return res;
}


//34. N皇后问题 II
//您的提交打败了 98.00% 的提交!
int totalNQueens(int n) 
{
	// write your code here
	vector<vector<string> > res;
	vector<int> pos(n, -1);
	solveNQueensDFS(n, pos, 0, res);
	return res.size();
}
int main()
{
	int n = 4;
	vector<vector<string>> res = solveNQueens(n);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}