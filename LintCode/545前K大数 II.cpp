#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

//545. 前K大数 II
//您的提交打败了 74.20% 的提交!
class Solution
{
	public:
		/*
		* @param k: An integer
		*/
		int count;
		priority_queue<int> q;
		Solution(int k)
		{
			// do intialization if necessary
			count = k;
		}

		/*
		* @param num: Number to be added
		* @return: nothing
		*/
		void add(int num) 
		{
			// write your code here
			q.push(num);
		}

		/*
		* @return: Top k element
		*/
		vector<int> topk()
		{
			// write your code here
			vector<int>res;
			int len = q.size();
			if (len >= count)
			{
				int i = 0;
				while (i != count)
				{
					res.push_back(q.top());
					q.pop();
					i++;
				}
				for (int i = 0; i<res.size(); i++)
				{
					q.push(res[i]);
				}
			}
			else
			{
				while (!q.empty())
				{
					res.push_back(q.top());
					q.pop();
				}
				for (int i = 0; i<res.size(); i++)
				{
					q.push(res[i]);
				}
			}
			return res;
		}
};