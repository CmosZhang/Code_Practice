#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

struct Interval
{
	int start, end;
	//Interval(int start, int end)
	//{
	//	this->start = start;
	//	this->end = end;
	//}
};

//156. 合并区间
// 您的提交打败了 100.00% 的提交!
//先按照start排序
static bool cmp(const Interval &a, const Interval &b) 
{
	return a.start < b.start;
}
vector<Interval> merge(vector<Interval> &intervals) 
{
	// write your code here
	vector<Interval> ans;
	if (intervals.empty())
	{
		return ans;
	}
	int len = intervals.size();
	sort(intervals.begin(), intervals.end(), cmp);
	ans.push_back(intervals[0]);
	for (int i = 1; i < len; i++)
	{
		if (ans.back().end < intervals[i].start)
		{
			ans.push_back(intervals[i]);
		}
		else
		{
			if (ans.back().end < intervals[i].end)
			{
				ans.back().end = intervals[i].end;
			}
		}
	}
	return ans;
}