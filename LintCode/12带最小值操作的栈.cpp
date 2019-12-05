#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//12. 带最小值操作的栈
//您的提交打败了 0.6% 的提交!
class MinStack 
{
	public:
		MinStack() 
		{
			// do intialization if necessary
		}

		/*
		* @param number: An integer
		* @return: nothing
		*/
		void push(int number) 
		{
			// write your code here
			if (minStack.empty())
			{
				minStack.push(number);
			}
			else
			{
				int top = minStack.top();
				if (top < number)
				{
					minStack.push(top);
				}
				else
				{
					minStack.push(number);
				}
			}
			dataStack.push(number);
		}

		/*
		* @return: An integer
		*/
		int pop() 
		{
			// write your code here
			int temp;
			temp = dataStack.top();
			dataStack.pop();
			minStack.pop();
			return temp;
		}


		/*
		* @return: An integer
		*/
		int min()
		{
			// write your code here
			return minStack.top();
		}
    private:
		stack<int> dataStack; //数据栈
		stack<int> minStack;  //辅助栈
};

//用栈实现队列
//您的提交打败了 16.40% 的提交!
class MyQueue 
{
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
		dataStack.push(element);
	}

	/*
	* @return: An integer
	*/
	int pop() 
	{
		// write your code here
		if (queueStack.empty())
		{
			while (!dataStack.empty())
			{
				int top = dataStack.top;
				queueStack.push(top);
				dataStack.pop();
			}
		}
		int temp = queueStack.top();
		queueStack.pop();
		return temp;
	}

	/*
	* @return: An integer
	*/
	int top() 
	{
		// write your code here
		if (queueStack.empty())
		{
			while (!dataStack.empty())
			{
				int top = dataStack.top;
				queueStack.push(top);
				dataStack.pop();
			}
		}
		return queueStack.top();
	}
private:
	stack<int> dataStack; //数据栈
	stack<int> queueStack;  //辅助栈
};

//实现栈
//用其他数据结构方式
class Stack {
public:
	/*
	* @param x: An integer
	* @return: nothing
	*/
	vector<int>temp1;
	vector<int>temp2;
	void push(int x) 
	{
		// write your code here
	}

	/*
	* @return: nothing
	*/
	void pop() {
		// write your code here
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
	}

	/*
	* @return: True if the stack is empty
	*/
	bool isEmpty() {
		// write your code here
	}
};