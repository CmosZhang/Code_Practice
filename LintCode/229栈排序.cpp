#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//229. 栈排序
//64% 数据通过测试
//这种方式会导致堆栈溢出，出现问题主要是因为第42行出现问题。
//问题解决后，提交成功
//您的提交打败了 28.35% 的提交!
void stackSorting(stack<int>&stk)
{
	// write your code here
	if (stk.empty() || stk.size() == 1)
	{
		return;
	}
	stack<int> temp;
	while (!stk.empty())
	{
		temp.push(stk.top());
		stk.pop();
	}
	while (!temp.empty())
	{
		int max = temp.top();
		temp.pop();
		if (stk.empty())
		{
			stk.push(max);
		}
		else
		{
			if (max >= stk.top())
			{
				stk.push(max);
			}
			else
			{
				int count = 0;
				while (!stk.empty()&&max < stk.top())//这需要注意容易出问题，应该把判断是否为空放在前面，不能放在后面
				{
					temp.push(stk.top());
					stk.pop();
					count++;
				}
				stk.push(max);
				while (count > 0)
				{
					stk.push(temp.top());
					temp.pop();
					count--;
				}
			}
		}
	}
}


//网上优秀答案
void stackSorting(stack<int> &stk)
{
	if (stk.empty() || stk.size() == 1)
	{
		return;
	}
	stack<int> temp;
	int first = stk.top();
	temp.push(first);	
	stk.pop(); 
	while (!stk.empty()) 
	{  
		int top = stk.top();
		stk.pop();
		while (!temp.empty() && top > temp.top()) 
		{ 
			int tmp1 = temp.top();
			temp.pop();			
			stk.push(tmp1);
		}		
		temp.push(top); 
	} 	
	while (!temp.empty())
	{ 
		int tmp2 = temp.top();		
		temp.pop();		
		stk.push(tmp2);
	}
}

int main()
{
	vector<int> s = { 19,-10,-2,40,3,36,57,25,66,51,5,40,-8,43,9,-5,0,4,55,28,63,67,-2,35,57,0,0,30,17,55,22,34,-4,42,57,52,4,65,6,-2,8,12,31,43,26,34,31,19,-3,36,34,11,58,23,13,7,17,10,33,-5,10,53,14,56,18,8,-6,-2,37,7 };
	stack<int> temp;
	for (int i = 0; i < s.size(); i++)
	{
		temp.push(s[i]);
	}
	stackSorting(temp);
	while (!temp.empty())
	{
		cout << temp.top() << endl;
		temp.pop();
	}
	system("pause");
	return 0;
}