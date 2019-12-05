#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

//974. 01����
//����BFS�㷨����
//
queue<pair<int, int>> myQue;//������ȱ�����������
void helper(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &res)
{
	int rowSize = matrix.size();
	int colSize = matrix[0].size();
	vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!myQue.empty())
	{
		pair<int, int> cur = myQue.front();
		myQue.pop();
		for (int i = 0; i < 4; i++)
		{
			int newRow = cur.first + dirs[i][0], newCol = cur.second + dirs[i][1];
			if (newRow >= 0 && newRow < row&&newCol >= 0 && newCol < col)
			{
				if (res[newRow][newCol] > res[cur.first][cur.second] + 1)
				{
					res[newRow][newCol] = res[cur.first][cur.second] + 1;
					myQue.push({ newRow,newCol });
				}
			}
		}
	}
}

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
	// write your code here
	if (matrix.empty() || matrix[0].empty())
	{
		return matrix;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> res(row, vector<int>(col, INT_MAX));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				myQue.push({ i,j });
			    res[i][j] = 0;
			}
		}
	}
	helper(matrix, row, col, res);
	return res;
}

//���ϵ������
//�����ύ����� 100.00% ���ύ!
//vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
//{
//	int row = matrix.size();       
//	if (row == 0) 
//		return matrix; 
//	int col = matrix[0].size(); 
//	vector<vector<int>> res(row, vector<int>(col, numeric_limits<int>::max()));    
//	queue<pair<int, int>> q;      
//	for (int i = 0; i<row; i++)        
//		for (int j = 0; j<col; j++) 
//		{ 
//			if (matrix[i][j] == 0)
//			{
//				q.push({ i,j });
//				res[i][j] = 0;
//			}
//		} 
//	int sear[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };//���ñ����ķ�������    
//	while(!q.empty())       
//	{          
//		pair<int,int> cur=q.front(); 
//		q.pop();            
//		for(int i=0;i<4;i++)
//		{                
//			int newRow=cur.first+sear[i][0],newCol=cur.second+sear[i][1];  
//			if(newRow>=0&&newRow<row&&newCol>=0&&newCol<col)
//			{                    
//				if(res[newRow][newCol]>res[cur.first][cur.second]+1) 
//				{                        
//					res[newRow][newCol]=res[cur.first][cur.second]+1;   
//					q.push({newRow,newCol});        
//				}                
//			}         
//		}       
//	}      
//	return res;  
//}

//int main()
//{
//	vector<vector<int>> matrix = { { 0,1,0,1,1 },{ 1,1,0,0,1 },{ 0,0,0,1,0 },{ 1,0,1,1,1 },{ 1,0,0,0,1 } };
//	//vector<vector<int>> ans = updateMatrix(matrix);
//	//for (int i = 0; i < ans.size(); i++)
//	//{
//	//	for (int j = 0; j < ans[0].size(); j++)
//	//	{
//	//		cout << ans[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	system("pause");
//	return 0;
//}
