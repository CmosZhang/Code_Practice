#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

//886. 凸多边形
//利用几何知识计算叉积来判断是否为凸边形
//在特定的输入条件下是正确的
//bool isConvex(vector<vector<int>> &point) {
//	// write your code here
//	if (point.empty() || point.size() < 3)
//	{
//		return false;
//	}
//	//sort(point.begin(), point.end());
//	int numPoints = point.size();
//
//	point.push_back(point[0]);
//	point.push_back(point[1]);
//	//int num = 0;
//	//for (int x = 0; x < row; x++)
//	//{
//	//	if ((point[x + 1][0] - point[x][0])*(point[x + 2][1] - point[x + 1][1]) - (point[x + 2][0] - point[x + 1][0])*(point[x + 1][1] - point[x][1]) > 0)
//	//	{
//	//		num++;
//	//	}
//	//	else if (abs((point[x + 1][0] - point[x][0])*(point[x + 2][1] - point[x + 1][1]) - (point[x + 2][0] - point[x + 1][0])*(point[x + 1][1] - point[x][1]))== 0)
//	//	{
//	//		num++;
//	//	}
//	//	else
//	//	{
//	//		return false;
//	//	}
//	//	if (num >= 3 && x == row - 1)
//	//	{
//	//		return true;
//	//	}
//	//}
//}

//您的提交打败了 100.00% 的提交!
int Cross_Product(vector<int>& p1, vector<int>& p2, vector<int>& p3)
{
	int ax = p2[0] - p1[0];
	int ay = p2[1] - p1[1];
	int bx = p3[0] - p2[0];
	int by = p3[1] - p2[1];
	int cp = ax * by - ay * bx;
	if (cp > 0) 
	{
		return 1;
	}
	else if (cp < 0) 
	{
		return -1;
	}
	else 
	{
		return 0;
	}
}

bool isConvex(vector<vector<int>> &point) {
	// write your code here
	if (point.empty() || point.size() < 3)
	{
		return false;
	}
	int numPoints = point.size();
	bool postiveFlag = false;
	bool negativeFlag = false;
	for (int i = 2; i < numPoints + 2; i++)
	{
		int ans = Cross_Product(point[(i - 2) % numPoints], point[(i - 1) % numPoints], point[i % numPoints]);
		if (ans == 1) 
		{
			postiveFlag = true;
		}
		else if (ans == -1) 
		{
			negativeFlag = true;
		}
	}
	//if (postiveFlag && negativeFlag || (!postiveFlag && !negativeFlag)) 
	//{
	//	return false;
	//}
	//else
	//{
	//	return true;
	//}
	//以上面判断是一个意思，用异或来表示
	if(postiveFlag^negativeFlag)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	vector<vector<int>> point = { {0, 0},{0,10},{ 10, 10 },{10, 0 },{5,5} };
	cout << isConvex(point) << endl;
	system("pause");
	return 0;
}