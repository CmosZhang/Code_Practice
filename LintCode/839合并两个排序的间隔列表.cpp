#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

struct Interval
{
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};

//839. 合并两个排序的间隔列表
//您的提交打败了 60.60% 的提交!
void push(vector<Interval> &list, Interval &interval)
{
	if (interval.start <= list.back().end)
	{
		list.back().end = max(list.back().end, interval.end);
	}
	else
	{
		list.push_back(interval);
	}
}

vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
	// write your code here
	if (list1.empty())
	{
		return list2;
	}
	if (list2.empty())
	{
		return list1;
	}
	vector<Interval> res;
	int i = 0, j = 0;
	int len1 = list1.size(), len2 = list2.size();
	int startPoint = min(list1[0].start, list2[0].start);
	res.push_back(Interval(startPoint, startPoint));
	while (i < len1&&j < len2)
	{
		if (list1[i].start < list2[j].start)
		{
			push(res, list1[i]);
			i++;
		}
		else
		{
			push(res, list2[j]);
			j++;
		}
	}
	while (i < len1)
	{
		push(res, list1[i++]);
	}
	while (j < len2)
	{
		push(res, list2[j++]);
	}
	return res;
}