#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

//1065. �ҵ��ճ̰��ű� I
//�����ύ����� 73.31% ���ύ!
class MyCalendar 
{
	private:
		vector<pair<int, int>> books;
	public:
		MyCalendar() 
		{
		}
		bool book(int start, int end) 
		{
			for(pair<int, int> p:books)
			{
				if (max(p.first, start) < min(end, p.second))
				{
					return false;
				}
			}
			books.push_back({ start,end });
			return true;
		}
};
