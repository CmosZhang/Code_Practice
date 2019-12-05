#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//161. ��תͼ��
//�����ύ����� 90.80% ���ύ!
//��ת�ã�Ȼ�󽻻���һ�к����һ�У��ڶ��к͵����ڶ��У��Դ�����
void rotate(vector<vector<int>> &matrix)
{
	// write your code here
	if (matrix.empty())
	{
		return;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col / 2; j++)
		{
			int temp2 = matrix[i][j];
			matrix[i][j] = matrix[i][col - 1 - j];
			//cout << matrix[i][col - 1 - j] << endl;
			//cout << matrix[i][j] << endl;
			matrix[i][col - 1 - j] = temp2;
		}
	}
}

int main()
{
	int row = 2, col = 2;
	vector<vector<int>> num = { {1,2},{3,4} };
	rotate(num);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <col; j++)
		{
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

