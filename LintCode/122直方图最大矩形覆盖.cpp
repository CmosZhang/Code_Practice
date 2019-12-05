#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


//122. 直方图最大矩形覆盖
//Time Limit Exceeded
//最原始的方法遍历
//68% 数据通过测试
/*
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.empty())
	{
		return 0;
	}
	if (height.size() == 1) 
	{
		return height[0];
	}

	int len = height.size();
	
	int maxArea = INT_MIN;

	for (int i = 0; i < len; i++)
	{
		int left = i;
		int right = i;
		while (left - 1 >= 0 && height[left - 1] >= height[i])
		{
			left--;
		}
		while (right + 1 <= len - 1 && height[right + 1] >= height[i])
		{
			right++;
		}
		maxArea = max(maxArea, (right - left + 1) * height[i]);
	}
	return maxArea;
}
*/

//您的提交打败了 98.80% 的提交!
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.size() == 0) 
		return 0;
	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;    		//维护单调递增
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) 
			s.push(i);		//如果当前高度大于栈顶，直接压入
		else 
		{
			while (!s.empty() && tmp[s.top()] > tmp[i]) 			//如果栈顶高度大于当前高度
			{
				int idx = s.top();
				s.pop();						//保存栈顶元素信息
				int width = s.empty() ? i : (i - s.top() - 1);		//如果栈已经为空，宽度为i，否则i-s.top()-1
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important							//压入栈中
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {2,1,5,6,2,3 };
	int res = largestRectangleArea(nums);
	cout << res << endl;
	system("pause");
	return 0;
}