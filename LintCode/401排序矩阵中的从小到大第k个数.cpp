#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


void adjustMatrix(vector<vector<int> > &matrix)
{
	int row = 0, col = 0;
	while (row < matrix.size() - 1 && col < matrix[0].size() - 1)
	{
		if (matrix[row][col + 1] <= matrix[row + 1][col])
		{
			swap(matrix[row][col + 1], matrix[row][col]);
			col++;
		}
		else if (matrix[row][col + 1] >= matrix[row + 1][col])
		{
			swap(matrix[row + 1][col], matrix[row][col]);
			row++;
		}
	}
	while (row == matrix.size() - 1 && col < matrix[0].size() - 1)
	{
		if (matrix[row][col] >= matrix[row][col + 1]) {
			swap(matrix[row][col + 1], matrix[row][col]);
			col++;
		}
	}
	while (col == matrix[0].size() - 1 && row < matrix.size() - 1)
	{
		if (matrix[row][col] >= matrix[row + 1][col]) 
		{
			swap(matrix[row + 1][col], matrix[row][col]);
			row++;
		}
	}
}



int kthSmallest(vector<vector<int> > &matrix, int k) 
{
	// write your code here
	int sizeRow = matrix.size();
	if (sizeRow <= 0)
	{
		return 0;
	}
	int sizeCol = matrix[0].size();
	if (sizeCol <= 0) 
	{
		return 0;
	}
	int min = 0;
	for (int i = 0; i < k; i++) 
	{
		min = matrix[0][0];
		matrix[0][0] = INT_MAX;
		adjustMatrix(matrix);
	}
	return min;
}

int main()
{
	vector<vector<int>> num = { { 1, 5, 7 },{ 3,7,8 },{ 4, 8, 9 } };
	int min = kthSmallest(num,4);
	cout << min << endl;
	system("pause");
	return 0;
}