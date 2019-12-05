#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Interval{
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

//919. 会议室 II
//67% 数据通过测试
//逻辑上还是存在问题
bool static comp(const Interval &a, const Interval &b)
{
	if (a.start != b.start)
	{
		return a.start < b.start;
	}
	else
	{
		return a.end < b.end;
	}
}
//
//int minMeetingRooms(vector<Interval> &intervals) {
//	// Write your code here
//	if (intervals.empty())
//	{
//		return 0;
//	}
//	sort(intervals.begin(), intervals.end(), comp);
//	int len = intervals.size();
//	int res = 1;
//	for (int i = 1; i < len; i++)
//	{
//		if (intervals[i].start < intervals[i - 1].end&&intervals[i].end > intervals[i - 1].end)
//		{
//			res++;
//		}
//		else if (intervals[i].start > intervals[i - 1].start&&intervals[i].end <= intervals[i - 1].end)
//		{
//			res++;
//		}
//		else
//		{
//			continue;
//		}
//	}
//	return res;
//}

//网上的优秀答案
//您的提交打败了 68.80% 的提交!
//利用最小堆的方法
int minMeetingRooms(vector<Interval> &intervals) {
	// Write your code here
	priority_queue<int, vector<int>, std::greater<int>> pq;
	sort(intervals.begin(), intervals.end(), comp);

	pq.push(intervals[0].end);
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i].start >= pq.top()) {
			pq.pop();
		}
		pq.push(intervals[i].end);
	}
	return pq.size();
}