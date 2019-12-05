#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//class Interval
//{
//	int start, end;
//    Interval(int start, int end)
//    {
//		this->start = start;
//		this->end = end;
//    }
//};

struct Interval
{
	int start, end;
	//Interval(int start, int end)
	//{
	//	this->start = start;
	//	this->end = end;
	//}
};


//30. 插入区间
//暴力求解
//您的提交打败了 9.20% 的提交!
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
			else
			{
				ans.back().end = ans.back().end;
			}
		}
	}
	return ans;
}
/*
//插入的时候没有考虑顺序，结果导致还需要重新排序，比较耗时间。
//您的提交打败了 9.20% 的提交!
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	// write your code here
	vector<Interval> res;
	if (intervals.empty())
	{
		res.push_back(newInterval);
		return res;
	}
	//插入新的节点
	int len = intervals.size();
	res.push_back(newInterval);
	for (int k = 0; k < len; k++)
	{
		res.push_back(intervals[k]);
	}
	vector<Interval> ans = merge(res);
	return ans;
}
*/
//如果插入的时候就是有序的，在合并区间的时候就不需要排序。
//您的提交打败了 26.00% 的提交!
//这种方式可以将合并区间中的排序省掉。
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	// write your code here
	vector<Interval> res;
	if (intervals.empty())
	{
		res.push_back(newInterval);
		return res;
	}
	//插入新的节点
	int len = intervals.size();
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (intervals[i].start < newInterval.start)
		{
			res.push_back(intervals[i]);
		}
		else
		{
			j = i;
			break;
		}
	}
	res.push_back(newInterval);

	for (int k = j; k < len; k++)
	{
		res.push_back(intervals[k]);
	}
	vector<Interval> ans = merge(res);
	return ans;
}

int main()
{
	vector<Interval> num;
	Interval temp;
	for (int i = 0; i < 1; i++)
	{
		cin >> temp.start >> temp.end;
		num.push_back(temp);
	}
	Interval newInt;
	cin >> newInt.start >>newInt.end;
	vector<Interval> ans = insert(num,newInt);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].start << " " << ans[i].end << endl;
	}
	system("pause");
	return 0;
}