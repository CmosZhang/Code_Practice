#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//123.��������
//�����ύ����� 100.00% ���ύ!
//����dfs��������
bool dfs(vector<vector<char>>&board, vector<vector<bool>>&visited, int index, string &word, int i, int j)
{
	if (index == word.size())
	{
		return true;
	}
	//�ж�Խ�����
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
	{
		return false;
	}
	//֮ǰ���ʹ�,�����ٱ�����
	if (visited[i][j])
	{
		return false;
	}
    //������������ַ��뵥����Ŀǰ��index���ַ���һ�£�Ҫ���ֿ�ʼ
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