#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct Point 
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};


//186.����ж��ٸ�����һ��ֱ����
//�����ύ����� 67.20% ���ύ!
int maxPoints(vector<Point> &points) 
{
	// write your code here
	if (points.empty())
	{
		return 0;
	}
	int res = 0;
	int len = points.size();
	if (len == 1)
	{
		return 1;
	}
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			Point a = points[i];
			Point b = points[j];

			//ͬһ��
			if (a.x == b.x&&a.y == b.y)
			{
				int cnt = 0;
				for (int k = 0; k < len; k++)
				{
					if (points[k].x == a.x&&points[k].y == a.y)
					{
						cnt++;
					}
				}
				res = max(res, cnt);
			}

			if (a.x == b.x && a.y != b.y)
			{//X��
				int cnt = 0;
				for (int k = 0; k < len; k++)
				{
					if (points[k].x == a.x)
					{
						cnt++;
					}
				}
				res = max(res, cnt);
			}

			if (a.x != b.x && a.y == b.y) 
			{//Y��
				int cnt = 0;
				for (int k = 0; k < len; k++)
				{
					if (points[k].y == a.y)
					{
						cnt++;
					}
				}
				res = max(res, cnt);
			}

			if (a.x != b.x && a.y != b.y) 
			{//��б��
				double l = (a.y - b.y) / (a.x - b.x);
				int cnt = 0;
				for (int k = 0; k < len; k++)
				{
					if (points[k].x == a.x && points[k].y == a.y) 
					{
						cnt++;
						continue;
					}

					if (points[k].x == b.x && points[k].y == b.y)
					{
						cnt++;
						continue;
					}

					if ((points[k].y - a.y) * (a.x - b.x) == (a.y - b.y) * (points[k].x - a.x))
					{
						cnt++;
						continue;
					}
				}
				res = max(res, cnt);
			}
		}
	}
	return res;
}