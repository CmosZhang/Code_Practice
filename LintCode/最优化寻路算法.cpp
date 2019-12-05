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
			//�Ѿ���D��ʼ��Ϊ�ڽӾ����ֵ
			dis[row][col] = Adj[row][col];
			//����P�ĳ�ֵ��Ϊ�����ߵ��յ㶥����±�
			path[row][col] = col;
		}
	}

	//����ѭ�������ڼ���ÿ����Ե����·��
	int temp = 0;
	int select = 0;
	for (temp = 0; temp < VexNum; temp++)
	{
		for (row = 0; row < VexNum; row++)
		{
			for (col = 0; col < VexNum; col++)
			{
				//Ϊ�˷�ֹ�����������Ҫ����һ��selectֵ
				select = (dis[row][temp] == INT_MAX || dis[temp][col] == INT_MAX) ? INT_MAX : (dis[row][temp] + dis[temp][col]);
				if (dis[row][col] > select)
				{
					//�������ǵ�D����
					dis[row][col] = select;
					//�������ǵ�P����
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
		//�����ڽӾ���
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
				AdjMatrix[i][j] = INT_MAX;// ���������,������������·����ʱ�������ơ�
			}
		}
		for (int i = 0; i < P; i++)
		{
			int row = matrix[i].start;
			int col = matrix[i].end;
			AdjMatrix[row][col] = matrix[i].time;
			AdjMatrix[col][row] = matrix[i].time;
		}
		int **path; //��¼���·��
		path = new int*[N];
		for (int i = 0; i < N; i++)
		{
			path[i] = new int[N];
		}
		int **dis;//��¼��̾���
		dis = new int*[N];
		for (int i = 0; i < N; i++)
		{
			dis[i] = new int[N];
		}
		//�����·
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