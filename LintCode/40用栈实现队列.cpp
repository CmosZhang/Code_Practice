#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;


//40. 用栈实现队列
//您的提交打败了 45.40% 的提交!
class MyQueue {
public:
	MyQueue() {
		// do intialization if necessary
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element)
	{
		// write your code here
		datastack.push(element);
	}

	/*
	* @return: An integer
	*/
	int pop()
	{
		// write your code here
		if (st.empty())
		{
			while (!datastack.empty())
			{
				int temp = datastack.top();
				datastack.pop();
				st.push(temp);
			}
		}
		int res = st.top();
		st.pop();
		return res;
	}

	/*
	* @return: An integer
	*/
	int top()
	{
		// write your code here
		if (st.empty())
		{
			while (!datastack.empty())
			{
				int temp = datastack.top();
				datastack.pop();
				st.push(temp);
			}
		}
		int res = st.top();
		return res;
	}
private:
	stack<int> datastack;//数据栈
	stack<int> st;//辅助栈
};