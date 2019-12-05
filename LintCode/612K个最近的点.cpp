#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct Distance {
	int dis;
	int num;
	int x;
	int y;
};

bool static comp(const Distance &a, const Distance &b)
{
	if (a.dis!= b.dis)
	{
		return a.dis < b.dis;
	}
	else
	{
		if (a.x != b.x)
		{
			return a.x < b.x;
		}
		else
		{
			return a.y < b.y;
		}
	}
}

int Edistance(const Point &a, const Point &b)
{
	int res = 0;
	res = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);//�����ƽ��
	return res;
}


//612. K������ĵ�
//������ⷽ��
//�����ύ����� 43.80% ���ύ!
//�����еľ��붼���������������Ȼ��ǰK����С�Ľ�����ݳ���.
vector<Point> kClosest2(vector<Point> &points, Point &origin, int k) {
	// write your code here
	if (points.empty())
	{
		return points;
	}
	int len = points.size();
	vector<Distance> dist(len);
	for (int i = 0; i < len; i++)
	{
		int temp = Edistance(points[i], origin);
		dist[i].dis = temp;
		dist[i].num = i;
		dist[i].x = points[i].x;
		dist[i].y = points[i].y;
	}
	sort(dist.begin(), dist.end(), comp);
	vector<Point> res(k);
	for (int i = 0; i < k; i++)
	{
		res[i] = points[dist[i].num];
	}
	return res;
}


//�������� ʹ�����ȼ����С���������
//�����ύ����� 81.40% ���ύ!
//�㷨�ĸ��Ӷ�ΪO(nlogk)

Point g_origin;

bool operator < (const Point &a, const Point &b) {
	int dist_a = Edistance(a, g_origin);
	int dist_b = Edistance(b, g_origin);
	if (dist_a == dist_b) 
	{
		if (a.x == b.x) 
			return a.y < b.y;
		return a.x < b.x;
	}
	return dist_a < dist_b;
}

class compare {
public:

	bool operator() (const Point &a, const Point &b) const {
		int dist_a = Edistance(a, g_origin);
		int dist_b = Edistance(b, g_origin);
		if (dist_a == dist_b) {
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		}
		return dist_a < dist_b;
	}
};


vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
	if (points.empty())
	{
		return points;
	}
	int len = points.size();
	g_origin = Point(origin);
	priority_queue<Point, vector<Point>, compare> pq;  //����
	for (int i = 0; i < len; ++i)
	{
		pq.push(points[i]);
		if (pq.size() > k) 
			pq.pop();
	}
	vector<Point> result;
	while (!pq.empty()) 
	{
		result.push_back(pq.top());
		pq.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}