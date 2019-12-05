#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


//949. 斐波那契数列 II
//您的提交打败了 68.42% 的提交!
//定义一个矩阵类
struct Matrix {
	long long mat[2][2];
	void zero() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				mat[i][j] = 0;
	}
	void unit() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				mat[i][j] = (i == j);
	}

	Matrix operator *(const Matrix&m)const
	{
		Matrix tmp;
		tmp.zero();
		for (int i = 0; i < 2; ++i)
		{
			for (int k = 0; k < 2; ++k)
			{
				if (mat[i][k] == 0)
					continue;
				for (int j = 0; j < 2; ++j)
				{
					tmp.mat[i][j] += mat[i][k] * m.mat[k][j];
					tmp.mat[i][j] %= 10000;
				}
			}
		}
		return tmp;
	}
}A, B;

Matrix MatrixPow(const Matrix &A, int a)
{
	B.unit();
	Matrix temp = A;
	for (; a; a >>= 1)
	{
		if (a & 1)
		{
			B = B * temp;
		}
	    temp = temp * temp;
	}
	return B;
}

string lastFourDigitsOfFn(int n) {
	// write your code here
	string res = "";
	if (n == 0)
	{
		return "0";
	}
	A.mat[0][0] = 1, A.mat[0][1] = 1;
	A.mat[1][0] = 1, A.mat[1][1] = 0;
	Matrix ans = MatrixPow(A, n - 1);
	int temp = ans.mat[0][0];
	if (temp == 0)
	{
		return "0";
	}
	for (int i = 0; i < 4; i++)
	{
		res = (char)('0' + temp % 10) + res;
		temp /= 10;
	}
	return res;
}


int main()
{
	int n = 30;
	cout << lastFourDigitsOfFn(n) << endl;
	system("pause");
	return 0;
}