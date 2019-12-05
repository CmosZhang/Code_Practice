#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

class MyStack 
{
	public:
		MyStack() 
		{
			// do intialization if necessary
		}

		/*
		* @param element: An integer
		* @return: nothing
		*/
		void push(int element)
		{
			// write your code here
			q1.push(element);
		}

		/*
		* @return: An integer
		*/
		int top()
		{
			// write your code here
			if (!q1.empty())
			{
				int len = q1.size();
				for (int i = 0; i < len - 1; i++)
				{
					q2.push(q1.front());
					q1.pop();
				}
				int temp = q1.front();
				q2.push(temp);
				q1.pop();
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
				return temp;
			}
		}

		/*
		* @return: True if the stack is empty
		*/
		bool isEmpty()
		{
			// write your code here
			if (q1.empty())
			{
				return true;
			}
			return false;
		}

		/*
		* @param element: An integer
		* @return: nothing
		*/
		void pop()
		{
			// write your code here
			if (!q1.empty())
			{
				int len = q1.size();
				for (int i = 0; i < len - 1; i++)
				{
					q2.push(q1.front());
					q1.pop();
				}
				int temp = q1.front();
				q1.pop();
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
			}
		}

		private:
			queue<int> q1; 
			queue<int> q2; //¸¨Öú¶ÓÁÐ
};