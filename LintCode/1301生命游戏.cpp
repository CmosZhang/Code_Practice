#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//1301. ������Ϸ
//�����ύ����� 66.34% ���ύ!
void Helper(vector<vector<int>>&board, vector<vector<bool>>&visited,int row, int col) {
	int count = 0;//ͳ���ܱ�8��λ����1�ĸ���
	int rowSize = board.size();
	int colSize = board[0].size();
	for (int i = max(row - 1, 0); i <= min(row + 1, rowSize - 1); i++) {
		for (int j = max(col - 1, 0); j <= min(col + 1, colSize - 1); j++) {
			if (visited[i][j] == false && board[i][j] != 0) {
				count++;//�����Ǽ�����9��λ�ã���Ҫע��
			}
		}
	}
	//-1�����ϸ�������ϸ����2��ʾ��ϸ����ɻ�ϸ����1��ʾԭ���Ļ�ϸ����0��ʾԭ������ϸ��
	if (board[row][col] == 1) {
		count--;//��Ϊ�����������λ�ã����Լ���
		if (count < 2 || count>3) {//�����ϸ��
			board[row][col] = -1;
			//visited[row][col] = true;��һ��Ҫע�͵�����Ϊ���ԭ����1��Ҫ�õ���
		}
		else if (count == 2 || count == 3) {
			board[row][col] = 1;
			visited[row][col] = false;
		}
	}
	else {
		if (count == 3) {//��ɻ�ϸ��
			board[row][col] = 2;
			visited[row][col] = true;
		}
	}
}

void gameOfLife(vector<vector<int>> &board) {
	// Write your code here
	if (board.empty()) {
		return;
	}
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Helper(board, visited, i, j);
		}
	}
	//�Ѿ�����0,1
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == -1) {
				board[i][j] = 0;
			}
			if (board[i][j] == 2) {
				board[i][j] = 1;
			}
		}
	}
}

int main() {
	vector<vector<int>> board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
	gameOfLife(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}