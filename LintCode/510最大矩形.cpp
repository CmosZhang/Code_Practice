#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//510. 最大矩形
//将这道题转换成122题直方图最大矩形覆盖然后直接利用122题的方法求解即可
//您的提交打败了 82.80% 的提交!
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.size() == 0)
		return 0;
	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;  //维护单调递增
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()]))
		{
			s.push(i);//如果当前高度大于栈顶，直接压入
		}
		else
		{
			while (!s.empty() && tmp[s.top()] > tmp[i]) //如果栈顶高度大于当前高度
			{
				int idx = s.top();
				s.pop();						//保存栈顶元素信息
				int width = s.empty() ? i : (i - s.top() - 1);//如果栈已经为空，宽度为i，否则i-s.top()-1
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important							//压入栈中
		}
	}
	return res;
}

int maximalRectangle(vector<vector<bool>> &matrix) 
{
	// write your code here
	if (matrix.empty()||matrix[0].empty())
	{
		return 0;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int maxArea = 0;
	vector<vector<int>> height(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (!matrix[i][j])
			{
				height[i][j] = 0;
			}
			else 
			{
				height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
			}
		}
	}

	for (int i = 0; i < row; i++) 
	{
		maxArea = max(maxArea, largestRectangleArea(height[i]));
	}
	return maxArea;
}

int main()
{
	vector<vector<bool>> num = { { 1, 1, 0, 0, 1 },{ 0,1,0,0,1 },{ 0,0,1,1,1 },{ 0,0,1,1,1},{ 0,0,0,0,1 } };
	int ans = maximalRectangle(num);
	cout << ans << endl;
	system("pause");
	return 0;
}