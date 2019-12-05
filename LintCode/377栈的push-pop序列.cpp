#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


//377. 栈的push-pop序列
//您的提交打败了 67.90% 的提交!
bool isLegalSeq(vector<int> &push, vector<int> &pop) 
{
	// write your code here
	if (push.empty() || pop.empty() || push.size() != pop.size())
	{
		return false;
	}
	int index = 0;
	stack<int>mystack;
	for (int i = 0; i<pop.size(); i++)
	{
		while (mystack.empty() || mystack.top() != pop[i])
		{
			if (index >= push.size())
				//如果需要压入的元素个数大于pushV的元素个数，说明popV不可能是pushV的弹出序列
				return false;
			mystack.push(push[index++]);
		}
		//当栈顶元素与popV当前元素相等时，将栈顶元素弹出，并移至popV下一个元素
		if (mystack.top() == pop[i])
			mystack.pop();
	}
	return true;
}