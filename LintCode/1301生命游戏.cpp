#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//1301. 生命游戏
//您的提交打败了 66.34% 的提交!
void Helper(vector<vector<int>>&board, vector<vector<bool>>&visited,int row, int col) {
	int count = 0;//统计周边8个位置上1的个数
	int rowSize = board.size();
	int colSize = board[0].size();
	for (int i = max(row - 1, 0); i <= min(row + 1, rowSize - 1); i++) {
		for (int j = max(col - 1, 0); j <= min(col + 1, colSize - 1); j++) {
			if (visited[i][j] == false && board[i][j] != 0) {
				count++;//这里是计算了9个位置，需要注意
			}
		}
	}
	//-1代表活细胞变成死细胞，2表示死细胞变成活细胞，1表示原本的活细胞，0表示原本的死细胞
	if (board[row][col] == 1) {
		count--;//因为多计算了自身位置，所以减掉
		if (count < 2 || count>3) {//变成死细胞
			board[row][col] = -1;
			//visited[row][col] = true;这一步要注释掉，因为这个原本的1是要用到的
		}
		else if (count == 2 || count == 3) {
			board[row][col] = 1;
			visited[row][col] = false;
		}
	}
	else {
		if (count == 3) {//变成活细胞
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
	//把矩阵变成0,1
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