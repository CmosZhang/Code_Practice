//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//
//class Matrix {
//private:
//	int row;
//	int col;
//	int **mat;
//public:
//	Matrix(int N, int M);//构造函数
//	Matrix(const Matrix &mat);//拷贝构造函数
//	~Matrix();//析构函数
//	int getValue(int i, int j);//成员函数
//	int &getChangeValue(int i, int j);
//	int setValue(int i, int j, int a);
//};
//
//Matrix::Matrix(int N, int M) {
//	row = N;
//	col = M;
//	mat = new int*[row];
//	for (int i = 0; i < col; i++) {
//		mat[i] = new int[col];
//	}
//}
//
//
//Matrix::Matrix(const Matrix &T) {
//	row = T.row;
//	col = T.col;
//	mat = new int *[row];
//	for (int i = 0; i < row; i++) {
//		mat[i] = new int[col];
//		for (int j = 0; j < col; j++) {
//			mat[i][j] = T.mat[i][j];
//		}
//	}
//}
//
//Matrix::~Matrix() {
//	for (int i = 0; i < row; i++) {
//		delete[] mat[i];
//	}
//	delete[]mat;
//}
//
//int Matrix:: getValue(int i, int j)
//{
//	return mat[i][j];
//}
//
//int &Matrix::getChangeValue(int i, int j)
//{
//	int &a = mat[i][j];
//	return a;
//}
//
//int Matrix::setValue(int i, int j, int a)
//{
//	mat[i][j] = a;
//	return mat[i][j];
//}

#include<iostream>
#include<vector>

using namespace std;

class Matrix {
private:
	int row, col;
	vector<vector<int>> mat;
public:
	Matrix(int r, int c) :row(r), col(c) {}//构造函数
	Matrix(Matrix&T);//拷贝构造函数
	void InitialMatrix();
	int getValue(int i, int j);
	int setValue(int i, int j, int a);
	int getRow()const;
	int getCol()const;
	vector<vector<int>> getMat() const;
	//friend Matrix operator+(const Matrix &first, const Matrix &second);//需要友元函数来重载
	//friend Matrix operator-(const Matrix &first, const Matrix &second);
	friend Matrix operator+(const Matrix &first, const Matrix &second);
	friend Matrix operator-(const Matrix &first, const Matrix &second);
};

Matrix::Matrix(Matrix&T) {
	row = T.row;
	col = T.col;
	for (int i = 0; i < row; i++)
	{
		mat.push_back(T.mat[i]);
	}
}

void Matrix::InitialMatrix() {
	vector<int> temp;
	int num;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> num;
			temp.push_back(num);
		}
		mat.push_back(temp);
	}
	temp.clear();
}

int Matrix::getValue(int i, int j) {
	return mat[i][j];
}

int Matrix::setValue(int i, int j, int a) {
	mat[i][j] = a;
	return mat[i][j];
}

int Matrix::getRow()const{
	return row;
}

int Matrix::getCol()const{
	return col;
}


vector<vector<int>> Matrix::getMat() const {
	return mat;
}

//友元函数的重载运算符操作
//Matrix operator+(const Matrix&first, const Matrix&second) {
//	Matrix ans(first.getRow(), first.getCol());
//	vector<int> temp;
//	for (int i = 0; i < (int)first.mat.size(); i++){
//		for (int j = 0; j < (int)first.mat[i].size(); j++)
//			temp.push_back(first.mat[i][j] + second.mat[i][j]);
//		ans.mat.push_back(temp);
//		temp.clear();
//	}
//	return ans;
//}

//Matrix operator-(const Matrix&first, const Matrix&second) {
//	Matrix ans(first.getRow(), first.getCol());
//	vector<int>temp;
//	for (int i = 0; i < (int)first.mat.size(); i++){
//		for (int j = 0; j < (int)first.mat[i].size(); j++)
//			temp.push_back(first.mat[i][j] - second.mat[i][j]);
//		ans.mat.push_back(temp);
//		temp.clear();
//	}
//	return ans;
//}

//不需要友元函数的操作符操作
Matrix operator+(const Matrix&first, const Matrix&second) {
	Matrix ans(first.getRow(), first.getCol());
	vector<int>temp;
	vector<vector<int>> num1 = first.getMat();
	vector<vector<int>> num2 = second.getMat();
	for (int i = 0; i < num1.size(); i++){
		for (int j = 0; j < num1[i].size(); j++)
			temp.push_back(num1[i][j] + num2[i][j]);
		ans.getMat().push_back(temp);
		temp.clear();
	}
	return ans;
}

Matrix operator-(const Matrix&first, const Matrix&second) {
	Matrix ans(first.getRow(), first.getCol());
	vector<int>temp;
	vector<vector<int>> num1 = first.getMat();
	vector<vector<int>> num2 = second.getMat();
	for (int i = 0; i < num1.size(); i++) {
		for (int j = 0; j < num1[i].size(); j++)
			temp.push_back(num1[i][j] - num2[i][j]);
		ans.getMat().push_back(temp);
		temp.clear();
	}
	return ans;
}      