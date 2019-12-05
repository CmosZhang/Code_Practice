#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;


//40. ��ջʵ�ֶ���
//�����ύ����� 45.40% ���ύ!
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
	stack<int> datastack;//����ջ
	stack<int> st;//����ջ
};