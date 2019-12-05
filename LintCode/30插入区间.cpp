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


//30. ��������
//�������
//�����ύ����� 9.20% ���ύ!
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
//�����ʱ��û�п���˳�򣬽�����»���Ҫ�������򣬱ȽϺ�ʱ�䡣
//�����ύ����� 9.20% ���ύ!
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	// write your code here
	vector<Interval> res;
	if (intervals.empty())
	{
		res.push_back(newInterval);
		return res;
	}
	//�����µĽڵ�
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
//��������ʱ���������ģ��ںϲ������ʱ��Ͳ���Ҫ����
//�����ύ����� 26.00% ���ύ!
//���ַ�ʽ���Խ��ϲ������е�����ʡ����
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	// write your code here
	vector<Interval> res;
	if (intervals.empty())
	{
		res.push_back(newInterval);
		return res;
	}
	//�����µĽڵ�
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