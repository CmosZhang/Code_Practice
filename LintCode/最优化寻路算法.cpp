#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point
{
	int start;
	int end;
	int time;
};

void Floyd(int **Adj, int **path, int **dis, int VexNum)
{
	int row = 0;
	int col = 0;
	for (row = 0; row < VexNum; row++)
	{
		for (col = 0; col < VexNum; col++)
		{
			//把矩阵D初始化为邻接矩阵的值
			dis[row][col] = Adj[row][col];
			//矩阵P的初值则为各个边的终点顶点的下标
			path[row][col] = col;
		}
	}

	//三重循环，用于计算每个点对的最短路径
	int temp = 0;
	int select = 0;
	for (temp = 0; temp < VexNum; temp++)
	{
		for (row = 0; row < VexNum; row++)
		{
			for (col = 0; col < VexNum; col++)
			{
				//为了防止溢出，所以需要引入一个select值
				select = (dis[row][temp] == INT_MAX || dis[temp][col] == INT_MAX) ? INT_MAX : (dis[row][temp] + dis[temp][col]);
				if (dis[row][col] > select)
				{
					//更新我们的D矩阵
					dis[row][col] = select;
					//更新我们的P矩阵
					path[row][col] = path[row][temp];
				}
			}
		}
	}
}

int main()
{
	int N, P, C;
	while (cin >> N >> P >> C) {
		vector<Point> matrix(P);
		for (int i = 0; i < P; i++)
		{
			cin >> matrix[i].start >> matrix[i].end >> matrix[i].time;
		}
		vector<int> refer(C);
		for (int i = 0; i < C; i++)
		{
			cin >> refer[i];
		}
		//构建邻接矩阵
		int **AdjMatrix;
		AdjMatrix = new int*[N];
		for (int i = 0; i < N; i++)
		{
			AdjMatrix[i] = new int[N];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				AdjMatrix[i][j] = INT_MAX;// 设置无穷大,这样在求解最短路径的时候有优势。
			}
		}
		for (int i = 0; i < P; i++)
		{
			int row = matrix[i].start;
			int col = matrix[i].end;
			AdjMatrix[row][col] = matrix[i].time;
			AdjMatrix[col][row] = matrix[i].time;
		}
		int **path; //记录最短路径
		path = new int*[N];
		for (int i = 0; i < N; i++)
		{
			path[i] = new int[N];
		}
		int **dis;//记录最短距离
		dis = new int*[N];
		for (int i = 0; i < N; i++)
		{
			dis[i] = new int[N];
		}
		//求最短路
		Floyd(AdjMatrix, path, dis, N);

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << dis[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		int res = 0;
		for (int i = 0; i < C; i++)
		{
			res += dis[0][refer[i]];
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}