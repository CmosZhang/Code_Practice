#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

//1367. 警察距离
//利用BFS算法来查找最短距离
//您的提交打败了 83.74% 的提交!

bool isValid(int x, int y, int row, int col) {
	return (x >= 0 && y >= 0 && x < row && y < col);
}

void GetDistance(vector<vector<int>> &matrix, vector<vector<int>> &res, queue<pair<int, int>> &s) {
	int px, py;
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> dx{ 0, 0, 1, -1 }, dy{ -1, 1, 0, 0 };
	while (!s.empty()) {
		pair<int, int> pt = s.front(); 
		s.pop();
		for (int i = 0; i < 4; ++i) {
			px = pt.first + dx[i]; py = pt.second + dy[i];
			if (isValid(px, py, row, col) && !matrix[px][py] && !res[px][py]) {
				res[px][py] = res[pt.first][pt.second] + 1;
				s.push(make_pair(px, py));
			}
		}
	}
}


vector<vector<int>> policeDistance(vector<vector<int>> &matrix) {
	// Write your code here
	if (matrix.empty() || matrix[0].empty()) {
		return matrix;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> res(row, vector<int>(col, 0));
	queue<pair<int, int>> s;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == -1) {
				res[i][j] = -1;
			}
			else if (matrix[i][j] == 1) {
				s.push(make_pair(i, j));			
			}
		}
	}
	GetDistance(matrix, res, s);
	return res;
}

int main() {
	vector<vector<int>> mat = { {0,-1,-1},{0,-1,1},{0,0,0} };
	vector<vector<int>> res = policeDistance(mat);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}