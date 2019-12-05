#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>


using namespace std;

// 螺旋矩阵1
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
	// write your code here
	vector<int> order;
	if (matrix.size() == 0)
	{
		return order;
	}
	int startrow = 0;
	int startcol = 0;
	int endrow = matrix.size() - 1;
	int endcol = matrix[0].size() - 1;
	while (startrow <= endrow && startcol <= endcol)
	{
		for (int i = startcol; i <= endcol; i++)
		{
			order.push_back(matrix[startrow][i]);
		}
		for (int j = startrow + 1; j <= endrow; j++)
		{
			order.push_back(matrix[j][endcol]);
		}
		if (endrow != startrow)
		{
			for (int k = endcol - 1; k >= startcol; k--)
			{
				order.push_back(matrix[endrow][k]);
			}
		}
		if (endcol != startcol)
		{
			for (int n = endrow - 1; n > startrow; n--)
			{
				order.push_back(matrix[n][startcol]);
			}
		}
		startrow++;
		startcol++;
		endrow--;
		endcol--;
	}
	return order;
}


//螺旋矩阵2
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> matrix(n);
	for (int j = 0; j < matrix.size(); j++)
		matrix[j].resize(n);
	if (n <= 0)
	{
		return matrix;
	}
	int startrow = 0;
	int startcol = 0;
	int endrow = matrix.size() - 1;
	int endcol = matrix[0].size() - 1;
	int num = 1;
	while (startrow <= endrow && startcol <= endcol)
	{
		for (int i = startcol; i <= endcol; i++)
		{
			matrix[startrow][i] = num;
			num++;
		}
		for (int j = startrow + 1; j <= endrow; j++)
		{
			matrix[j][endcol] = num;
			num++;
		}
		if (endrow != startrow)
		{
			for (int k = endcol - 1; k >= startcol; k--)
			{
				matrix[endrow][k] = num;
				num++;
			}
		}
		if (endcol != startcol)
		{
			for (int n = endrow - 1; n > startrow; n--)
			{
				matrix[n][startcol] = num;
				num++;
			}
		}
		startrow++;
		startcol++;
		endrow--;
		endcol--;
	}
	return matrix;
}

int main()
{
	int i, j;
	//生成一个3行3列的矩阵
	vector<vector<int>> array(3);  
	for (i = 0; i < array.size(); i++)
		array[i].resize(3);
	for (i = 0; i < array.size(); i++)
	{
		for (j = 0; j < array[0].size(); j++)
		{
			array[i][j] = (i + 1) + j;
		}
	}
	cout << "输出矩阵 : " << endl;
	for (i = 0; i < array.size(); i++)
	{
		for (j = 0; j < array[0].size(); j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	vector<int> result;
	result = spiralOrder(array);
	for (int i = 0; i<result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	cout << endl;
	cout << "生成一个螺旋矩阵：" << endl;
	vector<vector<int>> res;
	res = generateMatrix(5);
	cout << "输出矩阵 : " << endl;
	for (i = 0; i < res.size(); i++)
	{
		for (j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 1;
}