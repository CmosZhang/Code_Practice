#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//12. ����Сֵ������ջ
//�����ύ����� 0.6% ���ύ!
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
		stack<int> dataStack; //����ջ
		stack<int> minStack;  //����ջ
};

//��ջʵ�ֶ���
//�����ύ����� 16.40% ���ύ!
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
	stack<int> dataStack; //����ջ
	stack<int> queueStack;  //����ջ
};

//ʵ��ջ
//���������ݽṹ��ʽ
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