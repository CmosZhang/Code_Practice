#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//389. �ж������Ƿ�Ϸ�
//�����ύ����� 79.40% ���ύ!
//������⡣
bool isValidSudoku(vector<vector<char>> &board) 
{
	// write your code here
	if (board.empty())
	{
		return false;
	}
	int row = board.size();
	int col = board[0].size();
	//�����϶���һ������
	//�����
	for (int i = 0; i < row; i++)
	{
		int temp[10] = { 0 };
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			else if (board[i][j] >'0'&&board[i][j] <= '9')
			{
				int index = board[i][j] - '0';
				temp[index]++;
				if (temp[index] > 1)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	//�����
	for (int i = 0; i < col; i++)
	{
		int temp2[10] = { 0 };
		for (int j = 0; j < row; j++)
		{
			if (board[j][i] == '.')
			{
				continue;
			}
			else if (board[j][i] >= '0'&&board[j][i] <= '9')
			{
				int index = board[j][i] - '0';
				temp2[index]++;
				if (temp2[index] > 1)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	//���ÿһ��3*3��С����
	for (int rowtemp = 0; rowtemp < row; rowtemp = rowtemp + 3)
	{
		for (int coltemp = 0; coltemp < col; coltemp = coltemp + 3)
		{
			int temp3[10] = { 0 };
			for (int i = rowtemp; i < rowtemp + 3; i++)
			{
				for (int j = coltemp; j < coltemp + 3; j++)
				{
					if (board[i][j] == '.')
					{
						continue;
					}
					else if (board[i][j] > '0'&&board[i][j] <= '9')
					{
						int index = board[i][j] - '0';
						temp3[index]++;
						if (temp3[index] > 1)
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}